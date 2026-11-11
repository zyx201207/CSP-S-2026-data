#include<iostream>
#include<fstream>
#include<cstdio>
#include<string> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000";
		return 0;
	}
	char r=s1[2],x=s2[2];
	//cout<<r<<" "<<x;//debug
	if((r=='A'&&r=='C')||(r=='C'&&x=='A')){
		cout<<"1110";
		return 0;
	}
	if((r=='A'&&x=='B')||(r=='B'&&x=='C')||(r=='D'&&x=='F') || (x=='A'&&r=='B')||(x=='B'&&r=='C')||(x=='D'&&r=='F')){
		cout<<"1111";
		return 0;
	}
	cout<<"1100";
	return 0;
} 
