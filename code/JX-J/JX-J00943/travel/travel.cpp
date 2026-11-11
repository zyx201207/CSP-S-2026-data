#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2;
    cin>>b1>>b2;
    if(a1==b1) cout<<1;
    else cout<<0;
    if(a1==b1&&a2.substr(0,2)==b2.substr(0,2)) cout<<1;
    else cout<<0;
    if(a1==b1&&a2.substr(0,2)==b2.substr(0,2)&&((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')||(a2[2]=='A'&&(b2[2]=='B'||b2[2]=='C'))||(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C'))||(a2[2]=='C'&&(b2[2]=='B'||b2[2]=='A')))) cout<<1;
    else cout<<0;
    if(a1==b1&&a2.substr(0,2)==b2.substr(0,2)&&((a2[2]=='D'&&b2[2]=='F')||(a2[2]=='F'&&b2[2]=='D')||(a2[2]=='A'&&b2[2]=='B')||(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C'))||(a2[2]=='C'&&b2[2]=='B'))) cout<<1;
    else cout<<0;
    return 0;
}