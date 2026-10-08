#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int ans=0;
    int left,right,mid;
    left=0;right=205;
    while(left<=right){
        mid=(left+right)/2;
        bool if_ok=true;
        for(int i=0;i<strs.size();i++){
            if(mid>strs[i].length()){
                if_ok=false;
                break;
            }
            for(int u=0;u<mid;u++){
                if(strs[i][u]!=strs[0][u]){
                    if_ok=false;
                    break;
                }
            }
            if(if_ok==false) break;
        }
        if(if_ok==true){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    string answer;
    for(int i=0;i<ans;i++){
        answer.push_back(strs[0][i]);
    }
    return answer;
    }
};