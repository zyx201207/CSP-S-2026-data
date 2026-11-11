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

int n, d, a[2000005], lft[2000005], rgt[2000005], lcnt[2000005], rcnt[2000005], lval[2000005], rval[2000005], ans;
vector<int> v1, v2;

inline void solve() {
	cin >> n >> d, ans = 0;
	rep(i, 1, n) cin >> a[i];
	lft[1] = 1;
	rep(i, 2, n) {
		lft[i] = lft[i - 1];
		while(a[i] - a[lft[i]] > d) ++lft[i];
	}
	rgt[n] = n;
	_rep(i, n - 1, 1) {
		rgt[i] = rgt[i + 1];
		while(a[rgt[i]] - a[i] > d) --rgt[i];
	}
	if(n <= 300) {
		rep(i, 1, n) rep(j, i + 1, n) {
			bool flag = 0;
			v1.clear(), v2.clear();
			int x = i;
			while(x < j) {
				v1.push_back(x);
				if(x == rgt[x]) {
					flag = 1;
					break;
				}
				x = rgt[x];
			}
			v1.push_back(j);
			x = j;
			while(x > i) {
				v2.push_back(x);
				if(x == lft[x]) {
					flag = 1;
					break;
				}
				x = lft[x];
			}
			v2.push_back(i);
			if(flag) continue;
			reverse(v2.begin(), v2.end());
			int tot = 0;
			fep(i, 0, (int)v1.size()) {
				tot += abs(v1[i] - v2[i]);
			}
			ans += tot == 1;
		}
		cout << ans << '\n';
		return;
	}
	rep(i, 1, n) lcnt[i] = rcnt[i] = lval[i] = rval[i] = 0;
	rep(i, 1, n) {
		++lcnt[i];
		if(i < rgt[i] and lft[rgt[i]] <= i) {
			if(lft[rgt[i]] == i) lcnt[rgt[i]] += lcnt[i];
			else ++lcnt[rgt[i]];
			if(rgt[i] > 1 and lft[rgt[i] - 1] <= i) ++lval[rgt[i]];
		}
	}
	_rep(i, n, 1) {
		++rcnt[i];
		if(i > lft[i] and rgt[lft[i]] >= i) {
			if(rgt[lft[i]] == i) rcnt[lft[i]] += rcnt[i];
			else ++rcnt[lft[i]];
			if(lft[i] < n and rgt[lft[i] + 1] >= i) ++rval[lft[i]];
		}
	}
	rep(i, 2, n) {
		int l = max(lft[i - 1], lft[i]), r = min(rgt[i - 1], rgt[i]);
		if(not (l < i - 1 and i < r)) continue;
		int u = 0, v = 0;
		if(lft[i - 1] == lft[i]) u = lcnt[i] - 1;
		else u = lval[i];
		if(rgt[i - 1] == rgt[i]) v = rcnt[i - 1] - 1;
		else v = rval[i - 1];
		ans += u * v;
	}
	cout << ans << '\n';
	return;
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1; cin >> T >> T;
	while(T--) solve();
	return 0;
}