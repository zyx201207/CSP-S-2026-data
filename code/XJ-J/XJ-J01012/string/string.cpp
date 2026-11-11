#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,z;
	int w,x,y=0,a[100000];
	for (int i=1;i<=n;i++)
	{
	    cin>>x>>w;
	    for (int j=1+y;j<=y+x;j++)
	    {
	        a[j]=w;
		}
		y+=x;
	}
	if (y%2==0)
	{
		z=y/2;
	}
	else 
	{
		z=y/2+1;
	}
	int g=0;
	for (int e=1;e<=z;e++)
	{
		for (int f=y;f>=z;f--)
		{
			if (a[e]!=a[f])
			{
				g++;
			}
		}
	}
	cout<<g;
	return 0;
}