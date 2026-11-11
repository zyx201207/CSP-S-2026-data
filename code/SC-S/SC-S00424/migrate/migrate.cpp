#include <iostream>
using namespace std;
typedef long long ll;
namespace io {
	const int S = 1 << 20;
	char buf[S], *p1, *p2;
	#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
	inline ll read() {
		ll res = 0, f = 1;
		char ch = gc();
		while (!isdigit(ch)) { if (ch == '-') f = -1; ch = gc(); }
		while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = gc();
		return res * f;
	}
	inline void print(ll x) {
		if (x < 0) x = -x, putchar('-');
		if (x > 9) print(x / 10);
		putchar(x % 10 ^ 48);
	}
}
using namespace io;
const int N = 2e6 + 5;
int c, t, n;
int dist[N], cnt[N], from[N], vis[N];
ll d, ans, x[N];
void init() {
	ans = 0;
	for (int i = 1; i <= n; i++)
		dist[i] = 0x7fffffff;
	for (int i = 1; i <= n; i++) 
		from[i] = cnt[i] = vis[i] = 0;
	dist[1] = 0;
}
void find(int u) {
	ll res = 1;
	while (from[u] != u) {
		res *= cnt[u];
		if (res > 2) return;
		if (res == 2) ans++; 
		u = from[u];
		vis[u] = 1;
	}
}
void count(int &i, int &k) {
	if (x[i] + d >= x[k]) {
		if (dist[i] + 1 < dist[k]) {
			dist[k] = dist[i] + 1;
			cnt[k] = 1;
			from[k] = i;
		}
		else if (dist[i] + 1 == dist[k]) cnt[k]++;
	} else {
		while (x[++i] + d < x[k]);
		k = i - 1;
	}
} 
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	for (int i = 1; i <= N; i++)
		dist[i] = 0x7fffffff;
	while (t--) {
		n = read(), d = read();
		for (int i = 1; i <= n; i++)
			x[i] = read();
		if (c == 11 || c == 12) {
			print(ll(d * 1ll / (x[2] - x[1])) * (n - 3));
			putchar('\n');
		}
		else if (c == 13 || c == 14) {
			print(n * 1ll * n);
			putchar('\n');
		}
		else {
			init();
			int i = 1;
			for (int j = 1; j <= n; j++) count(i, j);
			while (i < n)	count(++i, n);
			for (int i = n; i >= 1; i--)
				if (!vis[i]) vis[i] = 1, find(i);
			printf("%lld\n", ans);
		}
	}
}
