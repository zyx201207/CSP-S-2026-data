#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
if(a==c){
cout<<'1';
}
else{
cout<<'0'<<'0'<<'0'<<'0';
return 0;
}
string m,n;
for(int i=0;i<=1;i++){
m[i]=b[i];
n[i]=d[i];
}
char s=b[2],w=d[2];
if(m==n){
cout<<'1';
}
else{
cout<<"000";
return 0;
}
if('A'<=s&&s<='C'&&'A'<=w&&w<='C'){
cout<<"1";
}
else if('D'<=s&&s<='F'&&'D'<=w&&w<='F'){
cout<<"11";
return 0;
}
else{
cout<<"00";
return 0;
}
if('s'-'w'==1&&'w'-'s'==1){
cout<<'1';
}
else{
cout<<'0';
}
return 0;
}
