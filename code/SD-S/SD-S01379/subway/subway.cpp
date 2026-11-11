//#include<bits\stdc++.h>
#include<bits/stdc++.h>
//using namesoace std;
using namespace std;
/*====================*/
using lnt = long long;
using pii = pair<lnt, int>;
/*====================*/
const int INF = 0x3F3F3F3F;
const lnt LNF = 0x3F3F3F3F3F3F3F3F;
/*====================*/
struct Node {
	lnt sum;
	int typ, p;
	
	friend bool operator <(const Node a, const Node b) {
		return a.sum < b.sum;
	}
};
/*====================*/
vector<vector<int>> node;
vector<unordered_map<int, int>> vec;
vector<unordered_map<int, vector<int>>> graph;
/*====================*/
lnt Dijkstra(int s, int t, int m) {
	set<pii> vis;
	priority_queue<Node> q;
	vector<unordered_map<int, lnt>> dis(m + 1);
	for (int i : node[s]) {
		q.push({ vec[s][i], i, s });
		dis[s][i] = vec[s][i];
	}
	
	while (!q.empty()) {
		Node u = q.top(); q.pop();
		if (vis.count(make_pair(u.typ, u.p))) continue;
		vis.insert(make_pair(u.typ, u.p));
		for (int i : graph[u.p][u.typ]) {
			if (!dis[i].count(u.typ) || dis[i][u.typ] > dis[u.p][u.typ]) {
				dis[i][u.typ] = dis[u.p][u.typ];
				q.push({ dis[i][u.typ], u.typ, i });
			}
		}
		for (int i : node[u.p]) {
			if (!dis[u.p].count(i) || dis[u.p][i] > dis[u.p][u.typ] + vec[u.p][u.typ] + vec[u.p][i]) {
				dis[u.p][i] = dis[u.p][u.typ] + vec[u.p][u.typ] + vec[u.p][i];
				q.push({ dis[u.p][i], i, u.p });
			}
		}
	}
	
	lnt res = LNF;
	for (int i : node[t]) 
		res = min(res, dis[t][i] + vec[t][i]);
	return res;
}

void Solve() {
	int c, n, m, d, q; 
	cin >> c >> n >> m >> d >> q;
	
	vector<int> w(m + 1);
	for (int i = 1; i <= m; i++) cin >> w[i];
	
	vec.resize(m + 1);
	node.resize(m + 1);
	graph.resize(m + 1);
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		int last = 0;
		for (int j = 1; j <= k; j++) {
			int x, t; cin >> x >> t;
			node[x].push_back(i);
			if (j > 1) {
				graph[last][i].push_back(x);
				graph[x][i].push_back(last);
			}
			vec[x][i] = t;
			last = x;
		}
	}
	
	while (q--) {
		int x, y; cin >> x >> y;
		cout << Dijkstra(x, y, m) + w[x] + w[y] << '\n';
	}
}

// int mian() {
int main() {
	//freopen("subwat.in", "r", stdin);
	//freopen("subwat.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1; //cin >> T;
	while (T--) Solve();
	return 0;
}
