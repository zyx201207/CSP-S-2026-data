#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool car=0;
	bool line=0;
	bool sides=0;
	if(c1==c2)
	{
		cout<<1;
		car=1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&car)
	{
		cout<<1;
		line=1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int c1l=0;
	int c2l=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	{
		c1l=1;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
	{
		c2l=1;
	}
	if(c1l==c2l&&line)
	{
		cout<<1;
		sides=1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(sides&&abs(s1[2]-s2[2])==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0; 
}
