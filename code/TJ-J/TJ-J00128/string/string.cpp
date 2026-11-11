#include <bits/stdc++.h>
using namespace std;
long long n,a[10000000005],sum=0,ans=1,he=0;
char c[10000000005],x[100000000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=a[i];j++)
		{
			x[ans]=c[i];
			ans++;
		}
	}
	for(long long i=1;i<=ans;i++)
	{
		if(x[i]!=x[ans])
		{
			sum++;
		}
		ans--;
	}
	cout<<sum-1;
	return 0;
} 
