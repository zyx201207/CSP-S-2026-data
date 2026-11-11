#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-2000000000000;
long long a[250005];
int main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=n-1;i>=0;i--)
	{
		long long b[250005];
		for(long long j=0;j<n;j++)
		{
			b[j]=a[i]-a[j];
		}
		long long l=m,sum=0;
		sort(b,b+n);
		for(long long j=0;j<n;j++)
		{
			if(b[j]>=0&&b[j]<=l)
			{
				sum++;
				l-=b[j];
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
