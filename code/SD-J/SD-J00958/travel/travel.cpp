#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
string a,b,c,d;
bool flag1,flag2,flag3;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) flag1=true,cout<<1;
	else cout<<0;
	if(b[1]==d[1] and b[0]==d[0] and flag1) flag2=true,cout<<1;
	else cout<<0;
	if(!flag2)
	{
		cout<<0<<0;
		return 0;
	}
	if(b[2]=='F')
	{
		if(d[2]=='D')
		{
			cout<<1<<1;
			return 0;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	else if(b[2]=='D')
	{
		if(d[2]=='F')
		{
			cout<<1<<1;
			return 0;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	else if(b[2]=='C')
	{
		if(d[2]=='B')
		{
			cout<<1<<1;
			return 0;
		}
		else if(d[2]=='A')
		{
			cout<<1<<0;
			return 0;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	else if(b[2]=='B')
	{
		if(d[2]=='A' or d[2]=='C')
		{
			cout<<1<<1;
			return 0;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	else if(b[2]=='A')
	{
		if(d[2]=='B')
		{
			cout<<1<<1;
			return 0;
		}
		else if(d[2]=='C')
		{
			cout<<1<<0;
			return 0;
		}
		else
		{
			cout<<0<<0;
			return 0;
		}
	}
	return 0;
}
