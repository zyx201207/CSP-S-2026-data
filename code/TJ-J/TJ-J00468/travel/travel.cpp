#include<bits/stdc++.h>
using namespace std;
int x(string c1,string s1,string c2,string s2)
{
	if(c1!=c2)
	{
		return 1;		
	}
	else if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if(s1[2]=='A'||s1[2]=='B'&&s2[2]=='A'||s2[2]=='B'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='B'||s2[2]=='C'||s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F')
		{
			return 2;
			
		}
		if(s1[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='C')
		{
			return 3;
			
		}
		else
		{
			return 4;
		}
		
	}
	else
	{
		return 5;
	}
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(x(c1,s1,c2,s2)==1)
	{
		cout<<"0000";
	}
	else if(x(c1,s1,c2,s2)==2)
	{
		cout<<"1111";
	}
	else if(x(c1,s1,c2,s2)==3)
	{
		cout<<"1110";
	}
	else if(x(c1,s1,c2,s2)==4)
	{
		cout<<"1100";
	}
	else
	{
		cout<<"1000";
	}
	return 0;
}
