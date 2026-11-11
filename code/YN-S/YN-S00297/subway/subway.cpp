#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c, n, m, d, q;
long long lz = 1e18;
int p[550], a[N], b[N];
int r[N], f[N];
bool fl[550];

struct node {
	int v, w;
};
vector<node>o[550];

void dfs(int u, int wi, long long sum) {
	fl[u] = 1;
	if (u == wi) {
		lz = min(lz, sum);
		return;
	}
	for (auto it : o[u]) {
		int v = it.v;
		int w = it.w;
		if (fl[v] == 0) {
			dfs(v, wi, sum + w);
			fl[v] = 0;
		}
	}

}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> b[j];
		}
		for (int x = 1; x <= k; x++) {
			for (int y = 1; y <= k; y++) {
				if (x != y) {
					o[a[x]].push_back({a[y], b[x] + b[y]});
				}
			}
		}
	}
//	for (int i = 1; i <= m; i++) {
//		cout << "i:" << i << ' ' << "s:" << o[i].size() << '\n';
//		for (auto it : o[i]) {
//			int v = it.v, w = it.w;
//			cout << v << "(" << w << ")" << " ";
//		}
//		cout << '\n';
//	}
	for (int i = 1; i <= q; i++) {
		lz = 1e18;
		cin >> r[i] >> f[i];
		dfs(r[i], f[i], 0);
		cout << lz + p[r[i]] + p[f[i]] << '\n';
	}
	return 0;
}

