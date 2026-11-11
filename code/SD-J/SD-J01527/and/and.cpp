#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
#define ___prique_mx priority_queue<vector<ll>>
#define ___prique_mn priority_queue<vector<ll, greater<ll>>>
#define endl '\n'
const int N = 2e5 + 10;
ll a[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, m; cin >> n >> m;
	for(ll i = 1; i <= n; ++ i) cin >> a[i];
	ll ans = -1000000LL;
	for(ll i = 1; i <= (1 << (n + 1)); ++ i) {
		ll cnt = 0;
		for(ll j = 1; j <= n; ++ j) {
			ll M = i;
			if(M >> j & 1) {
				cnt ++;
			}
		}
		if(cnt != m) continue;
		ll x = -1;
		for(ll j = 1; j <= n; ++ j) {
			ll M = i;
			if(M >> j & 1) {
				if(x == -1) x = a[j];
				else x &= a[j];
			}
		}
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
