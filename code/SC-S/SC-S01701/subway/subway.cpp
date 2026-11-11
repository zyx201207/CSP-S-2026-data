#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], a[500005], t[500005];
vector<pair<int, int> > edge[500005];
queue<int> qu;
int dl[500005], vis[500005];
void spfa(int n, int s) {
	for (int i = 1; i <= n; i++) {
		dl[i] = 0x3f;
	}
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	vis[s] = 1;
	dl[s] = 0;
	while (qu.size()) {
		int x = qu.front();
		qu.pop();
		vis[x] = 0;
		for (auto a : edge[x]) {
			int y = a.first, wl = a.second;
			if (dl[y] > dl[x] + wl) {
				dl[y] = dl[x] + wl;
				if (!vis[y]) {
					qu.push(y);
					vis[y] = 1;
				}
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
			edge[a[j - 1]].push_back(a[j], 0);
			edge[a[j]].push_back(a[j - 1], 0);
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		spfa(n, x);
		cout << d[y];
	}
	return 0;
}