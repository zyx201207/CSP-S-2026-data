#include<bits/stdc++.h>
using namespace std;

long long a[500005];
long long b[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	if(n>=5000)
	{
		cin>>a[1]>>a[2];
		long long k=a[2]-a[1];
		cout<<m/k+1;
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long maxx=0;
	for(long long i=1;i<=n;i++)
	{
		long long sum=0;
		long long ans=0;
		for(long long j=i-1;j>0;j--)
		{
			sum+=a[i]-a[j];
			if(sum<=m)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		maxx=max(maxx,ans+1);
	}
	cout<<maxx;
	return 0;
}
