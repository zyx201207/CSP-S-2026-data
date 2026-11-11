#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,ans;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>s1>>s2>>s3>>s4;
if(s1==s3){
ans+='1';
}else{
cout<<"0000";
return 0;
}
if(s2[0]==s4[0]&&s2[1]==s4[1]){
    ans+='1';
}else{
cout<<"1000";
return 0;
}
char s5=max(s2[2],s4[2]),s6=min(s2[2],s4[2]);
if((s5=='B'&&s6=='A')||(s5=='C'&&s6=='A')||(s5=='C'&&s6=='B')||(s5=='F'&&s6=='D')){
    ans+='1';
}else{
cout<<"1100";
return 0;
}
if((s5=='B'&&s6=='A')||(s5=='C'&&s6=='B')||(s5=='F'&&s6=='D')){
    ans+='1';
}else{
cout<<"1110";
return 0;
}
cout<<ans;
return 0;
}
