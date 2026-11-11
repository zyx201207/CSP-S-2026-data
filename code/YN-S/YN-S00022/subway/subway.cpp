#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k;
int w[500005], x[100005], y[100005];
int v1, vj, vt, vm[500005][505], line[505][505], vs, p[505];
vector<int>v[500005];

void dfs(int z) {
	for (int i = 1; i <= n; i++) {
		if (line[z][i] != 1000000003 && p[z] + line[z][i] < p[i]) {
			p[i] = p[z] + line[z][i];
			dfs(i);
		}
	}
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			line[i][j] = 1000000003;
		}
	}
	for (int i = 1; i <= 500004; i++) {
		v[i].push_back(0);
	}
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> v1;
		for (int j = 1; j <= v1; j++) {
			cin >> vj >> vt;
			v[vj][0]++;
			v[vj].push_back(i);
			vm[vj][i] = vt;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i <= m; i++) {
		vs = v[i][0];
		for (int j = 1; j <= vs - 1; j++) {
			for (int k = j + 1; k <= vs; k++) {
				line[v[i][j]][v[i][k]] = min(line[v[i][j]][v[i][k]], vm[i][v[i][j]] + vm[i][v[i][k]]);
				line[v[i][k]][v[i][j]] = line[v[i][j]][v[i][k]];
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		for (int j = 1; j <= n; j++) {
			p[j] = 1000000003;
		}
		k = 1000000003;
		for (int j = 1; j <= n; j++) {
			if (vm[x[i]][j] ) {
				p[j] = 0;
				dfs(j);
				for (int r = 1; r <= n; r++) {
					if (vm[y[i]][r] != 0 && (p[r] || vm[x[i]][r])) {
						k = min(k, p[r] + vm[y[i]][r] + vm[x[i]][j]);
					}
				}
			}
		}
		cout << w[x[i]] + k + w[y[i]] << endl;
	}
	return 0;
}