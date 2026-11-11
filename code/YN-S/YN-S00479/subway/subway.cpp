#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int root, dis[500005];
int w[505];
bool vis[500005];

struct node {
	int u, v, w;
};

struct node2 {
	int  v, w;
};
vector<node2>ed[500005];

void sp(int st, int end) {
	for (int i = 1; i <= m; i++)
		vis[i] = 0, dis[i] = INT_MAX;

	queue<int>q;
	q.push(st);
	dis[st] = 0;
	int tmp = q.front();
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		for (int i = 0; i < ed[tmp].size(); i++) {
			int v = ed[tmp][i].v;
			int w = ed[tmp][i].w;
			if (dis[tmp] + w < dis[v]) {
				dis[v] = dis[tmp] + w;
			}
			if (vis[v] == 0) {
				q.push(v);
				vis[v] = 1;
			}

		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<int>a, t;
		for (int j = 1; j <= k; j++) {
			int x, y;
			cin >> x >> y;
			a.push_back(x);
			t.push_back(y);
		}
		for (int j = 0; j < k; j++) {
			for (int p = k - 1; p > j; p--) {
				//	cout << a[j] << " " << a[p] << endl;
				ed[a[j]].push_back({a[p], t[j] + t[p]});
				ed[a[p]].push_back({a[j], t[j] + t[p]});
			}
		}
	}
	/*
	for (int i = 1; i <= m; i++) {
		cout << endl;
		for (int j = 0; j < ed[i].size(); i++) {
			cout << i << " " << ed[i][j].v << " " << ed[i][j].w << endl;
		}

	}
	*/
	for (int i = 1; i <= q; i++) {
		int st, end;
		cin >> st >> end;
		sp(st, end);
		//	cout << dis[end] << endl;
		cout <<  dis[end] + w[st] + w[end] << endl;
	}
	return 0;
}