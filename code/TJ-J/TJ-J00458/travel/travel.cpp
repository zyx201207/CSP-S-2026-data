#include <iostream>
using namespace std;
string rc,xc,a,b;
string aa,bb;
char ac,bc;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>a>>xc>>b;
	aa=a[0]+a[1];
	bb=b[0]+b[1];
	ac=a[2];
	bc=b[2];
	if (rc==xc)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if (aa==bb)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
	if (ac<='F' and ac>='D' and bc>='D' and bc<='F')
	{
		cout<<11;
		return 0;
	}
	else if (ac<='C' and ac>='A' and bc<='C' and bc>='A')
	{
		cout<<1;
		if (ac=='B' or bc=='B')
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	return 0;
 } 
