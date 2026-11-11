#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){cout<<1;}
    else{cout<<"0000";return 0;}
    char ss1[3]={s1[0],s1[1],s1[2]},ss2[3]={s2[0],s2[1],s2[2]};
    if(ss1[0]==ss2[0] && ss1[1]==ss2[1]){cout<<1;}
    else{cout<<"000";return 0;}
    int a=s1[2]+s2[2],ax=max(s1[2],s2[2]),in=min(s1[2],s2[2]);
    if(ax<'D' || in>'C'){cout<<1;}
    else{cout<<"00";return 0;}
    if(ax-in==1){cout<<1;}
    else{cout<<0;}
    return 0;
}
