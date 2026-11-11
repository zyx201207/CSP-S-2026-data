#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int C, n, m, d, q;
int w[N], a[N][N], t[N][N], k[N];

bool judge1(int s, int i) {
	for (int j = 1; j <= k[i]; j++) {
		if (a[i][j] == s) return true;
	}
	return false;
}

bool judge2(int e, int i) {
	for (int j = 1; j <= k[i]; j++) {
		if (a[i][j] == e) return true;
	}
	return false;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		int st, en;
		cin >> st >> en;
		if (judge1(st, i) && judge2(en, i)) {
			cout << w[st] + t[i][st] + t[i][en] + w[en] << '\n';
		}
	}
	return 0;
} 
