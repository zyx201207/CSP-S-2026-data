#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	bool x=false;
	if(a1==a2)
	{
		cout<<"1";
		x=true;
	}
	else
	{
		cout<<"0";
	}
	bool l=false;
	if(x&&(b1[0]==b2[0])&&(b1[1]==b2[1]))
	{
		cout<<"1";
		l=true;
	}
	else
	{
		cout<<"0";
	}
	bool c=false;
	if(l&&x)
	{
		if((b1[2]=='A'||b1[2]=='B'||b1[2]=='C')&&(b2[2]=='D'||b2[2]=='F'))
		{
			cout<<"0";
		}
		else if((b2[2]=='A'||b2[2]=='B'||b2[2]=='C')&&(b1[2]=='D'||b1[2]=='F'))
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
			c=true;
		}
	}
	else
	{
		cout<<"0";
	}
	if(l&&c&&x)
	{
		if(b1[2]=='A'&&b2[2]=='C'||b2[2]=='A'&&b1[2]=='C')
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
