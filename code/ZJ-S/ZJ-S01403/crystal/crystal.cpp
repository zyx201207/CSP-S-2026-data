#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005],mx;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		long long l=0,r=i;
		while(l<r)
		{
			long long mid=(l+r)/2;
			if((i-mid)*a[i]-(sum[i]-sum[mid])<=m)
			r=mid;
			else
			l=mid+1;
		}
		mx=max(mx,i-l);
	}
	cout<<mx;
	return 0;
} 
