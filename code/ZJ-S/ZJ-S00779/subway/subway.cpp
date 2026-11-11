#include <bits/stdc++.h>
#define int long long
#define mk(A, B) make_pair(A, B)
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return f * x;
}
typedef pair<int, int> PII;
const int N = 505, M = 5e5 + 5, inf = 1e18;
int cc, n, m, d, q;
vector<int> e[N];
map<PII, int> mp1, mp2;
vector<int> p[M];
int w[M], k[N];
int vis[N];
int find(int s, int now, int t) {
	if (now == t) return 0;
	int res = inf;
	for (int i = 0; i < p[now].size(); ++i) {
		int line = p[now][i];
		if (vis[line]) continue;
		vis[line] = 1;
		for (int j = 0; j < e[line].size(); ++j)
			res = min(res, mp1[mk(now, line)] + mp2[mk(line, e[line][j])]
				+ find(s, e[line][j], t));
		vis[line] = 0;	
	}
	return res;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cc = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i) {
		k[i] = read();
		for (int j = 1; j <= k[i]; ++j) {
			int a = read(), t = read();
			p[a].push_back(i), e[i].push_back(a), 
				mp1[mk(a, i)] = mp2[mk(i, a)] = t;
		}
	}
	while (q --) {
		int s = read(), t = read();
		int x = find(s, s, t);
		printf("%lld\n", x + w[s] + w[t]);
	}
	return 0;
}
