/*
The class `Solution` implements a knapsack algorithm using dynamic programming to find the maximum
value that can be obtained within a given weight limit. 

Problem link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

*/



/*
-> Remember the concept of choice diagram, it helps in writing the recursive function.

Item -> (wt[Item] <= W) ? (YES/NO) : (NO)

This will be the choice diagram for the problem.


-> Base condition: Try to think about the smallest possible valid input.
If n == 0 or W == 0, return 0.

-> Now when these things are clear try to write recursive function.
Format:
1. Base case
2. Choice diagram

-> Now sudo code for the problem will be:
Base Case
1. If n == 0 or W == 0, return 0. 
Choice Diagram
2. If wt[n-1] <= W, return max(helper(W,n-1,val,wt),val[n-1] + helper(W-wt[n-1],n-1,val,wt));
3. Else return helper(W,n-1,val,wt);

-------------------------------------------------------------------------------------------------

Now the recursive funtion is ready and we need it to memoize it since there are overlapping subproblems.

-> To memoize it we need to identify the changing parameters in the recursive function which will give us the dimesions of the dp array.
Here we have 2 changing parameters W and n.
-> So we will create a 2D dp array of size (n+1) x (W+1) and initialize it with -1, and we will fill the state as we find solution to the subproblem and we
will reuse it when we encounter the same subproblem again.


*/



class Solution {
  public:
    #define SIZE 1001
    
    int dp[SIZE][SIZE];
    
    int helper(int w, int n, vector<int> &val, vector<int> &wt) {
        if(n==0 || w==0) return 0; //Base Condition
        
        if(dp[n][w] != -1) return dp[n][w]; // Memoized return
        

        // Memoized choice diagram
        if(wt[n-1] <= w) {
            return dp[n][w] = max(helper(w,n-1,val,wt),val[n-1] + helper(w-wt[n-1],n-1,val,wt));
        }
        
        return dp[n][w] = helper(w,n-1,val,wt);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
    
        // std::memset(dp,-1,sizeof(dp));

        /* 
        -> memset can be used but it is not safe to use it, but for value such as 0 or -1 we can use memset 
        -> We can use std::fill instead of std::memset to fill the array with a specific value. It is safer and more readable.
        -> std::fill(starting itr, ending itr, value)
        -> for 2D array we can use &dp[0][0] to get the starting address of the array while using std::fill  
        */
        
        std::fill(&dp[0][0], &dp[0][0] + SIZE * SIZE, -1);

        return helper(W,n,val,wt);
    }
};
