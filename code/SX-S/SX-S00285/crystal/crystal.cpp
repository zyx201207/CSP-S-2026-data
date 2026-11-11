#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int h[500005];
int d[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	sort(h + 1, h + 1 + n);
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + (i - 1) * (h[i] - h[i - 1]);
	}
	int o = 0;
	for (int i = n; i >= 1; i--) {
		int l = 1, r = i;
		while (l <= r) {
			int did = (l + r) / 2;
			if (d[i] - d[did] > m) {
				l = did + 1;
			} else {
				r = did - 1;
				o = max(o, i - did + 1);
			}
		}
	}
	cout << o;
	return 0;
}