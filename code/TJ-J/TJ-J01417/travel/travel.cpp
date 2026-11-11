#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2,b1,b2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	a1=s1[0]-'0';
	a2=s1[1]-'0';
	b1=s2[0]-'0';
	b2=s2[1]-'0';
	if(a1==b1&&a2==b2) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	} 
	if(s1[2]=='A'){
		if(s2[2]=='B')cout<<1;
		else cout<<0;
	}
	if(s1[2]=='B'){
		if(s2[2]=='A'||s2[2]=='C')cout<<1;
		else cout<<0;
	}
	if(s1[2]=='C'){
		if(s2[2]=='B')cout<<1;
		else cout<<0;
	}
	if(s1[2]=='D'){
		if(s2[2]=='F')cout<<1;
		else cout<<0;
	}
	if(s1[2]=='F'){
		if(s2[2]=='D')cout<<1;
		else cout<<0;
	}
	return 0;
}
