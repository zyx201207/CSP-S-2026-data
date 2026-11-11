#include <bits/stdc++.h>
using std::cin; using std::cout;
using std::max; using std::min;
using ll = long long;
#define rep(x, a, b) for (int x = (a); x <= (b); ++x)
constexpr int MAXN = 5e5 + 10;
constexpr ll MAXM = 1e18;
ll a[MAXN], s[MAXN];
int n; ll m;
ll Get(int l, int r) { return s[r] - s[l - 1]; }
int ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	std::sort(a + 1, a + n + 1, [](ll a, ll b) {
		return a > b;
	});
//	rep (i, 1, n) cout << a[i] << ' ';// ------------------------------
//	cout << '\n'; // -------------------
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	rep(i, 1, n) {
		ll goal = a[i];
		int l = i, r = n, res = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if ((mid - i + 1) * goal - Get(i, mid) <= m) {
				res = mid;
				l = mid + 1;
			}
			else { r = mid - 1; }
		}
		ans = std::max(ans, res - i + 1);
	}
	cout << ans;
	return 0;
}