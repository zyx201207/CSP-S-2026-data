#include <bits/stdc++.h>
using namespace std;
int c1,c2;
string num1,num2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>num1>>c2>>num2;
if(c1!=c2){cout<<"0000";return 0;}

int i1=(num1[0]-'0')*10+num1[1]-'0';
int i2=(num2[0]-'0')*10+num2[1]-'0';
if(i1!=i2){cout<<"1000";return 0;}
int s1=num1[2];
int s2=num2[2];
if(s1<='C'&&s2<='C'||s1>='D'&&s2>='D'){
}else{cout<<"1100";return 0;}
if(abs(s1-s2)!=1){cout<<"1110";return 0;}
cout<<"1111";
return 0;
}
