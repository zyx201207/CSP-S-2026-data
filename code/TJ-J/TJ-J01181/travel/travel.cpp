#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c1,s1;
	cin>>c>>s>>c1>>s1;
	if(c==c1){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s[0]==s1[0]&&s[1]==s1[1]){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(s[2]>'C'&&s1[2]<'D'||s[2]<'D'&&s1[2]>'C'){
		cout<<0<<0;
		return 0;
	}
	else{
		cout<<1;
	}
	int a=s[2]-s1[2];
	if(a<0){
		a=0-a;
	}
	if(a==1||s[2]=='D'&&s1[2]=='F'||s[2]=='F'&&s1[2]=='D'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
