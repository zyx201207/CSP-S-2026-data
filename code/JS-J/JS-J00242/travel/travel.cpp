#include<bits/stdc++.h>
using namespace std;
bool c(string s){
    if(s[2]=='D'||s[2]=='F'){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans;
    if(c1==c2){
        ans+='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            ans+='1';
            if(c(s1)==c(s2)){
                ans+='1';
                if(c(s1)){
                    ans+='1';
                }
                else{
                    if(max(s1[2],s2[2])-min(s1[2],s2[2])==1){
                        ans+='1';
                    }
                    else{
                        ans="1110";
                    }
                }
            }
            else{
                ans="1100";
            }
        }
        else{
            ans="1000";
        }
    }
    else{
        ans="0000";
    }
    cout<<ans;
    return 0;
}
