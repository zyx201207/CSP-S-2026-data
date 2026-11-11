#include<bits/stdc++.h>
using namespace std;
struct node
{
	string s,c;
};
node s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1.s>>s1.c>>s2.s>>s2.c;
	if(s1.s[0]==s2.s[0]&&s1.s[1]==s2.s[1])cout<<1;
	else cout<<0;
	if(s1.s[0]==s2.s[0]&&s1.s[1]==s2.s[1])
	{
		if(s1.c[0]==s2.c[0]&&s1.c[1]==s2.c[1])cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(s1.s[0]==s2.s[0]&&s1.s[1]==s2.s[1])
	{
		if(s1.c[0]==s2.c[0]&&s1.c[1]==s2.c[1])
		{
			if(s1.c[2]=='A'||s1.c[2]=='B'||s1.c[2]=='C'&&s2.c[2]=='A'||s2.c[2]=='B'||s2.c[2]=='C')cout<<1;
			else if(s1.c[2]=='D'||s1.c[2]=='F'&&s2.c[2]=='D'||s2.c[2]=='F')cout<<1;
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
	if(s1.s[0]==s2.s[0]&&s1.s[1]==s2.s[1])
	{
		if(s1.c[0]==s2.c[0]&&s1.c[1]==s2.c[1])
		{
			if(s1.c[2]=='A'||s1.c[2]=='B'||s1.c[2]=='C'&&s2.c[2]=='A'||s2.c[2]=='B'||s2.c[2]=='C')
			{
				if(s1.c[2]=='A'&&s2.c[2]=='B')cout<<1;
				else if(s1.c[2]=='B'&&s2.c[2]=='A'||s1.c[2]=='B'&&s2.c[2]=='C')cout<<1;
				else if(s1.c[2]=='C'&&s2.c[2]=='B')cout<<1;
				else cout<<0;
			}
			else if(s1.c[2]=='D'||s1.c[2]=='F'&&s2.c[2]=='D'||s2.c[2]=='F')
			{
				if(s1.c[2]=='D'&&s2.c[2]=='F')cout<<1;
				else if(s1.c[2]=='F'&&s2.c[2]=='D')cout<<1;
				else cout<<0;
			}
			else cout<<0;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
