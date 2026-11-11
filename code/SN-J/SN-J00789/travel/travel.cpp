//雷梦蝶 SN-J00789 西安市第四十二中学
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,a="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a=a+"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	char xa=s1[0]+s1[1],xy=s2[0]+s2[1];
	if(xa==xy){
		a=a+"1";
	}
	else{
		cout<<"1000";
		return 0;
	}
	char b=(char)s1[2],c=(char)s2[2];
	if((b=='D'||b=='E'&&c=='E'||c=='D')||(b>='A'||b<='C'&&c>='A'||c<='C')){
		a=a+"1";
	}
	else{
		cout<<"1100";
		return 0;
	}
	if((b+1==c||b-1==c)&&((b=='D'||b=='F')&&(c=='D'||c=='F'))){
		a=a+"1";
	}

	else{
		cout<<"1110";
		return 0;
	}
	cout<<a;
	return 0;
};
