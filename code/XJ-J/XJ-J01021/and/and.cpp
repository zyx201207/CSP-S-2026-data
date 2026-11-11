#include<bits/stdc++.h>
using namespace std;
long long int i,c,k=1,j,m,n,a[1000000],b;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(k=2;k<=m;k++)
	{ c=b;
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(k>2)
		c=b;
		else
		c=a[i];
		if(i!=j)
		if(c&a[j]>b)
		{
			b=a[i]&a[j];
		}
	}
	}
	
	cout<<b;
	return 0;
} 