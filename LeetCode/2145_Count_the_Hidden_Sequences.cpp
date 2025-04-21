class Solution {
public:
    int numberOfArrays(vector<int>& diffs, int lower, int upper) {
        long prefSum = 0, maxVal = 0, minVal = 0;
        for(auto &diff : diffs) {
            prefSum += diff;
            maxVal = max(maxVal, prefSum);
            minVal = min(minVal, prefSum);
        }
        int res = (upper - lower) - (maxVal - minVal) + 1;
        return max(0,res);
    }
};

/*

differences = [3,-4,5,1,-2], lower = -4, upper = 5

if lower == 0:
first possible answer: [0,3,-1,4,5,3]

-> With this we get initial value of minVal and maxVal

---------------------------

differences = [1,-3,4], lower = 1, upper = 6

[1,-2,2];

minVal >= lower

maxVal <= upper

(upper-maxVal) + (lower-minVal) + 1

---------------------------

Visualization:

____________ -> Upper

------------ -> maxVal



------------ -> minVal


____________ -> lower

-
-> Here the window of answer will be from  minVal to maxVal
-> This window can shift between values [lower,upper]
-> So answer will be: (upper - maxVal) + (minVal - lower) + 1;
-> Or alternatively: (upper - lower) - (maxVal - minVal) + 1;


*/
