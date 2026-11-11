#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int l1,l2,x1,x2;
	char z1,z2;
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	l1=s1.size();
	l2=s2.size();
	x1=s1[0]*10+s1[1];
	z1=s1[2];
	x2=s2[0]*10+s2[1];
	z2=s2[2];
	if(c1==c2)
	{
		cout<<1;	
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(l1==l2)
	{
			if(x1==x2)
			{
				cout<<1;	
			}
			else
			{
				cout<<"000";
				return 0;
			}
	}
	else
	{
		cout<<000;
		return 0;
	}
	if(z1=='A'||z1=='B'||z1=='C')
	{
		if(z2=='A'||z2=='B'||z2=='C')
		{
			cout<<1;
			if(z1=='B'||z2=='B')
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
			cout<<00;
		}
	}
	else
	{
		if(z2=='F'||z2=='D')
		{
			cout<<11;
		}
		else
		{
			cout<<00;
		}
	}
	return 0;
}