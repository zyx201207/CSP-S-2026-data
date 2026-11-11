#include <bits/stdc++.h>
#define N 500010
using namespace std;
typedef long long ll;

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

ll _, n, K, nE, hd[N], f[N], bx[N];
ll dis[N], vis[N];
struct edge {
	ll to, nxt;
} e[N + N];
inline void add(ll u, ll v) {
	e[++nE] = {v, hd[u]};
	hd[u] = nE;
}
inline ll find(ll x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w" ,stdout);
	
	_ = read(); _ = read();
	while (_--) {
		n = read(); K = read();
		nE = 0;
		for (int i = 1; i <= n; ++i) hd[i] = 0;
		for (int i = 1; i <= n - 1; ++i) {
			ll u = read(), v = read();
			add(u, v); add(v, u);
		}
		if (n > 20) continue;
		ll nPtn = (1ll << n) - 1, res = (1ll << 56);
		for (int p = 0; p <= nPtn; ++p) { 
			ll u = __builtin_popcount(p);
			if (u != K) continue;
			for (int i = 1; i <= n; ++i) dis[i] = (1ll << 56), vis[i] = 0;
			queue <ll> q;
			for (int i = 1; i <= n; ++i)
				if (p & (1 << i - 1)) dis[i] = 0, vis[i] = 1, q.push(i);
			ll ans = 0;
			for (int i = 1; i <= n; ++i) f[i] = i, bx[i] = 0;
			for (int u = 1; u <= n; ++u) {
				for (int i = hd[u]; i; i = e[i].nxt)
					if (vis[u] && vis[e[i].to]) f[find(u)] = find(e[i].to);
			}
			ll cT = 0;
//			cout << flush;
			for (int i = 1; i <= n; ++i) {
				if (!vis[i]) continue;
//				cout << find(i) << " " << bx[find(i)] << "------------------------\n";
				if (vis[i] && bx[find(i)] == 0) ++cT;
				bx[find(i)] = 1;
//				cout << find(i) << " " << bx[find(i)] << "------------------------\n";
			}
				
//			cout << cT << "\n";
			if (cT > 2) continue;
//			cout << "4328539342";
			while (!q.empty()) {
				ll u = q.front(); q.pop();
//				cout << u << " " << dis[u] << "-\n"; 
				for (int i = hd[u]; i; i = e[i].nxt) {
					ll v = e[i].to;
					if (vis[v]) continue;
					dis[v] = dis[u] + 1; vis[v] = 1;
					q.push(v);
				}
			}
			for (int i = 1; i <= n; ++i) ans = max(dis[i], ans);
			res = min(res, ans);
//			if (ans == 1) cout << "-------------------------------" << p << "\n";
//			cout << "---------\n";
		}
		cout << res << "\n";
	}
	
	return 0;
}
