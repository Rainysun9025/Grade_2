#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> solve;
        for(int i=0;i<nums.size();i++){
            int temp=target-nums[i];
            if(solve.find(temp)!=solve.end())
            {
                return {i,solve[temp]};
            }
            else solve[nums[i]]=i;
        }
        return {};
    }
};