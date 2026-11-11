#include <bits/stdc++.h>
using namespace std;


int main(){
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string ans="";
    if(c1==c2){
        ans=ans+"1";
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            ans=ans+"1";
            if(s1[2]<'D' && s2[2]<'D' || s1[2]>'C' && s2[2]>'C'){
                ans=ans+"1";
                if(abs(s1[2]-s2[2])==1){
                    ans=ans+"1";
                }
                else{
                    ans=ans+"0";
                }
            }
            else{
                ans=ans+"00";
            }
        }
        else{
            ans=ans+"000";
        }
    }
    else{
        ans="0000";
    }
    cout<<ans<<endl;
    return 0;
}
