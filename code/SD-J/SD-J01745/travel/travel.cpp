#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]&&c1[0]==c2[0])
	{
		f=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	bool k=0;
	if(f==1&&s1[0]==s2[0]&&s1[1]==s2[1])
	{
		k=1;
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	bool m=0;
	if(k==1)
	{
		if(s1[2]=='D'||s1[2]=='F')
		{
			if(s2[2]=='D'||s2[2]=='F')
			{
				m=1;
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else if(s1[2]=='C'||s1[2]=='B'||s1[2]=='A')
		{
			if(s2[2]=='C'||s2[2]=='B'||s2[2]=='A')
			{
				m=1;
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	
	
	if(m==1)
	{
		if(abs(s1[2]-s2[2])==1)
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	return 0;
 } 
