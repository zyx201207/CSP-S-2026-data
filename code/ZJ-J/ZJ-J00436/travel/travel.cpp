#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<s1.size();i++)
	{
		if(int(s1[i])!=int(s3[i]))
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<2;i++)
	{
		if(int(s2[i])!=int(s4[i]))
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(s2[2]=='A')
	{
		if(s4[2]=='B')
		{
			cout<<"11";
		}
		else if(s4[2]=='C')
		{
			cout<<"10";
		}
		else
		{
			cout<<"00";
		}
	}
	else if(s2[2]=='B')
	{
		if(s4[2]=='D'||s4[2]=='F')
		{
			cout<<"00";
		}
		else
		{
			cout<<"11";
		}
	}
	else if(s2[2]=='C')
	{
		if(s4[2]=='B')
		{
			cout<<"11";
		}
		else if(s4[2]=='A')
		{
			cout<<"10";
		}
		else
		{
			cout<<"00";
		}
	}
	else if(s2[2]=='D')
	{
		if(s4[2]=='F')
		{
			cout<<"11";
		}
		else
		{
			cout<<"00";
		}
	}
	else if(s2[2]=='F')
	{
		if(s4[2]=='D')
		{
			cout<<"11";
		}
		else
		{
			cout<<"00";
		}
	}
	return 0;
}
