#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool a1=false,b1=false,c1=false,d1=false;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		a1=true;
	}
	else
	{
		cout<<a1<<b1<<c1<<d1;
		return 0;
	}
	if(b[0]+b[1]==d[0]+d[1])
	{
		b1=true;
	}
	else 
	{
		cout<<a1<<b1<<c1<<d1;
		return 0;
	}
	if(b[2]<'D' && d[2]<'D'  ||  b[2]>'C' && d[2]>'c')
	{
		c1=true;
	}
	else 
	{
		cout<<a1<<b1<<c1<<d1;
		return 0;
	}
	if(b[2]+1==d[2] || b[2]-1==d[2])
	{
		d1=true;
	}
	cout<<a1<<b1<<c1<<d1;
	return 0;
}
	