#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,s1,c2,s2;
cin>>c1>>s1>>c2>>s2;
string a;
if(c1==c2)a+='1';
else a+='0';
if(s1[0]==s2[0]&&s1[1]==s2[1])a+='1';
else a+='0';
if((s1[2]-'A'<=2&&s2[2]-'A'>=3)||(s1[2]-'A'>=3&&s2[2]-'A'<=2))a+='0';
else a+='1';
if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)a+='1';
cout<<a;
return 0;}
