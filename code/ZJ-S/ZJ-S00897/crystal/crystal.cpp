#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;

constexpr int MAXN = 500000 + 10;
int n; ll m;
ll a[MAXN], sum[MAXN];

ll get(int l, int r, int i) {
//	cerr << l << " " << r << " " << a[i] * (r - l + 1) - (sum[r] - sum[l - 1]) << "\n";
	return a[i] * (r - l + 1) - (sum[r] - sum[l - 1]);
}

bool _check(int k, ll cnt) {
	for(int i = 1; i <= n - k + 1; ++i) {
		int j = i + k - 1;
		if(get(i, j, j) <= cnt) return 1;
	}
	return 0;
}

bool check(int k) {
	ll l = 0, r = m;
	while(l <= r) {
		ll mid = (l + r) >> 1;
		if(_check(k, mid)) return 1;
		else l = mid + 1;
	}
	return 0;
}

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = n, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
}

int main() {
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}

