#include<bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
bool p;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel,out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	if(s[0]==ss[0] and s[1]==ss[1])
	{
		cout<<"1";
		if((s[2]>'C' and ss[2]>'C') or (s[2]<'D' and ss[2]<'D'))
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(s[2]=='B')
	{
		if(ss[2]=='A' or ss[2]=='C')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	
	if(ss[2]=='B')
	{
		if(s[2]=='A' or s[2]=='C')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	
	if(s[2]=='D')
	{
		if(ss[2]=='F')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	
	if(s[2]=='F')
	{
		if(ss[2]=='D')
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	
	if(s[2]!='B' and ss[2]!='B')
	{
		cout<<"0";
	}
	
	return 0;
}
