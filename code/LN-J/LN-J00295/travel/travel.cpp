#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    char zuo1,zuo2;
    int pai1,pai2;
    pai1=10*s1[0]+s1[1]-528;
    pai2=10*s2[0]+s2[1]-528;
    zuo1=s1[2];
    zuo2=s2[2];
    if(c1==c2) cout<<1;
    else cout<<0;
    if(c1==c2&&pai1==pai2) cout<<1;
    else cout<<0;
    int f3=1;
    if(zuo1<='C'){
        if(zuo2<='C') f3=1;
        else f3=0;
    }
    else if(zuo1>'C'){
        if(zuo2>'C') f3=1;
        else f3=0;
    }
    if(c1==c2&&pai1==pai2&&f3==1) cout<<1;
    else cout<<0;
    if(c1==c2&&pai1==pai2&&f3==1&&max(zuo1,zuo2)-min(zuo1,zuo2)==1) cout<<1;
    else cout<<0;
    return 0;
}
