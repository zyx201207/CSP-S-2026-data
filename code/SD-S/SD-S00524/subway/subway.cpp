#include <bits/stdc++.h>
using namespace std;

template<typename T>
inline void read(T &x) {
	x = 0;
	bool f = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = 1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	if (f) {
		x = -x;
	}
}
template<typename T>
inline void write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 | 48);
}
template<typename T>
inline void writeln(T x) {
	write(x);
	putchar('\n');
}

const long long N = 2e5 + 10;
long long c, n, m, d, q;
long long w[N];
long long cnt, h[N], to[N], nxt[N], val[N];
void add(long long u, long long v, long long w) {
	to[++cnt] = v;
	val[cnt] = w;
	nxt[cnt] = h[u];
	h[u] = cnt;
}
long long dis[N];
bool vis[N];
long long dijkstra(long long x, long long y) {
	for (long long i = 1; i <= n + m; ++i) {
		dis[i] = 0x3f3f3f3f3f3f3f3f;
		vis[i] = 0;
	}
	priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
	q.push({0, x});
	dis[x] = 0;
	while (!q.empty()) {
		pair<long long, long long> p = q.top();
		q.pop();
		long long w = p.first, u = p.second;
		if (vis[u]) {
			continue;
		}
		if (u == y) {
			return dis[u];
		}
		vis[u] = 1;
		for (long long i = h[u]; i; i = nxt[i]) {
			if (dis[u] + val[i] < dis[to[i]]) {
				dis[to[i]] = dis[u] + val[i];
				q.push({dis[to[i]], to[i]});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	read(c), read(n), read(m), read(d), read(q);
	for (long long i = 1; i <= m; ++i) {
		read(w[i]);
	}
	for (long long i = 1; i <= n; ++i) {
		long long k, a, t;
		read(k);
		for (long long j = 1; j <= k; ++j) {
			read(a), read(t);
			add(a, m + i, t);
			add(m + i, a, t);
		}
	}
	for (long long i = 1; i <= q; ++i) {
		long long x, y;
		read(x), read(y);
		writeln(dijkstra(x, y) + w[x] + w[y]);
	}
	
	return 0;
}
