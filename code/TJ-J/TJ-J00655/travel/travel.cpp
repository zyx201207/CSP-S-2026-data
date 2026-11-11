#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=1;
	for(int i=0;i<=1;i++){
		if(c1[i]!=c2[i]) flag=0;
	}
	if(flag) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	flag=1;
	for(int i=0;i<=1;i++){
		if(s1[i]!=s2[i]) flag=0;
	}
	if(flag) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	
	if(s1[2]=='C'&&s2[2]=='D'){
		cout<<"00";
		return 0;
	}
	else if(s1[2]=='D'&&s2[2]=='C'){
		cout<<"00";
		return 0;
	}
	else cout<<1;
	
	if(s1[2]-'A'+1==s2[2]-'A') cout<<1;
	else if(s1[2]-'A'==s2[2]-'A'+1) cout<<1;
	else cout<<0;
	return 0;
 }
