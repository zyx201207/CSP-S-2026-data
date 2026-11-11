#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a[3]={};
string b="";
for(int i=0;i<=3;i++){
	cin>>a[i];
if(a[0]==a[2]){
		b+="1";
	}else{
		b+="0";
	}
}
string m=a[1];
string n=a[3];
for(int i=0;i<=9;i++){
if(m[1]=='1'+i&&n[1]=='1'+i+1||m[1]=='1'+i&&n[1]=='1'+i-1){
	b+="1";
}
for(int i=0;i<=25;i++){
if(m[1]=='A'+i&&n[1]=='A'+i+1||m[1]=='A'+i&&n[1]=='A'+i-1){
	b+="1";
}
}}
cout<<b;
return 0;
}
