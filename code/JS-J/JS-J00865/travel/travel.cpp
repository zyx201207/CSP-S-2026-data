#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        if(s1.substr(0,2)==s2.substr(0,2)){
            if((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C')){
                ans="1100";
            }else{
                if(s1[2]-s2[2]==1||s2[2]-s1[2]==1||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
                    ans="1111";
                }else{
                    ans="1110";
                }
            }
        }else{
            ans="1000";
        }
    }else{
        ans="0000";
    }
    cout<<ans<<endl;
    return 0;
}
