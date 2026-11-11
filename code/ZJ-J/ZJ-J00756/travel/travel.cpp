#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
int a1,a2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	a1+=s2[0]-'0';
	a1*=10;
	a1+=s2[1]-'0';
	a2+=s4[0]-'0';
	a2*=10;
	a2+=s4[1]-'0';
	if(a1==a2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s2[2]=='D'&&s4[2]=='F'){
		cout<<1;
	}
	if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'){
		cout<<1;	
	}
	else{
		cout<<0<<0;
		return 0;
	}
	
	char c1=s2[2],c2=s4[2];
	if(c1=='A'&&c2=='B'){
		cout<<1;return 0;
	}
	if(c1=='B'&&c2=='A'||c2=='C'){
		cout<<1;return 0;
	}
	if(c1=='C'&&c2=='B'){
		cout<<1;return 0;
	}
	if(c1=='D'&&c2=='F'){
		cout<<1;return 0;
	}
	if(c1=='F'&&c2=='D'){
		cout<<1;return 0;
	}
	cout<<0;
	
	return 0;
}