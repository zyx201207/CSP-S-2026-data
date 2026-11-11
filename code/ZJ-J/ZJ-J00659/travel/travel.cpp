#include <bits/stdc++.h>
using namespace std;
char s1[10],s2[10],s3[10],s4[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s1+1>>s2+1>>s3+1>>s4+1;
	if(s1[1]==s3[1]&&s1[2]==s3[2]) cout<<1;
	else cout<<0<<0<<0<<0,exit(0);
	if(s2[1]==s4[1]&&s2[2]==s4[2]) cout<<1;
	else cout<<0<<0<<0,exit(0);
	if(s2[3]=='C'&&s4[3]=='D'||s2[3]=='D'&&s4[3]=='C')
		cout<<0<<0,exit(0);
	else if(s2[3]<='C'&&s4[3]>='D'||s2[3]>='D'&&s4[3]
	<='C') cout<<0<<0,exit(0);
	else cout<<1;
	if(abs(int(s2[3])-int(s4[3]))==1||(s2[3]=='D'&&s4[3]
	=='F')||(s2[3]=='F'&&s4[3]=='D')) cout<<1;
	else cout<<0;
	return 0;
}