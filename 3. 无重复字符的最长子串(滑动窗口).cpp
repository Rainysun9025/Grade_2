#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        unordered_set<char> mp;
        int ans=0;
        while(r<s.length()){
            if(mp.find(s[r])!=mp.end()){
                //重复了
                while(s[l]!=s[r]){
                    mp.erase(s[l]);//清除左边即将要收缩的字符
                    l++;
                }
                //找到了重复的字符，l++
                mp.erase(s[l]);
                l++;
            }
            else{
                //没重复
                mp.insert(s[r]);
                ans=max(ans,r-l+1);
                r++;
            }
        }
        return ans;
    }
};