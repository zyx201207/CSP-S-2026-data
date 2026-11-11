#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int c1,s1,c2,s2;
char ss1,ss2;
cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
if(c1==c2){
cout<<"1";
if(s1==s2){cout<<"1";
if('A'<=ss1&&ss1<='C'&&'A'<=ss2&&ss2<='C'){cout<<"1";
if(ss1-ss2==1||ss1-ss2==-1)cout<<"1";
else cout<<"0";
}
else if('D'<=ss1&&ss1<='F'&&'D'<=ss2&&ss2<='F'){cout<<"11";}
else{
cout<<"00";}
}
else{
cout<<"000";}
}else {cout<<"0000";}
return 0;
}
