//SN-S00454  杨建傲措  陕西省西安爱知中学
#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;
bool vl[505];
struct node {
	int l, j;
	map <int, int> m;
} w[500005];

int bfs(int u, int v) {
	queue <int> qe;
	qe.push(u);
	for(auto o : w[u].m) {
		vl[o.second] = 0;
	}
	while(!qe.empty()) {
		int x = qe.front();
		qe.pop();
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i].j;
	for(int i = 1; i <= n; i++) {
		int k, x, v;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> x >> v;
			w[x].m[k] = v;
		}
	}
	while(q--) {
		int u, v;
		cin >> u >> v;
		cout << bfs(u, v);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
