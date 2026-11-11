#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10;
ll a[N];
ll b[N];
ll n,m;
bool check(ll l,ll r){
	if (((r-l+1)*a[r]-(b[r]-b[l-1]))<=m) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll ans=0;
	for (ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (ll i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for (ll i=1;i<=n;i++){
		ll l=1,r=i;
		while (l<r){
			int mid=(l+r)>>1;
			if (check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
