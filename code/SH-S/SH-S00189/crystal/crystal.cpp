#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500010];
ll sum[500010];
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
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	ll j=1;
	ll ans=0;
	for(ll i=1;i<=n;i++)
	{
		while(j<i&&(i-j+1)*a[i]-(sum[i]-sum[j-1])>m)
			j++;
		ans=max(ans,i-j+1ll);
	}
	cout<<ans; 
	return 0;
} 
