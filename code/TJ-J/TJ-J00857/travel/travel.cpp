#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string y;
	bool x=true;
	bool ctl=true;
	for(int i=0;i<2;i++)
	{
		if(a[i]!=c[i])
	    {
			x=false;
			ctl==false;
		}
	}
	if(x&&ctl)
	{
		y+='1';
	}
	else
	{
		y+='0';
	}
	x=true;
	for(int i=0;i<2;i++)
	{
		if(b[i]!=d[i])
		{
			x=false;
			ctl=false;
		}
	}
	if(x&ctl)
	{
		y+='1';
	}
	else
	{
		y+='0';
	}
	x=false;
	int z=0;
	if((b[2]=='F')||(b[2]=='D'))
	{
		z++;
	}
	if((d[2]=='F')||(d[2]=='D'))
	{
		z++;
	}
	if(z%2==0&&ctl)
	{
		y+='1';
	}
	else
	{
		y+='0';
		ctl=false;
	}
	if(z==2)
	{
		if((b[2]==(d[2]+1))||(b[2]==(d[2]-1)))
		{
			x=true;
		}
	}
	else if(z==0)
	{
		if((b[2]==(d[2]+1))||(b[2]==(d[2]-1)))
		{
			x=true;
		}
	}else
	{
		ctl=false;
	}
	if(x&ctl)
	{
		y+='1';
	}
	else
	{
		y+='0';
	}
	cout<<y;
	return 0;
}
