#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(s1[2]=='D') s1[2]='E';
	if(s2[2]=='D') s2[2]='E';
	if(c1==c2) a=1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) b=1;
	else{
		cout<<"1000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) c=1;
	else{
		cout<<"1100";
		return 0;
	}
	if((abs(int(s1[2])-int(s2[2]))==1)||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))) d=1;
	else{
		cout<<"1110";
		return 0;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
