#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
using ll = long long;

int n; ll m;
ll w[N];

bool chk(int x) {
	ll s = 0;
	for (int i = 1; i <= x; i ++ ) s += w[x] - w[i];
	if (s <= m) return 1;
	for (int i = x + 1; i <= n; i ++ ) {
		s -= (w[i - 1] - w[i - x]);
		s += 1ll * (x - 1) * (w[i] - w[i - 1]);
		if (s <= m) return 1;
	} return 0;
}

int main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> w[i];
	sort(w + 1, w + 1 + n);
	ll l = 1, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (chk(mid)) l = mid;
		else r = mid - 1;
	} cout << l << '\n'; return 0;
}
