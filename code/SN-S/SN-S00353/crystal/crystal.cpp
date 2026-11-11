#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
bool BE;
int n, m, a[N], s[N];
bool ED;


bool check(int l, int r) {
	int w = (r - l + 1) * a[r] - (s[r] - s[l - 1]);
	return w <= m;
}


signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr << ((&ED - &BE) >> 20) << "Mib\n";
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for (int r = 1; r <= n; r++) {
		int l = r;
		for (int i = 1 << 20; i; i >>= 1) {
			if (l - i < 1) continue;
			if (check(l - i, r)) l -= i;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}

