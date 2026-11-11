#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned int n=0,m=0;
	cin>>n>>m;
	long long int a[n+3],cz[n+3],sum[n+3];
	int x[100003],y;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=0;j<n;++j)
	{
		for(int i=1;i<n;++i)
		{
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
			}
		}
	}
	for(int i=1;i<n;++i)
	{
		cz[i]=a[i+1]-a[i];
	}
	for(int j=1;j<n;++j)                                   
	{
		int i=j;
		while(sum[j]>m||i>n)
		{
			sum[j]+=cz[i];
			i++;x[j]++;
		}
		sum[j]-=cz[i-1];
	}
	y=x[1];
	for(int i=1;i<n;i++)
	{
		if(y<x[i])
		{
			y=x[i];
		}
	}
	cout<<y<<endl;
	return 0;
}