#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N],sum[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		ll l=1,r=i-1,mid;
		while (l<r)
		{
			mid=(l+r)>>1;
			if (m>=(i-mid+1)*a[i]-(sum[i]-sum[mid-1])) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout << ans;
	return 0;
}
