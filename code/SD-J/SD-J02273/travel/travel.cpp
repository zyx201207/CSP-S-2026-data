#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d;
string x,y; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	c=(x[0]-'0')*10+(x[1]-'0');
	d=(y[0]-'0')*10+(y[1]-'0');
	if(c==d)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if(x[2] >= 'A' && x[2] <= 'C' && y[2] >= 'A' && y[2] <= 'C' || (x[2] == 'D' || x[2] == 'F') && (y[2] == 'D' || y[2] == 'F'))
	{
		cout<<1;
		if(x[2]-1==y[2] || x[2]+1==y[2])
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
		cout<<0<<0;
	}
	
	return 0;
}
