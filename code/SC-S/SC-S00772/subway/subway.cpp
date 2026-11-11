#include <bits/stdc++.h>
#define pa(a, b) make_pair(a, b)
using namespace std;
typedef long long ll;
const int N1 = 5e5 + 5, N2 = 505;
struct node {
	int idx, q;
	node(int a, int b) { idx = a, q = b; }
	friend operator < (const node &a, const node &b) {
		if (a.q == b.q) return a.idx < b.idx;
		return a.q < b.q;
	} 
};
int c, n, m, d, q;
// 分别表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
// 每个地铁站的地铁口走到站厅需要的时间 w[N1]
vector<ll> a[N2], t[N1]; 
// ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
map<pair<node, node>, ll> Gr;
pair<node, node> get(int a1, int c1, int a2, int c2) {
	return make_pair(
		node(a1, c1), node(a2, c2)
	);
}
void add(int a1, int c1, int a2, int c2, int len) {
	Gr[make_pair(
		node(a1, c1), node(a2, c2)
		)] = len;
	Gr[make_pair(
		node(a2, c2), node(a1, c1)
		)] = len;
}
void test1() {
	cerr << Gr[get(1, 1, 1, 2)] << '\n';
	cerr << Gr[get(1, 3, 2, 3)] << '\n';
}
ll spfa(int s, int e) {
	node st = node(s, 1), ed = node(e, 1);
	map<pair<node, node>, ll> dis;
	map<node, bool> f;
	queue<node> q;
	dis[pa(st, st)] = 0;
	q.push(st);
	f[st] = true;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n + 2; j++) {
				if (Gr[get(p.idx, p.q, i, j)] != 0) {
					if (dis[get(p.idx, p.q, i, j)] > dis[get(st.idx, st.q, p.idx, p.q)] + (Gr[get(p.idx, p.q, i, j)] == -1 ? 0 : Gr[get(p.idx, p.q, i, j)]) || dis[get(p.idx, p.q, i, j)] == 0) {
						dis[get(p.idx, p.q, i, j)] = dis[get(st.idx, st.q, p.idx, p.q)] + (Gr[get(p.idx, p.q, i, j)] == -1 ? 0 : Gr[get(p.idx, p.q, i, j)]);
						if (!f[node(i, j)]) {
							q.push(node(i, j));
						}
					}
				}
			}
		}
	}
	return dis[pa(st, ed)];
}
void aSolve() {
	int st, ed;
	cin >> st >> ed;
	cout << spfa(st, ed) << '\n';
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		ll nw;
		cin >> nw;
		add(i, 1, i, 2, nw);
	}
	for (int i = 1, k, la = 0; i <= n; i++) {
		cin >> k;
		for (ll j = 1, na, nt; j <= k; j++) {
			cin >> na >> nt;
			if (la != 0) add(la, 2 + i, na, 2 + i, -1);
			add(na, 2, na, 2 + i, nt);
			la = na;
		}
	}
	while (q--) {
		aSolve();
	}
}