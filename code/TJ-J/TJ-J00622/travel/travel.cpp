#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r","stdin");
//	freopen("travel.out","w","stdout");
	char s1[10],s2[10];
	string c1,c2;
	cin>>c1;
	for(int i=1;i<=2;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=2;i++){
		cin>>s2[i];
	}
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	s1[1]=s1[1]*10-'0';
	s2[1]=s2[1]*10-'0';
	int k1=0,k2=0;
	k1=s1[1]+s1[2];
	k2=s2[1]+s2[2];
	if(c1==c2&&k1==k2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(c1==c2&&k1==k2&&(s1[3]!='C'&&s2[3]!='D')&&(s1[3]!='D'&&s2[3]!='c')){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	bool f=false;
	if((s1[3]=='A'&&s2[3]=='B')||(s1[3]=='B'&&s2[3]=='A')||(s1[3]=='B'&&s2[3]=='C')||(s1[3]=='C'&&s2[3]=='B')||(s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s2[3]=='D')){
		f=true;
	}
	if(c1==c2&&k1==k2&&(s1[3]!='C'&&s2[3]!='D')&&(s1[3]!='D'&&s2[3]!='C')&&f==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
