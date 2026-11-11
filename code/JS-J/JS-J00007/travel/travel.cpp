#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1])cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    int cnt0=0,cnt1=0;
    if(s1[2]>='A'&&s1[2]<='C')cnt0++;
    if(s2[2]>='A'&&s2[2]<='C')cnt0++;
    if(s1[2]=='D'||s1[2]=='F')cnt1++;
    if(s2[2]=='D'||s2[2]=='F')cnt1++;
    if(cnt0==2||cnt1==2)cout<<1;
    else cout<<0;
    if((cnt0==2||cnt1==2)&&((int)abs(s1[2]-s2[2])==1))cout<<1;
    else cout<<0;
    return 0;
}
