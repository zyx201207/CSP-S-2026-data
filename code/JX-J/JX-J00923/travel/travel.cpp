/*
 shangqingyun code has no bug
 pts RP++
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
int vis1,vis2,vis3,vis4;
bool f(string s1,string s2){
    int cnt1,cnt2;
    if(s1[2]=='d'||s1[2]=='f')cnt1=1;
    else cnt1=2;
    if(s2[2]=='d'||s2[2]=='f')cnt2=1;
    else cnt2=2;
    return cnt1==cnt2;
}
bool f2(string s1,string s2){
    int cnt1,cnt2;
    if(s1[2]=='A')cnt1=1;
    if(s1[2]=='B')cnt1=2;
    if(s1[2]=='C')cnt1=3;
    if(s1[2]=='D')cnt1=4;
    if(s1[2]=='F')cnt1=5;

    if(s2[2]=='A')cnt2=1;
    if(s2[2]=='B')cnt2=2;
    if(s2[2]=='C')cnt2=3;
    if(s2[2]=='D')cnt2=4;
    if(s2[2]=='F')cnt2=5;

    if(abs(cnt1-cnt2)==1)return true;
    return false;
}
signed main(){
    freopen("travel.in"."r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)vis1=1;
    else vis1=0;
    if(vis1&&b[0]==d[0]&&b[1]==d[1])vis2=1;
    if(vis2&&f(b,d))vis3=1;
    if(vis3&&f2(b,d))vis4=1;
    cout<<vis1<<vis2<<vis3<<vis4;
    return 0;
}
