#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define F(i, n, m) for(int i = n; i <= m; i++)
#define dF(i, n, m) for(int i = n; i >= m; i--)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int const K = 1005;
int qwe, n, m, d, q;
int w[K], a[25], t[25];
int c[K];
vector<pii> g[K];

void dfs(int now, int end) {
	if(now == end) {
		return;
	}
	for(auto x:g[now]) {
		int w = x.fi, to = x.se;
		if(c[to] > c[now] + w) {
			c[to] = c[now] + w;
			dfs(to, end);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway4.in", "r", stdin);
	
	cin >> qwe >> n >> m >> d >> q;
	F(i, 1, m) {
		cin >> w[i];
	}
	F(i, 1, n) {
		int k;
		cin >> k;
		F(j, 1, k) {
			cin >> a[j] >> t[j];
		}
		F(j, 1, k) {
			F(u, 1, k) {
				g[a[j]].push_back({t[j] + t[u], a[u]});
				g[a[u]].push_back({t[j] + t[u], a[j]});
			}
		}
	}
	
	while(q--) {
		memset(c, 0x3f, sizeof(c));
		int x, y;
		cin >> x >> y;
		c[x] = 0;
		dfs(x, y);
		cout << c[y] + w[x] + w[y] << '\n';
	}
	
	return 0;
}