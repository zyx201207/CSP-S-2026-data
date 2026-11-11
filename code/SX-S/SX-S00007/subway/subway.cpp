#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, cnt, a;
long long  w[500005], b, x, y, f[5000505], p[5005][5005];

struct edge {
	long long v;
	long long w;
	long long nxt;
} e[10000005];

void build(long long u, long long v, long long w) {
	e[++cnt] = {v, w, f[u]};
	f[u] = cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway5.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(p, 0x3f3f3f3f, sizeof p);
	cin >> c >> n >> m >> d >> q;
	for (long long i = 1; i <= m; i++)
		cin >> w[i];
	for (long long i = 1; i <= n; i++) {
		p[i][i] = 0;
		long long k = 0;
		cin >> k;
		for (long long j = 1; j <= k; j++) {
			cin >> a >> b;
			build(m + i, a, b);
			build(a, m + i, b);
		}
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = f[m + i]; j > 0; j = e[j].nxt) {
			for (long long k = f[e[j].v]; k > 0; k = e[k].nxt) {
				p[i][e[k].v - m] = min(p[i][e[k].v - m], e[j].w + e[k].w);
			}
		}
	}
	for (long long k = 1; k <= n; k++) {
		for (long long i = 1; i <= n; i++) {
			for (long long j = 1; j <= n; j++) {
				p[i][j] = min(p[i][j], p[i][k] + p[j][k]);
				p[j][i] = p[i][j];
			}
		}
	}
	while (q--) {
		long long ans = 0x3f3f3f3f;
		cin >> x >> y;
		for (long long i = f[x]; i > 0; i = e[i].nxt) {
			for (long long j = f[y]; j > 0; j = e[j].nxt) {
				if (e[i].w + e[j].w + p[e[i].v - m][e[j].v - m] < ans)
					ans = e[i].w + e[j].w + p[e[i].v - m][e[j].v - m];
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	return 0;
}
