#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define rep(i, j, k) for (int i = (j); i <= (k); ++i)
#define per(i, j, k) for (int i = (j); i >= (k); --i)
#define smax(a, b) (a = max(a, (b)))
#define smin(a, b) (a = min(a, (b)))
using namespace std;
// using namespace __gnu_pbds;

const int N = 5e5 + 7;
int n, m, a[N];
int s[N];

inline int calc(int l, int r) {
	int c = r - l, sum = s[r - 1] - s[l - 1];
	return c * a[r] - sum;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) s[i] = s[i - 1] + a[i];
	int r = 1, ans = 1;
	rep(l, 1, n) {
		smax(r, l);
		while (calc(l, r + 1) <= m && r < n) ++r;
		// if (l == 1) cout << calc(l, r) << '\n';
		smax(ans, r - l + 1);
	}
	cout << ans << '\n';

	return 0;
}