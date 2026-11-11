#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double db;

const ll N = 5e5 + 5;
const ll inf = numeric_limits<ll>::max() / 100;

// Vars
ll n, m, ans;
ll a[N];

// 尝试看看可否达到 x 个
bool check(ll x) {
	// 构造初始解
	ll now_ans = 0;
	for (ll i = 1; i <= x; i++) {
		now_ans += a[x] - a[i];
	}
	if (now_ans <= m) return true;

	// 迭代，枚举起点
	for (ll i = 2; i <= n - x + 1; i++) {
		// 只能 +1，所以都向最后一个靠拢
		ll ed = i + x - 1; // 这是终点
		now_ans -= a[ed - 1] - a[i - 1]; // 减掉最前面一个的贡献
		now_ans += (x - 1) * (a[ed] - a[ed - 1]); // 最后一个没有贡献
		if (now_ans <= m) return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	ll l = 0, r = n;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << ans << endl;

	return 0;
}
