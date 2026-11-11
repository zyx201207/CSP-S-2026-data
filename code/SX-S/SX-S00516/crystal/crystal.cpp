#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],b[1000000],h=0,o=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	for(long long k=1;k<=n;k++)
		for(long long i=1;i<=n;i++)
		{
			for(long long j=k;j<i;j++)
			{
				h+=a[i]-a[j];
			}
			if(h<=m)
			{
				o=max(o,i-k+1);
			}
			h=0;
		}
	cout<<o;
	return 0;
}