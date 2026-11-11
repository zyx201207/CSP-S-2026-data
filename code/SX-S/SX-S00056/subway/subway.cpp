#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

ifstream fin;
ofstream fout;
const int N = 5e5 + 500 + 10;

struct Node {
	int v, w;
	
	bool operator<(const Node& other) const {
		if (w == other.w) return v < other.v;
		return w < other.w;
	}
	bool operator>(const Node& other) const {
		if (w == other.w) return v > other.v;
		return w > other.w;
	}
};

int c, n, m, d, q;
vector<Node> g[N];
int w[N];
vector<int> dis[510];

void add(int a, int b, int w) {
	g[a].push_back({b, w});
	g[b].push_back({a, w});
}

void print() {
	int tot = n + m;
	for (int i = 1; i <= tot; ++i) {
		cout << i << ": ";
		for (Node node : g[i]) {
			cout << "(" << node.v << ", " << node.w << ") ";
		}
		cout << endl;
	}
}
void print2() {
	for (int i = 1; i <= n; ++i) {
		cout << i << ": ";
		for (int j = 1; j <= m; ++j) {
			cout << "(" << j << ", " << dis[i][j] << ") ";
		}
		cout << endl;
	}
}

int main() {
	fin.open("subway.in");
	fout.open("subway.out");
	
	fin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		fin >> w[i];
	}
	for (int i = m + 1, k, a, t; i <= n + m; ++i) {
		fin >> k;
		for (int j = 1; j <= k; ++j) {
			fin >> a >> t;
			add(i, a, t);
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		int tot = n + m;
		dis[i].assign(tot + 1, INT_MAX);
		vector<bool> st(tot + 1, 0);
		priority_queue<Node, vector<Node>, greater<Node>> q;
		q.push({i + m, 0});
		while (q.size()) {
			Node node = q.top();
			q.pop();
			int u = node.v;
			int w = node.w;
			if (dis[i][u] > w) {
				dis[i][u] = w;
			}
			st[u] = 1;
			for (Node node : g[u]) {
				if (st[node.v]) continue;
				q.push({node.v, node.w + w});
			}
		}
	}
	
//	print2();
	
	int x, y, ans;
	while (q--) {
		fin >> x >> y;
		ans = INT_MAX;
		for (int i = 1; i <= n; ++i) {
			ans = min(ans, dis[i][x] + dis[i][y]);
		}
		ans += w[x] + w[y];
		fout << ans << endl;
	}
	
	fin.close();
	fout.close();
	return 0;
}
