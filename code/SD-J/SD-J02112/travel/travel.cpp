#include<bits/stdc++.h>
#define a ((s[2]<='C'&&t[2]<='C')||(s[2]>'C'&&t[2]>'C'))
#define b ((s[2]=='A'&&t[2]=='B')||(s[2]=='B'&&t[2]=='C')||(s[2]=='D'&&t[2]=='F'))
#define c ((s[2]=='B'&&t[2]=='A')||(s[2]=='C'&&t[2]=='B')||(s[2]=='F'&&t[2]=='D'))
using namespace std;
int r,x,ans;string s,t; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>s>>x>>t;
	ans+=(r==x);
	if(ans==1)ans+=(s[0]==t[0]&&s[1]==t[1]);
	if(ans==2)ans+=a;
	if(ans==3)ans+=(b||c);
	for(int i=1;i<=ans;i++)putchar('1');
	for(int i=ans;i<4;i++)putchar('0');
	return 0;
} 
