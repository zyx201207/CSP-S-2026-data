#include<bits/stdc++.h>
using namespace std;
long long a[200001][2];
int main()
{   
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char b;
	int o;
	long long x,y,z,c,d,e,f;
	cin>>x;
	y = 0;
	for (int i=1;i<=x;i++)
	{
		cin>>a[i][0]>>b;
		o=int(b-'a'+1);
		a[i][1]=o;
		y += a[i][0];
	}
	z = y/2;
	if (y%2==1)
		z++;
	c = 0;
	for (int i=1;i<=x;i++)
	{		
		c += a[i][0];
		if (c>=z)
			{c = i;break;}
	}	
	d = 1;
	e = x;
	f = 0;
	while (d<=c&&e>=c)
	{
		if (a[d][1]!=a[e][1])
			f += min(a[d][0],a[e][0]);
		if(a[d][0]>=a[e][0] )
		{a[d][0]-=a[e][0],e--;}
		else
		{a[e][0]-=a[d][0],d++;}
	}
	cout<<f;
	return 0;
}
