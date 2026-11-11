#include<bits/stdc++.h>
using namespace std;
bool f(char x,char y){
	if(x=='A'&&y=='C')return true;
	if(x=='C'&&y=='A')return true;
	if(x=='A'&&y=='B')return true;
	if(x=='B'&&y=='A')return true;
	if(x=='B'&&y=='C')return true;
	if(x=='C'&&y=='B')return true;
	if(x=='D'&&y=='F')return true;
	if(x=='F'&&y=='D')return true;
	return false;
}
bool g(char x,char y){
	if(x=='A'&&y=='B')return true;
	if(x=='B'&&y=='A')return true;
	if(x=='B'&&y=='C')return true;
	if(x=='C'&&y=='B')return true;
	if(x=='D'&&y=='F')return true;
	if(x=='F'&&y=='D')return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	char v1=s1[2],v2=s2[2];
	if(f(v1,v2))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(g(v1,v2))cout<<1;
	else cout<<0;
	return 0;
}
