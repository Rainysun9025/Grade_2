#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        string answer;
        answer.push_back(s[0]);
        int l,r,mid;
        l=1;
        r=s.length();
        while(l<=r){
            mid=(l+r)/2;
            bool if_ok=false;
            for(int i=0;i+mid-1<s.length();i++){
                unordered_map<char,bool> p;
                bool if_chongfu=false;
                for(int u=i;u<=i+mid-1;u++){
                    if(p.find(s[u])!=p.end()){
                        if_chongfu=true;
                        break;
                    }//重复
                    else{
                        p[s[u]]=true;
                    }//不重复
                }
                if(if_chongfu==false){
                    answer.clear();
                    for(int u=i;u<=i+mid-1;u++){
                        answer.push_back(s[u]);
                    }
                    if_ok=true;
                    break;
                }
            }
            if(if_ok==true){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return answer.length();
    }
};