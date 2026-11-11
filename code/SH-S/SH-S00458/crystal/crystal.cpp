#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 5e5+5;

ll n, m, a[N], pre[N];

bool check (ll d) {
	if (d>n) return 0;
	for (ll i=d; i<=n; i++) {
		ll sum = pre[i]-pre[i-d];
		//cout<<d<<' '<<i<<' '<<(a[i]-a[i-1])*d<<' '<<sum<<'\n'; 
		if (a[i]*d - sum <= m) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	
	cin>>n>>m;
	for (ll i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort (a+1, a+n+1);
	for (ll i=1; i<=n; i++) {
		pre[i] = a[i]+pre[i-1];
	}
	
	ll l=1, r=n+1, ans=1;
	ll mid;
	while (l<r) {
		mid = (l+r)>>1;
		if (check(mid)) {
			ans = max(ans, mid);
			l=mid+1;
		} else {
			r=mid;
		}
		//cout<<mid<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/ 

