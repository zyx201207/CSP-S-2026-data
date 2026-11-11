#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, w[N], mp[1001][1001];

struct node {
	int a, t;
} v[500][1000];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> v[i][j].a >> v[i][j].t;
		for (int j = 1; j <= k; j++)
			for (int o = j + 1; o <= k; o++)
				if (mp[v[i][j].a][v[i][o].a] != 0)
					mp[v[i][j].a][v[i][o].a] = mp[v[i][o].a][v[i][j].a] = min(mp[v[i][j].a][v[i][o].a],
					                           w[v[i][j].a] + w[v[i][j].a] + v[i][j].t + v[i][o].t);
				else
					mp[v[i][j].a][v[i][j].a] = mp[v[i][o].a][v[i][j].a] = w[v[i][j].a] + w[v[i][o].a] + v[i][j].t + v[i][o].t;
	}
	while (q--) {
		int s, e;
		cin >> s >> e;
		if (mp[s][e] != 0) {
			cout << mp[s][e] << "\n";
			continue;
		}
	}
	return 0;
}