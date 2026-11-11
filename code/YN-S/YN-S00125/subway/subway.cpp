#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
int c, n, m, d, q;
int w[N], t[N][N];
vector<int> a[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, s; j <= k; j++) {
			cin >> s;
			cin >> t[i][s];
			a[i].push_back(s);
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
	}
	return 0;
}