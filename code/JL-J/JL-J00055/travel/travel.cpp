#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
int a,b,m,n,u1,u2,u3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	
	if(cr[0]==cx[0]&&cr[1]==cx[1])
	{
		cout<<"1";
		u1=1;
	}
	else
	{
		cout<<"0";
		u1=0;
	}
	
	if(sr[0]==sx[0]&&sr[1]==sx[1]&&u1==1)
	{
		cout<<"1";
		u2=1;
	}
	else
	{
		cout<<"0";
		u2=0;
	}
	
	a=int(sr[2]);
	b=int(sx[2]);
	m=max(a,b);
	n=min(a,b);
	if(m-n==1&&m!=68&&u1==1&&u2==1)
	{
		cout<<"1";
		u3=1;
	}
	else if(m-n==2&&m==67&&u1==1&&u2==1)
	{
		cout<<"1";
		u3=2;
	}
	else
	{
		cout<<"0";
		u3=0;
	}
	
	if(u1==1&&u2==1&&u3!=0)
	{
		if(u3==1)
		{
			cout<<"1";
		}
		if(u3==2)
		{
			if(m-n==1)
			{
				cout<<"1";
			}
			else
			{
				cout<<"0";
			}
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
