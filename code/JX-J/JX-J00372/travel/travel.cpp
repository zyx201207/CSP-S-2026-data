#include<bits/stdc++.h>
using namespace std;
int c1,c2,a,b,c,d;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) a=1;
    if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1]) b=1;
    if(a==1&&s1[2]=='A'&&b==1) if(s2[2]=='B'||s2[2]=='C') c=1;
    if(a==1&&s1[2]=='B'&&b==1) if(s2[2]=='A'||s2[2]=='C') c=1;
    if(a==1&&s1[2]=='C'&&b==1) if(s2[2]=='B'||s2[2]=='A') c=1;
    if(c==1){
        if(s1[2]=='A'&&s2[2]=='B') d=1;
        if(s1[2]=='B'&&s2[2]=='A') d=1;
        if(s1[2]=='B'&&s2[2]=='C') d=1;
        if(s1[2]=='C'&&s2[2]=='B') d=1;
        if(s1[2]=='D'&&s2[2]=='F') d=1;
        if(s1[2]=='F'&&s2[2]=='D') d=1;
    }cout<<a<<b<<c<<d;
    return 0;
}
