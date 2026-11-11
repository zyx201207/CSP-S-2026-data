#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+60;
ll n,m;
ll a[N],sum[N];
ll ans=-0x3f3f3f3f;
bool check(ll mid,ll r)
{
	ll cnt=(r-mid)*a[r]-(sum[r-1]-sum[mid-1]);
	return cnt<=m;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		ll l=0,r=i;
		while(l+1!=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid;
		}
		ll pos=upper_bound(a+1,a+1+n,a[i])-a-1;
		ans=max(ans,ll(pos-r+1));
	}
	cout<<ans<<'\n';
	return 0;
}
