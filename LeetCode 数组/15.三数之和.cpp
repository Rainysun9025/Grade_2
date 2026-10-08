#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int >> answer;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            unordered_set<int> temp;
            for(int u=i+1;u<nums.size();u++){
                int target=-nums[i]-nums[u];
                if(temp.find(target)!=temp.end()){
                    vector<int> kk={nums[i],nums[u],target};
                    sort(kk.begin(),kk.end());
                    answer.insert(kk);
                }
                temp.insert(nums[u]);
            }

        }
        return vector<vector<int>>(answer.begin(), answer.end());
    }
};