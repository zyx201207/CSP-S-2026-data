#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d,a1,a2;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a=1;
	}
	else
	{
		a=0;
	}
	a1=0;
	a2=0;
	a1=a1+s1[0]*10;
	a1=a1+s1[1];
	a2=a2+s2[0]*10;
	a2=a2+s2[1];
	if(a==1&&a1==a2)
	{
		b=1;
	}
	else
	{
		b=0;
	}
	if(a==1&&b==1&&s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
	{
		c=1;
	}
	else if(a==1&&b==1&&s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
	{
		c=1;
	}
	else
	{
		c=0;
	}
	if(a==1&&b==1&&c==1)
	{
		if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
		{
			d=1;
		}
		else
		{
			d=0;
		}
	}
	else
	{
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
