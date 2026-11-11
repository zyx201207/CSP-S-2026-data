#include<bits/stdc++.h>
#define LoveFurina ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define F(x, l, r) for(int x = l; x <= r; ++x)
#define B(x, r, l) for(int x = r; x >= l; --x)
#define ll long long
#define pii pair<int, int>
#define st first
#define nd second
using namespace std;

const int N = 510;
const int M = 5e5 + 10;
const ll INF = 1e18;

int c, n, m, d, q;
ll w[M];

struct Node {
	int v; ll r;
};
vector<Node> adj[N + M];
int mx[M];

ll tmp[N + M], dis[N][N];
struct Heap {
	int u; ll d;
	inline bool operator < (const Heap &rhs) const {
		return d > rhs.d;
	} 
};
priority_queue<Heap> pq;

inline void dijkstra(int s) {
	F (i, 1, m) tmp[i] = INF;
	F (i, m + 1, s - 1) {
		tmp[i] = dis[i - m][s - m];
		pq.push({i, tmp[i]});
	}
	F (i, s + 1, m + n) tmp[i] = INF;
	tmp[s] = 0; pq.push({s, 0});
	while (!pq.empty()) {
		Heap h = pq.top(); pq.pop();
		int &u = h.u; ll &d = h.d;
		if (d != tmp[u]) continue;
		for (auto &e : adj[u]) {
			int &v = e.v; ll &r = e.r;
			if (v <= m && mx[v] <= s) continue;
			if (tmp[v] > tmp[u] + r) {
				tmp[v] = tmp[u] + r;
				pq.push({v, tmp[v]});
			}
		}
	}
	F (i, m + 1, m + n) dis[s - m][i - m] = tmp[i]; 
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	LoveFurina;
	
	cin >> c >> n >> m >> d >> q;
	F (i, 1, m) cin >> w[i];
	F (i, 1, n) {
		int k; cin >> k;
		F (j, 1, k) {
			int a; ll t; cin >> a >> t;
			mx[a] = max(mx[a], m + i);
			adj[a].push_back({m + i, t});
			adj[m + i].push_back({a, t});
		}
	}
	
	F (i, 1, n) F (j, 1, n) dis[i][j] = INF;
	F (i, m + 1, m + n) dijkstra(i);
	
	while (q--) {
		int x, y; cin >> x >> y; ll ans = INF;
		for (auto &a : adj[x]) for (auto &b : adj[y]) 
			ans = min(ans, w[x] + w[y] + a.r + b.r + dis[a.v - m][b.v - m]);
		cout << ans << '\n';
	}
	
return 0;
}
// 关注 luogu @DanseSolo 谢谢 awa 