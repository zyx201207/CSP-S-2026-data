#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
namespace IO {
const int SIZ = 1 << 20;
char buf[SIZ], *nw, *ed;
inline char getchar() {
	if (nw == ed) ed = buf + fread(buf, sizeof(char), SIZ, stdin), nw = buf;
	return *(nw++);
}
template<typename T> void read(T &x) {
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	}
	x *= f;
}
template<typename T, typename ...Args> void read(T &x, Args &...args) {
	read(x), read(args...);
}
}
using IO::read;
using ll = long long;
using pii = pair<ll, ll>;
const int M = 5e5 + 10, N = 600;
ll w[M], dis[N][N];
vector<pii> res[M];
//再卡常我杀了你 
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	read(c, n, m, d, q);
	for (int i = 1; i <= m; i++) read(w[i]);
	for (int i = 1; i <= n; i++) {
		int k;
		read(k);
		for (int j = 1; j <= k; j++) {
			ll a, t;
			read(a, t);
			res[a].push_back(make_pair(i, t));
		}
	}
	memset(dis, 0x3f, sizeof (dis));
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (auto px : res[i]) {
			ll x = px.first, dx = px.second;
			for (auto py : res[i]) {
				ll y = py.first, dy = py.second;
				dis[x][y] = min(dis[x][y], dx + dy);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--) {
		int u, v;
		read(u, v);
		ll ans = 4e18;
		for (auto px : res[u]) {
			ll x = px.first, dx = px.second;
			for (auto py : res[v]) {
				ll y = py.first, dy = py.second;
				ans = min(ans, dis[x][y] + dx + dy);
			}
		}
		cout << ans + w[u] + w[v] << "\n";
	}
}
