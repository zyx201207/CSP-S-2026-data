#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second

using namespace std;

char *p1, *p2, buf[1 << 20];
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)

template <typename T> void read(T &x) {
	x = 0; T f = 1; char c = gc();
	while(c < '0' || '9' < c) f = (c == '-') ? -1 : 1, c = gc();
	while('0' <= c && c <= '9') x = x * 10 + (c & 15), c = gc();
	x *= f;
}

template <typename T> void write(T x) {
	if(x < 0) putchar('-'), x = -x;
	static short st[25], top(0);
	do st[++top] = x % 10; while(x /= 10);
	while(top) putchar(st[top--] | 48);
	putchar('\n');
}

const int maxn = 505, maxm = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q, w[maxm];
vector<pii> s[maxm];
ll dis[maxn][maxn];

struct line {
	int k;
	vector<int> a, t;
} l[maxn];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(c), read(n), read(m), read(d), read(q);
	for(int i = 1; i <= m; i++) read(w[i]);
	for(int i = 1; i <= n; i++) {
		read(l[i].k);
		for(int j = 1; j <= l[i].k; j++) {
			int a, t; read(a), read(t);
			l[i].a.eb(a), l[i].t.eb(t);
			s[a].eb(MP(i, t));
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) dis[i][j] = inf;
	for(int i = 1; i <= m; i++) {
		for(pii j : s[i]) {
			for(pii k : s[i]) {
				ll val = min(dis[j.fi][k.fi], (ll)j.se + k.se);
				dis[j.fi][k.fi] = dis[k.fi][j.fi] = val;
			}
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	int u, v;
	while(q--) {
		read(u), read(v);
		ll res = inf;
		for(pii i : s[u])
			for(pii j : s[v])
				res = min(res, dis[i.fi][j.fi] + i.se + j.se);
		write(res + w[u] + w[v]);
	}
	return 0;
}