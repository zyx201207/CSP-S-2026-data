#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],l,r,sum[500005],ans;
bool check(int f)
{
	long long summ=600000000000000000;
	for(int i=f;i<=n;i++)
	{
		summ=min(a[i]*f-sum[i]+sum[i-f],summ);
	}
	return summ<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	l=1;
	r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
