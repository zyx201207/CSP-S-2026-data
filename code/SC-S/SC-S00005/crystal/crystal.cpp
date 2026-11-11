#include <bits/stdc++.h>

#define rep(i, s, e) for(int i = s; i <= (e); ++i)
#define _rep(i, s, e) for(int i = s; i >= (e); --i)
#define fep(i, s, e) for(int i = s; i < (e); ++i)
#define _fep(i, s, e) for(int i = s; i > (e); --i)

#define int long long
#define pii pair<int, int>

using namespace std;

constexpr int inf = numeric_limits<int>::max() >> 1;
constexpr int ninf = numeric_limits<int>::min() >> 1;
constexpr int mod = 998244353;
constexpr double eps = 1e-6;

int n, k, a[500005], s[500005], ans;

inline void solve() {
	cin >> n >> k, ans = 0;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	rep(i, 1, n) {
		int l = 1, r = i, m;
		while(l <= r) {
			m = (l + r) >> 1;
			if((i - m + 1) * a[i] - (s[i] - s[m - 1]) <= k) r = m - 1;
			else l = m + 1;
		}
		ans = max(ans, i - r);
	}
	cout << ans << '\n';
	return;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}