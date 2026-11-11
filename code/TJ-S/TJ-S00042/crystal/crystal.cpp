#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
ll n, m, a[N], sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
	
	ll ans = 1;
	for(ll i=2; i<=n; i++) {
		ll l = 1, r = i-1, mid;
		while(l <= r) {
			mid = (l + r) >> 1;
			if((i-mid)*a[i]-(sum[i-1]-sum[mid-1]) <= m)
				r = mid - 1, ans = max(ans, i-mid+1);
			else l = mid + 1;
		}
//		for(ll j=1; j<i; j++) {
//			if((i-j)*a[i]-(sum[i-1]-sum[j-1]) <= m) {
//				ans = max(ans, i-j+1);
//				break;
//			}
//		}
	}
	
	cout << ans;
	
	return 0;
}
