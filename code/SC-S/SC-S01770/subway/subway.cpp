#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

inline ll read() {
	ll w = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
	return f * w;
}

inline void write(ll x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x < 10) {
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
	return ;
}

const int N = 505;
const int M = 5e5 + 5;
const ll inf = 4e18;

vector <pair<ll, ll> > vec[M];

ll cos[N][N];
ll n, m, d, qu;
ll w[M];

int main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read();
	n = read(), m = read(), d = read(), qu = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i) {
		ll k = read();
		for (int j = 1; j <= k; ++j) {
			ll a = read(), t = read();
			vec[a].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) continue;
			cos[i][j] = inf;
		}
	}
	
	for (int i = 1; i <= m; ++i) {
		int siz = vec[i].size();
		for (int j = 0; j < siz; ++j) {
			ll tj = vec[i][j].second;
			for (int p = 0; p < j; ++p) {
				ll tp = vec[i][p].second;
				if (tj + tp < cos[vec[i][j].first][vec[i][p].first]) {
					cos[vec[i][j].first][vec[i][p].first] = tj + tp;
					cos[vec[i][p].first][vec[i][j].first] = tj + tp;
				}
			}
		}
	}
	
	for (int k = 1; k <= n; ++k) {
		for (int j = 1; j <= n; ++j) {
			for (int i = 1; i <= n; ++i) {
				cos[i][j] = min(cos[i][j], cos[k][j] + cos[i][k]);
			}
		}
	}
	
	while (qu--) {
		ll x = read(), y = read();
		ll res = inf;
		int s1 = vec[x].size(), s2 = vec[y].size();
		for (int i = 0; i < s1; ++i) {
			for (int j = 0; j < s2; ++j) {
				res = min(res, cos[vec[x][i].first][vec[y][j].first] + vec[x][i].second + vec[y][j].second);
			}
		}
		res += w[x] + w[y];
		write(res);
		putchar('\n');
	}
	return 0;
}