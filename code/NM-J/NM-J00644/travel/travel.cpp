#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string ca,wa,cb,wb;
	cin>>ca>>wa>>cb>>wb;
	bool a=0,b=0,c=0,d=0;
	long long i,s=0;
	for(i=0;i<=1;i++)
	{
		if(ca[i]==cb[i]) s++;
	}
	if(s==2)
	{
		a=1;
	}
	s=0;
	if(a==1)
	{
		for(i=0;i<=1;i++)
	    {
		    if(wa[i]==wb[i]) s++;
	    }
	    if(s==2) b=1;
	}
	if(a==1&&b==1)
	{
		if(wa[2]=='A')
		{
			if(wb[2]=='B')
			{
				c=1;
				d=1;
			}
			else if(wb[2]=='C')
			{
				c=1;
			}
		}
		if(wa[2]=='B')
		{
			if(wb[2]=='A'||wb[2]=='C')
			{
				c=1;
				d=1;
			}
		}
		if(wa[2]=='C')
		{
			if(wb[2]=='B')
			{
				c=1;
				d=1;
			}
			else if(wb[2]=='A')
			{
				c=1;
			}
		}
		if(wa[2]=='D')
		{
			if(wb[2]=='F')
			{
				c=1;
				d=1;
			}
		}
		if(wa[2]=='F')
		{
			if(wb[2]=='D')
			{
				c=1;
				d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
