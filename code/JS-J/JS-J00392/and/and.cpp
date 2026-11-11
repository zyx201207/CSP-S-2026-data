#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long arr[n];
	vector <long long> z;
	for(long long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(long long i=0;i<n-m;i++)
	{
		z[i]=arr[i];
		for(long long j=1;j<=m;j++)
		{
			z[i]=z[i]&z[i+j];
		}
	}
	long long x=z.size();
	for(long long i=0;i<x;i++)
	{
		for(long long j=i;j<x-1;j++)
		{
			if(z[j]<z[j+1])
			{
				long long a=z[j];
				z[j]=z[j+1];
				z[j+1]=a;
			}
		}
	}
	cout<<z[x-1];
	return 0;
}
