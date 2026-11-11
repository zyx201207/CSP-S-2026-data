#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll sum[N],a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll w;
	for(int i=2;i<=n;i++) 
	{
		ll c=a[i]-a[i-1];
		w+=c;
		sum[i]+=w;
	}
	ll ans=lower_bound(sum+1,sum+n+1,m)-sum-1;
	cout<<ans<<"\n";
	return 0;
}
