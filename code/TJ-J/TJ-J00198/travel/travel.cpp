#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int biaoji=0;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		biaoji=1;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1] and biaoji==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		biaoji=1;
	}
	int guodao1=0;
	if(s1[2]=='B' or s1[2]=='A' or s1[2]=='C')
	{
		guodao1=1;
	}
	int guodao2=0;
	if(s2[2]=='B' or s2[2]=='A' or s2[2]=='C')
	{
		guodao2=1;
	}
	if(guodao1==guodao2 and biaoji==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		biaoji=1;
	}
	if(abs(s1[2]-s2[2])==1 and biaoji==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	
	return 0;
 } 
