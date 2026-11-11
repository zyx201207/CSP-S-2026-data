#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e6+5;

ll c;
ll T, n, d, x[N];

bool check (ll s) {
	if (x[s+3]-x[s] > d && x[s+2]-x[s] <= d && x[s+3]-x[s+1] <= d) return 1;
	return 0;
}

struct Sm {
	ll l, r;
};

set <ll> l, r;
vector <Sm> v;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>c>>T;
	while (T--) {
		cin>>n>>d;
		ll dx=0;
		for (ll i=1; i<=n; i++) {
			cin>>x[i];
			if (dx==0) {
				dx=(i==1?0:x[i]-x[i-1]);
			} else if (dx>0) {
				if (dx != x[i]-x[i-1]) {
					dx=-1;
				}
			}
		}
		ll ans=0;
		if (dx>0) {
			if (d<dx*2) cout<<0<<'\n';
			ll k = d/dx;
			k = k+k;
			cout<<n-k+1<<'\n';
		}
	}
	return 0;
}
