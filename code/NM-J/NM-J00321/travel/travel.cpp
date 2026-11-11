#include <bits/stdc++.h>
using namespace std;
int a,b;
string s1,s2,s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if (a==b)
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	if (a==b && s1[0]==s2[0] && s1[1]==s2[1])
	{
		s+='1';
	}
	else
	{
		s+='0';
	}
	if (a==b && s1[0]==s2[0] && s1[1]==s2[1])
	{
		if (s1[2]=='A' || s1[2]=='B'|| s1[2]=='C')
		{
			if (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')
			{
				s+='1';
			}
			else
			{
				s+='0';
			}
		}
		else if(s1[2]=='D' || s1[2]=='F')
		{
			if (s2[2]=='D' || s2[2]=='F')
			{
				s+='1';
			}
			else
			{
				s+='0';
			}
		}
		else
		{
			s+='0';
		}
	}
	else
	{
		s+='0';
	}
	if (a==b && s1[0]==s2[0] && s1[1]==s2[1])
	{
		if (abs(s1[2]-s2[2])==1)
		{
			if (s1[2]=='C' && s2[2]=='D')
			{
				s+='0';
			}
			else if (s1[2]=='D' && s2[2]=='C')
			{
				s+='0';
			}
			else
			{
				s+='1';
			}
		}
		else
		{
			s+='0';
		}
	}
	else
	{
		s+='0';
	}
	cout<<s;
	return 0;
}
