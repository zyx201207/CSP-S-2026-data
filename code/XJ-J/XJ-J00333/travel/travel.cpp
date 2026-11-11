#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2;
	string s1,s2;
	cin>>a1>>s1>>a2>>s2;
	if(a1==a2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2)){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'))){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}