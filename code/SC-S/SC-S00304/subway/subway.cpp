#include <bits/stdc++.h>
using ll = long long;
const int SZ = 1 << 16, TN = 2e6, LG = 21, SN = 4005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
#define fu(i, a, b) for (auto i = a; i <= b; ++i) 
#define fd(i, a, b) for (auto i = a; i >= b; --i) 
#define fr(i, a, b) for (auto i = a; i < b; ++i) 
#define I inline 
char buf[SZ], cuf[SZ];
int is = SZ, os;
I char ge() { return !(is ^ SZ) && (fread(buf, 1, SZ, stdin), is = 0), buf[is ++]; } 
I bool Flush() { return fwrite(cuf, 1, os, stdout), os = 0; } 
I void pu(char c) { !(os ^ SZ) && Flush(), cuf[os ++] = c;  } 
template <typename T> I void read(T &x) { 
    char c = ge(); bool f = false; x = 0;
    while (c < '0' || '9' < c) f = c == '-', c = ge();
    while ('0' <= c && c <= '9') x = x * 10 + (c ^ 48), c = ge();
    f && (x = -x);
} 
template <typename T> I void write(T x) {
    char tmp[25]; int l = 0;
    if (x == 0) { pu('0'); return ; }
    if (x < 0) x = -x, pu('-');
    while (x) tmp[l ++] = x % 10 + '0', x /= 10;
    while (l) pu(tmp[-- l]);
}
template <typename T> I void Write(T x, bool f = true) { write(x); pu(f ? '\n' : ' '); }
template <typename T> I T max(T a, T b) { return a > b ? a : b; }
template <typename T> I T min(T a, T b) { return a < b ? a : b; }
template <typename T> I void fmax(T &a, T b) { a = a > b ? a : b; }
template <typename T> I void fmin(T &a, T b) { a = a < b ? a : b; }

int n, head[TN], totm, depth[TN], biao, jump[TN][LG], tn, m, D, Q;
ll dist[TN], d[SN][SN];

struct pq { 
	int u; ll d;
	bool operator<(const pq &oth) const { return d > oth.d; }
};
struct Edge { int to, nxt; ll w; }eg[TN << 1];
I void Add_Edge(int u, int v, ll w) { eg[++ totm] = {v, head[u], w}; head[u] = totm; }
I void Add(int u, int v, ll w) { Add_Edge(u, v, w); Add_Edge(v, u, w); }
I void Clear_Map(int sz) { fu (i, 0, sz) head[i] = -1; totm = -1; }

void init(int u, int fat) {
	depth[u] = depth[fat] + 1, jump[u][0] = fat;
	fr (j, 1, LG) jump[u][j] = jump[jump[u][j - 1]][j - 1];
	
	for (int it = head[u]; ~it; it = eg[it].nxt) {
		int v = eg[it].to; ll w = eg[it].w;
		if (v == fat) continue ;
		dist[v] = dist[u] + w; init(v, u);
	}
}
I int Get_Lca(int u, int v) {
	if (depth[u] < depth[v]) std::swap(u, v);
	
	fd (i, LG - 1, 0) if (depth[jump[u][i]] >= depth[v]) u = jump[u][i];
	if (u == v) return u;
	
	fd (i, LG - 1, 0) if (jump[u][i] != jump[v][i]) {
		u = jump[u][i];
		v = jump[v][i];
	} return jump[u][0];
}

I void Dijkstra(int st, ll *di) {
	std::priority_queue <pq> q;
	di[st] = 0; q.emplace((pq){st, 0});

	while (!q.empty()) {
		pq t = q.top(); q.pop();
		int u = t.u; ll dis = t.d;
		if (dis != di[u]) continue ;
		
		for (int it = head[u]; ~it; it = eg[it].nxt) {
			int v = eg[it].to; ll w = eg[it].w;
			if (di[v] > dis + w) {
				di[v] = dis + w;
				q.emplace((pq){v, di[v]});
			}
		} 
	}
}
I void Make_Dist() {
	fu (i, 1, biao) {
		int u = (i << 1) - 1;
		fu (j, 1, n) d[u][j] = INF;
		Dijkstra(u, d[u]);
	}
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int cid; read(cid), read(m), read(n), read(D), read(Q);
    Clear_Map(TN - 1);
	fu (i, 1, n) {
    	ll t; read(t);
    	Add((i << 1) - 1, i << 1, t);
	} biao = n; n <<= 1;
	while (m --) {
		int k; read(k); ++ n;
		while (k --) {
			int nd; ll t; read(nd), read(t);
			Add(nd << 1, n, t);
		}
	}

	if (n <= 4000) Make_Dist();
	else init(1, 0);
	while (Q --) {
		int u, v; read(u), read(v);
		u = (u << 1) - 1, v = (v << 1) - 1;
		if (n <= 4000) Write(d[u][v]);
		else { int lca = Get_Lca(u, v); Write(dist[u] + dist[v] - (dist[lca] << 1)); }
	}
    return Flush(), 0;
}