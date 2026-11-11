#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int t=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)cout<<1;
    else {cout<<"0000";return 0;}
    for(int i=0;i<=1;i++){
        if(s2[i]!=s4[i])
            t=0;
    }
    if(t==1)cout<<1;
    else {cout<<"000";return 0;}
    if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D'))
        cout<<1;
    else {cout<<"00";return 0;}
    if(s2[2]-s4[2]==1||s4[2]-s2[2]==1)
        cout<<1;
    else cout<<0;
    return 0;
}
