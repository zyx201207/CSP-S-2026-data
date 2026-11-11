#include <bits/stdc++.h>
using namespace std;
int a,b,r,x;
string c1,c2,s1,s2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool flag=1;
    if(c1==c2) ans+="1";
    else{
        ans="0000";
        flag=0;
    }
    if(flag){
        for(int i=0;i<=1;i++){
            a=a*10+s1[i]-'0';
            b=b*10+s2[i]-'0';
        }
        r=s1[2]-'A';x=s2[2]-'A';
        if(a==b)ans+="1";
        else{
             ans+="000";
        }
        if((r<3&&x<3)||(r>=3&&x>=3))ans+="1";
        else{
            ans+="00";
        }
        if(r+1==x||x+1==r) ans+="1";
        else ans+="0";
    }
    for(int i=0;i<4;i++){
        cout<<ans[i];
    }
    return 0;
}
