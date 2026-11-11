#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(c[0]==d[0]&&c[1]==d[1])
	{
		cout<<1;
		if(c[2]<='C'&&d[2]<='C')
		{
			cout<<1;
			if(max(c[2],d[2])-min(c[2],d[2])==1)
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
			if(max(c[2],d[2])=='F'&&min(c[2],d[2])=='D')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
			if(max(c[2],d[2])=='F'&&min(c[2],d[2])=='D')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	else
	{
		cout<<0;
	}
	
}
