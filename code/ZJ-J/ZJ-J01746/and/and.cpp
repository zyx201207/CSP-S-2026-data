#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010], ans;
bool b[200010], v[200010], tag;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 30; i >= 0; i--) {
		int cnt = 0;
		memset(v, 0, sizeof(v));
		for (int j = 1; j <= n; j++)
			v[j] = !((a[j] >> i) & 1);
		for (int j = 1; j <= n; j++)
			cnt += !(b[j] | v[j]);
		if (cnt >= m)
			for (int j = 1; j <= n; j++) b[j] |= v[j];
	}
	for (int i = 1; i <= n; i++) {
		if (!b[i]) {
			if (tag) ans &= a[i];
			else {
				tag = true;
				ans = a[i];
			}
		}
	}
	cout << ans;
	return 0;
}
