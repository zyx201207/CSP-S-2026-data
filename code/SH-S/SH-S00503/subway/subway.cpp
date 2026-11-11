#include <bits/stdc++.h>
#define N 1000010
using namespace std;
typedef long long ll;

ll _, m, n, nV, D, Q, W[N];
ll nE, hd[N], E[510][510];
struct edge {
	ll to, w, nxt;
} e[N * 5];
inline void add(ll u, ll v, ll w) {
	e[++nE] = {v, w, hd[u]};
	hd[u] = nE;
}
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1;
	else x = ch - '0';
	ch = getchar();
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w" ,stdout);
	
	_ = read(); m = read(); n = read(); D = read(); Q = read();
	for (int i = 1; i <= n; ++i) W[i] = read();
	nV = n + m;
	for (int i = 1; i <= m; ++i) {
		ll cT = 0; cT = read();
		for (int j = 1; j <= cT; ++j) {
			ll u, K; u = read(); K = read();
			add(u, n + i, K);
		}
	}
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j)
			if (i == j) E[i][j] = 0;
			else E[i][j] = (1ll << 60);
	for (int u = 1; u <= n; ++u) 
		for (int i = hd[u]; i; i = e[i].nxt) {
			ll v = e[i].to - n;
			for (int j = hd[u]; j; j = e[j].nxt) {
				ll _v = e[j].to - n;
				if (v == _v) continue;
				E[v][_v] = min(E[v][_v], e[i].w + e[j].w);
				E[_v][v] = min(E[_v][v], e[i].w + e[j].w);
			}
		}
	for (int k = 1; k <= m; ++k)
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= m; ++j)
				E[i][j] = min(E[i][j], E[i][k] + E[j][k]);
	//for (int i = 1; i <= m; ++i, cout << "\n")
	//	for (int j = 1; j <= m; ++j)
	//		cout << E[i][j] << " ";
	while (Q--) {
		ll st, en;
		st = read(); en = read();
		ll Ans = (1ll << 60);
		for (int i = hd[st]; i; i = e[i].nxt)
			for (int j = hd[en]; j; j = e[j].nxt) {
				ll v = e[i].to - n, _v = e[j].to - n;
				Ans = min(Ans, e[i].w + e[j].w + E[v][_v]);
			}
		cout << Ans + W[st] + W[en] << "\n";
	}
	return 0;
}
