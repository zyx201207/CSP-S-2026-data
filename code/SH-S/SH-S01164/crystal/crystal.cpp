#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
using namespace std;
const int N = 500005;
int n, m, a[N], s[N], ans;
int cmp(int xxx, int yyy) { return xxx > yyy; }
void solve() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	rep(i, 1, n) {
		int l = i + 1; int r = n;
		while(l <= r) {
//			cout << i << ':' << '\n';
			int mid = (l + r) >> 1;
			int cur = (mid - i + 1) * a[i] - (s[mid] - s[i - 1]);
//			cout << l << ' ' << r << ' ' << cur << '\n';
			if(cur <= m) l = mid + 1;
			if(cur > m) r = mid - 1;
//			cout << l << ' ' << r << ' ' << cur << '\n';
		}
		ans = max(ans, r - i + 1);
		if(r == n) break;
	}
	cout << ans << '\n';
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
} 
