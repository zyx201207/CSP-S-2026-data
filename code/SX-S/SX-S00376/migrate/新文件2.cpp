#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
	int to, w;
	bool operator<(const Node &b) const {
		return w > b.w;
	}
};

const int N = 5e5+9;
vector<Node>v[N];
ll dis1[N], ans;
int n, m;
ll w[N], a[509][N], t[509][N], k[N];

void dijkstra(int s, int e) {
	memset(dis1, 0x3f, sizeof(dis1));
	priority_queue<Node>q;
	q.push({s, 0});
	dis1[1] = 0;
	while (!q.empty()) {
		Node u = q.top();
		q.pop();
		if (u.w > dis1[u.to])
			continue;
		for (auto x : v[u.to]) {
			if (u.w + x.w < dis1[x.to]) {
				dis1[x.to] = u.w + x.w;
				q.push({x.to, dis1[x.to]});
			}
		}
	}
	cout << dis1[e] + w[s] + w[e] << '\n';
}

signed main() {
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int ID, n, m, d, T;
	cin >> ID >> n >> m >> d >> T;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
			cin >> a[i][j] >> t[i][j];
	}
	int s = t[1][1];
	bool t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (s != t[i][j]) {
				t = 1;
				break;
			}
		}
	}
	if (t == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i]; j++) {
				v[a[i][j]].push_back({a[i][j + 1], t[1][1]});
			}
		}
		while (T--) {
			int x, y;
			cin >> x >> y;
			dijkstra(x, y);
		}
		return 0;
	}
	return 0;
}