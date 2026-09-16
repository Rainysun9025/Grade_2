#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        nums3.resize(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums3.begin());
        if(nums3.size()%2==0){
            int fir,sec;
            fir=nums3.size()/2-1;
            sec=fir+1;
            double ans=(nums3[fir]+nums3[sec])/2.0;
            return ans;
        }
        else{
            double ans=nums3[(nums3.size()+1)/2-1];
            return ans;
        }
    }
};