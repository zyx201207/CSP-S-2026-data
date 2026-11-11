#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    string ans="";
    if(c1==c2){
        ans+='1';
        string tmp1=s1.substr(0,2),tmp2=s2.substr(0,2);
        if(tmp1==tmp2){
            ans+='1';
            char pos1=s1[2],pos2=s2[2];
            if(pos1>='A'&&pos1<='C'&&pos2>='A'&&pos2<='C'){
                ans+='1';
                if(pos1==pos2+1||pos2==pos1+1) ans+='1';
                else ans+='0';
            }else if((pos1=='D'||pos1=='F')&&(pos2=='D'||pos2=='F')){
                ans+="11";
            }else ans+="00";
        }else ans+="000";
    }else ans="0000";
    cout<<ans;
    return 0;
}
