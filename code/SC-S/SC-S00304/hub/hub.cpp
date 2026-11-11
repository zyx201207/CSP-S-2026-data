#include <bits/stdc++.h>
using ll = long long; using std::vector;
const int SZ = 1 << 16;
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

const int SN = 20, N = 1e5 + 5;
int cid, n, k, ans, dist[SN][SN], p, sz[N], h[N];
vector <int> tr[N];
bool flag[SN];

void dfs(int step, int chse, int cnt) {
	if (step > n) {
		int cur = 0;
		fu (i, 1, n) {
			int mind = 2e9;
			fu (j, 1, n) if (flag[j]) fmin(mind, dist[i][j]);
			fmax(cur, mind);
		} fmin(ans, cur);
		return ;
	}
	
	if (n - step + 1 > k - chse) dfs(step + 1, chse, cnt);
	if (chse < k) {
		bool own = true;
		fu (i, 1, n) if (dist[step][i] == 1) own &= !flag[i];
		if (cnt + own <= 2) flag[step] = true, dfs(step + 1, chse + 1, cnt + own);
		flag[step] = false;
	}
}
I void TaskBF() {
	memset(dist, 0x3f, sizeof dist);
	fu (i, 1, n) dist[i][i] = 0;
	fr (i, 1, n) {
		int u, v; read(u), read(v);
		dist[u][v] = dist[v][u] = 1;
	}
	fu (k, 1, n) fu (i, 1, n) fu (j, 1, n) fmin(dist[i][j], dist[i][k] + dist[k][j]);

	ans = 2e9; dfs(1, 0, 0);
	Write(ans);
}
void Find_Center(int u, int fat) {
	sz[u] = 1; int maxs = 0;
	for (auto v : tr[u]) if (v != fat) {
		Find_Center(v, u); sz[u] += sz[v]; fmax(maxs, sz[v]);
	} fmax(maxs, n - sz[u]);
	if (maxs <= (n >> 1)) p = u;
}
void Get_Hight(int u, int fat) {
	for (auto v : tr[u]) if (v != fat) {
		Get_Hight(v, u); fmax(h[u], h[v]);
	} ++ h[u];
}
I void solve() {
	read(n), read(k);
	if (cid <= 3) TaskBF();
	else if (k == 2) {
		fu (i, 1, n) tr[i].clear();
		fr (i, 1, n) {
			int u, v; read(u), read(v);
			tr[u].emplace_back(v); tr[v].emplace_back(u);
		}

		Find_Center(1, -1); int maxh = 0, tmaxh = 0;
		for (auto v : tr[p]) {
			Get_Hight(v, p); int hei = h[v];
			fmax(tmaxh, hei);
			if (tmaxh > maxh) std::swap(tmaxh, maxh);
		}
		int len = maxh + tmaxh + 1;
		Write(len / 3);
	}
}

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int T; read(cid), read(T);
	while (T --) solve();
    return Flush(), 0;
}