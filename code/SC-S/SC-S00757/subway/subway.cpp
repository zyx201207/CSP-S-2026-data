#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
const ll inf = 1e18;
inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
struct Edge {
	int id, to;
};
struct Node {
	int dis, u;
	bool operator>(const Node &t)const {
		return dis < t.dis;
	}
};
vector<Edge> e[N];
int c, n, m, d, q;
int w[N], k[N], a[N], t[510][N];
int dis[N], ans;
bool vis[N];
inline void dijsktra(int s, int t, int idk) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	priority_queue<Node, vector<Node>, greater<Node>> q;
	q.push({0, s});
	while (!q.empty()) {
		auto to = q.top();
		q.pop();
		if (vis[to.u])continue;
		vis[to.u] = 1;
		for (auto v : e[to.u]) {

		}
	}
}
signed main() {
//	freopen("crystal3.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; i++)w[i] = read();
	for (int i = 1; i <= n; i++) {
		k[i] = read();
		for (int j = 1; j <= k[i]; j++) {
			a[j] = read(), t[i][j] = read();
			if (j >= 2)e[a[j - 1]].push_back({i, a[j]});
		}
		while (q--) {
			int x = read(), y = read();
			ans = w[x];
			cout << 0 << endl;
		}
	}
	return 0;
}