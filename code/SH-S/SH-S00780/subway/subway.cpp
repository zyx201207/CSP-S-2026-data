#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 5, M = 5e5 + 5;
int c, n, m, d, q;
long long w[M];
int t[M][N];
vector<int> has_node[M];
long long g[N][N];
long long f[N][N];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	memset(g, 0x3f3f3f3f3f3f3f3f, sizeof g);
	memset(f, 0x3f3f3f3f3f3f3f3f, sizeof f);
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j) {
			int a, tt;
			cin >> a >> tt;
			has_node[a].push_back(i);
			t[a][i] = tt;
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int line1: has_node[i]) {
			for (int line2: has_node[i]) {
				if (line1 == line2) continue;
				g[line1][line2] = g[line2][line1] = min(g[line1][line2], 1LL * t[i][line1] + 1LL * t[i][line2]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) f[i][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) f[i][j] = g[i][j];
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		int start, end;
		cin >> start >> end;
		long long minn = 1e18;
		for (int line1: has_node[start]) {
			for (int line2: has_node[end]) {
				minn = min(minn, w[start] + w[end] + f[line1][line2] + t[start][line1] + t[end][line2]);
			}
		}
		cout << minn << endl;
	}
	return 0;
}
