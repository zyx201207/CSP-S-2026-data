#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1,c2;
string s1,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2)a=1;
if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==1)b=1;
if(b==1){
        if(s1[2]>s2[2]&&s1[2]=='D')c=0;
        else if(s1[2]<s2[2]&&s2[2]=='D')c=0;
        else c=1;
}
if(a==1&&b==1&&c==1&&abs(s1[2]-s2[2])==1)d=1;
cout<<a<<b<<c<<d;
return 0;
}
