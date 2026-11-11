#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	bool b=0;
	for(int i=0;i<=1;i++){
		if(s2[i]!=s4[i]) b=1;
	}
	if(b==0) cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s2[2]=='C'&&s4[2]=='D'||s4[2]=='C'&&s2[2]=='D'){
		cout<<0<<0;
		return 0;
	}
	else cout<<1;
	if(s2[2]==s4[2]+1||s2[2]==s4[2]-1) cout<<1;
	else cout<<0;
	return 0;
}
