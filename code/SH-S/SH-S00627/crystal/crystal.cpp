#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l,r,a[500010];
bool ok(ll mid) {
	for(ll i=1,sum=0; i<=n; ++i) {
		sum+=a[i];
		if(i>=mid) {
			if(mid*a[i]-sum<=m) return 1;
			sum-=a[i-mid];
		}
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m,r=n;
	for(ll i=1; i<=n; ++i) cin>>a[i];
	sort(a+1,a+n+1);
	while(l<r) {
		ll mid=(l+r+1)>>1;
		if(ok(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
