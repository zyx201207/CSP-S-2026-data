#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	preopen("travel.in",a,b,c,d,m,n);
	preopen("travel.out",a,b,c,d);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"1";
		if(b%d==0)
		{
		cout<<"1";
		b=m;
		d=n;
			if(m==n)
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
	}
	else
	{
		cout<<"0000";
	}
	
	return 0;
}
