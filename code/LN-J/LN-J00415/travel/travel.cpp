#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a,b,c,d;
    if(c1==c2) a=1;
    else a=0;
    if(a==1&&s1[0]==s2[0]&&s1[1]==s2[1]) b=1;
    else b=0;
    int e,f;
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') e=1;
    else e=0;
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') f=1;
    else f=0;
    if(b==1&&e==f) c=1;
    else c=0;
    if(c==1&&e==0) d=1;
    else if(c==1&&e==1&&abs(int(s1[2])-int(s2[2]))==1) d=1;
    else d=0;
    string s="";
    s+=char(a+'0');
    s+=char(b+'0');
    s+=char(c+'0');
    s+=char(d+'0');
    cout<<s;
    return 0;
}
