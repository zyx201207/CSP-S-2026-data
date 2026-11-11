#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans=0;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1, greater<long long>());
	long long mid=(1+n)/2;
	for(long long i=mid;i<=n;i++)
	{
		long long d=a[mid]-a[i];
		if(m>0)
		{
			a[i]+=min(m, d);
			m-=d;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(a[i]==a[mid])
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
