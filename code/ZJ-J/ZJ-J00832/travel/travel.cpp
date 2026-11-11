#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='A')
	{
		if(s2[2]=='B' or s2[2]=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(s1[2]=='B')
	{
		if(s2[2]=='A' or s2[2]=='C')
			cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(s1[2]=='C')
	{
		if(s2[2]=='A' or s2[2]=='B')
			cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else if(s1[2]=='D')
	{
		if(s2[2]=='E')
			cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		if(s2[2]=='D')
			cout<<1;
		else
		{
			cout<<"00";
			return 0;
		}
	}
	string s=s1.substr(2,1)+s2.substr(2,1);
	if(s=="AB" or s=="BC" or s=="DE" or s=="BA" or s=="CB" or s=="ED")
		cout<<1;
	else
		cout<<0;
	return 0;
}