#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//const int N=
string a,b,c,d; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool a1=0,b1=0,c1=0,d1=0;
	if(a==c)
	{
		a1=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&a==c)
	{
		b1=1;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&a==c)
	{
		if(b[2]=='A')
		{
			if(d[2]=='B'||d[2]=='C')
				c1=1;
		}
		else if(b[2]=='B')
		{
			if(d[2]=='A'||d[2]=='C')
				c1=1;
		}
		else if(b[2]=='C')
		{
			if(d[2]=='A'||d[2]=='B')
				c1=1;
		}
		else if(b[2]=='D')
		{
			if(d[2]=='F')
				c1=1;
		}
		else if(b[2]=='F')
		{
			if(d[2]=='D')
				c1=1;
		}
		if(b[2]=='A')
		{
			if(d[2]=='B')
				d1=1;
		}
		else if(b[2]=='B')
		{
			if(d[2]=='A'||d[2]=='C')
				d1=1;
		}
		else if(b[2]=='C')
		{
			if(d[2]=='B')
				d1=1;
		}
		else if(b[2]=='D')
		{
			if(d[2]=='F')
				d1=1;
		}
		else if(b[2]=='F')
		{
			if(d[2]=='D')
			{
				d1=1;
			}
		}
	}
	cout<<a1<<b1<<c1<<d1;
	return 0;
}
