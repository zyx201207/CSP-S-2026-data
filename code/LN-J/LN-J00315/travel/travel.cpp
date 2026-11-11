#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,s2;
int c1,c2;
cin>>c1>>s1>>c2>>s2;
int s3=0,s4=0;
for(int i=0;i<=1;i++){
    s3=s3*10+s1[i]-'0',s4=s4*10+s2[i]-'0';
}
char g,h;
g=s1[2],h=s2[2];
if(c1!=c2)cout<<"0000";
else if(s3!=s4)cout<<"1000";
else if((g/('C'+0.5)-1)/(h/('C'+0.5)-1)<0)cout<<"1100";
else if((min(g,h)+1)!=max(h,g))cout<<"1110";
else cout<<"1111";
return 0;
}
