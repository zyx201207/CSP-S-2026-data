#include <bits/stdc++.h>
using namespace std;

// RP++
// AC AC AC

typedef long long ll;
const ll N = 5*1e5+5;
ll n, m, a[N], b[N], ans, k, tmp, t;
ll dp[N][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (ll i=1; i<=n; i++) {
		cin >> a[i];
	}
	
	sort(a+1, a+1+n, [](ll x, ll y){
		return x > y;
	});
	for (ll i=1; i<=n; i++) {
		b[i] = abs(a[i-1]-a[i]);
		dp[i][0] = 1;
	}
	for (ll i=n-1; i>=1; i--) {
		if (b[i+1]*dp[i+1][0]+dp[i+1][1] <= m) {
			dp[i][0] = dp[i+1][0]+1;
			dp[i][1] = b[i+1]*dp[i+1][0]+dp[i+1][1];
		}
		else {
			k = 1;
			tmp = 0;
			t = 0;
			for (ll j=i+1; j<=n; j++) {
				t += b[j];
				if (tmp+t <= m) {
					k++;
					tmp += t;
				}
				else {
					break;
				}
			}
			dp[i][0] = k;
			dp[i][1] = tmp;
		}
		ans = max(dp[i][0], ans);
	}
	cout << ans << "\n";

	return 0;
}

