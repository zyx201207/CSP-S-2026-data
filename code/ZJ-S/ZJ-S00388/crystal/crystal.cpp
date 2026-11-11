#include<bits/stdc++.h>
using namespace std;
int n;
long long m,ans;
long long a[500005],sum[500005];
long long cal(long long l,long long r)
{
	return 1ll*(r-l+1)*a[r]-(sum[r]-sum[l-1]);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		long long l=0,r=i+1;
		while(l+1<r)
		{
			long long mid=(l+r)/2;
			long long num=cal(mid,i);
			if(num<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout << ans;
	return 0;
}
