#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char fl1='0',fl2='0',fl3='0',fl4='0';
	if(c1==c2){
		fl1='1';
	}
	if(fl1=='1'&s1.substr(0,2)==s2.substr(0,2)){
		fl2='1';
	}
	string a1,a2;
	a1=s1.substr(2,1);
	a2=s2.substr(2,1);
	if(fl2=='1'){
		if((a1[0]>='D'&&a1[0]<='F'&&a2[0]>='D'&&a2[0]<='F')||(a1[0]>='A'&&a1[0]<='C'&&a2[0]>='A'&&a2[0]<='C')){
			fl3='1';
		}
	}
	if(fl3=='1'){
		if(a1[0]+1==a2[0]||a2[0]+1==a1[0]||(a1[0]=='D'&&a2[0]=='F')||(a1[0]=='F'&&a2[0]=='D')){
			fl4='1';
		}
	}
	cout<<fl1<<fl2<<fl3<<fl4;
	return 0;
} 
