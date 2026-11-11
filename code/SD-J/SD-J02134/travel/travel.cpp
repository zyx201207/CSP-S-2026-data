#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) 
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i]) {
			cout<<"1000";
			return 0;
		}
	}
	if(s1[2]=='A')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(s1[2]=='B')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(s1[2]=='C')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(s1[2]=='D')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			cout<<"1100";
			return 0;
		}
	}
	if(s1[2]=='F')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			cout<<"1100";
			return 0;
		}
	}
	
	
	
	
	if(s1[2]=='A')
	{
		if(s2[2]=='D'||s2[2]=='F'||s2[2]=='C')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='B')
	{
		if(s2[2]=='D'||s2[2]=='F')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='C')
	{
		if(s2[2]=='D'||s2[2]=='F'||s2[2]=='A')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='D')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			cout<<"1110";
			return 0;
		}
	}
	if(s1[2]=='F')
	{
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		{
			cout<<"1110";
			return 0;
		}
	}
	cout<<"1111";
	return 0;
} 
