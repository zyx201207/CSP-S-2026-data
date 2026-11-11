#include<bits/stdc++.h>
using namespace std;
long long a[5000010],d[5000010],c[3000010];
bool fun1(int n)
{
	for(int i=1;i<n;i++)
	{
		if(d[i]==d[n])
		{
			return true;
		}
	}
	return false;
}
int fun2(int n)
{
	for(int i=1;i<=n;i++)
	{
		if(d[i]==d[n])
		{
			return i; 
		}
	}
}
int main()
{	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long k=0;
		for(int j=i;j<=n;j++)
		{
			d[++k]=a[j];
			if(fun1(k))
			{
				k=fun2(k);
			}
		}
		for(int i=1;i<=k;i++)
		{
			c[d[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
