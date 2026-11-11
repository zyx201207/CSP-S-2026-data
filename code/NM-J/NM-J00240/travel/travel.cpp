#include<bits/stdc++.h>
using namespace std;

int main (){
freopen("travel.in","r","stdin");
freopen("travel.out","w","stdout");
string s1,c1,s2,c2;
cin>>s1>>c1>>s2>>c2;
int a=0;
int b=0;
int c=0;
int d=0;
if(s1==s2){
a=1;
}
else{
	cout<<a<<b<<c<<d;
	return 0;
	}
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
	b=1;
	if(c1[2]<='C'&&c2[2]<='C'){
		c=1;
		if(c1[2]+1==c2[2]||c2[2]+1==c1[2]){
			d=1;
			cout <<a<<b<<c<<d;
			return 0;
		}
		else{
			cout <<a<<b<<c<<d;
			return 0;
			}
	}
	else if(c1[2]=='D'&&c2[2]=='F'||c1[2]=='F'&&c2[2]=='D'){
		c=1;
		d=1;
		cout <<a<<b<<c<<d;
		return 0;
		}
		else{
			cout <<a<<b<<c<<d;
			return 0;
			}
	}
	else{
	cout <<a<<b<<c<<d;
	return 0;
		}
	
	return 0;
}
