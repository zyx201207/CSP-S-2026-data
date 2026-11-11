#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <iomanip>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;
const ll INF = 1e18 + 5;
const int MOD = 1e9 + 7;

int c, n, m, d, q;
int K[MAXN];
ll W[MAXN];
struct Node {
	int v; ll w;
};
vector<Node> Line[MAXN];
ll F[505][505];

void Floyd() {
	for(int k = 1; k <= n; k ++) {
		for(int u = 1; u <= n; u ++) {
			for(int v = 1; v <= n; v ++) {
				if(u == v) continue ;
				if(F[u][k] == INF || F[k][v] == INF) continue ;
				F[u][v] = min(F[u][v], F[u][k] + F[k][v]);
			}
		}
	}
	return ;
}

int main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> W[i];
	for(int i = 1; i <= n; i ++) for(int j = 1; j <= n; j ++) F[i][j] = INF;
	for(int i = 1; i <= n; i ++) F[i][i] = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> K[i];
		int u = i;
		for(int j = 1; j <= K[i]; j ++) {
			int v; ll w; cin >> v >> w;
			v += n;
			for(auto tmp : Line[v]) {
				int vv = tmp.v; ll ww = tmp.w;
				F[vv][u] = F[u][vv] = min(F[vv][u], ww + w);
			}
			Line[v].push_back( {u, w} );
		}
	}
	Floyd();
	while(q --) {
		int s, t; cin >> s >> t;
		ll ans = INF;
		s += n; t += n;
		for(auto tmps : Line[s]) {
			for(auto tmpt : Line[t]) {
				ll sum = 0;
				sum = tmps.w + F[tmps.v][tmpt.v] + tmpt.w;
				ans = min(ans, sum);
			}
		}
		ans = ans + W[s - n] + W[t - n];
		cout << ans << "\n";
	}
	
	return 0;

}


