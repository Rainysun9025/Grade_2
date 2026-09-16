#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    int ans=0;
    set<int> st;
    vector<vector<int> > vec;
    vec.resize(height.size(),vector<int>(2,0));
    for(int i=0;i<height.size();i++){
        vec[i][0]=height[i];
        vec[i][1]=i;
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<height.size();i++){
        st.insert(i);
    }
    for(int i=0;i<height.size();i++){
        int cur_num=vec[i][1];
        int cur_height=vec[i][0];
        int left=*st.begin();
        int right=*st.rbegin();
        int width=max(cur_num-left,right-cur_num);
        ans=max(ans,width*cur_height);
        st.erase(cur_num);
    }
    return ans;
    }
};