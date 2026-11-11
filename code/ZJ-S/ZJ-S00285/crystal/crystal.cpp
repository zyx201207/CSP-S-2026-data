#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[500005], pre[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1, a+1+n);
	for(ll i=1; i<=n; i++)
		pre[i]=pre[i-1]+a[i];
	ll maxn=0;
	for(ll i=1; i<=n; i++){
		ll l=1, r=i-1, mid, ans=i;
		while(r>=l){
			mid=l+r>>1;
			ll lon=i-mid+1;
			if(lon*a[i]-(pre[i]-pre[mid-1])<=m)r=mid-1, ans=mid;
			else l=mid+1;
		}
		maxn=max(maxn, i-ans+1);
	}
	cout<<maxn;
	return 0;
}

