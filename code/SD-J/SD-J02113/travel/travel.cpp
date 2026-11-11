#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string s1,s2,s3,s4;
cin>>s1>>s2>>s3>>s4;
if(s1==s3)cout<<1;
else cout<<0;
long long t1=(s2[0]-'0')*10+(s2[1]-'0'),t2=(s4[0]-'0')*10+(s4[1]-'0');
if(s1==s3&&t1==t2)cout<<1;
else cout<<0;
if(s1==s3&&t1==t2&&(s2[2]<='C'&&s4[2]<='C'||s2[2]>'C'&&s2[2]<='F'&&s4[2]>'C'&&s4[2]<='F'))cout<<1;
else cout<<0;
bool b=0;
if(s1==s3&&t1==t2&&(s2[2]<='C'&&s4[2]<='C'||s2[2]>'C'&&s2[2]<='F'&&s4[2]>'C'&&s4[2]<='F')){
if(s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A'||s2[2]=='B'&&s4[2]=='C'||s2[2]=='C'&&s4[2]=='B'||s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'){
b=1;
}
}
if(b==1)cout<<1;
else cout<<0;
return 0;
}
