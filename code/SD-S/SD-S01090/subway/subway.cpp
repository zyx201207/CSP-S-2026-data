#include<bits/stdc++.h>
#define endl '\n'
//#define MSOD

using namespace std;
using ll = long long;

const int N = 5e2 + 5, M = 5e5 + 5, D = 2e1 + 5;

int cc_, n, m, d, q;
int w[M];
vector<pair<int, int>> V[M];

ll f[N][N];



void TEST() {
	cin>>cc_>>n>>m>>d>>q;
	for(int i = 1 ; i <= m ; i ++) cin>>w[i];
	for(int i = 1 ; i <= n ; i ++) {
		int k;
		cin>>k;
		for(int j = 1 ; j <= k ; j ++) {
			int a, t;
			cin>>a>>t;
			V[a].push_back({i, t});
		}
	}
	memset(f, 0x3f, sizeof f);
	for(int i = 1 ; i <= n ; i ++) f[i][i] = 0;
	for(int i = 1 ; i <= m ; i ++) {
		for(int j = 0 ; j < (int)V[i].size() ; j ++) {
			for(int k = j + 1 ; k < (int)V[i].size() ; k ++) {
				int c = V[i][j].second + V[i][k].second;
				int u = V[i][j].first, v = V[i][k].first;
				f[u][v] = min(f[u][v], (ll)c), f[v][u] = min(f[v][u], (ll)c);
			}
		}
	}
	for(int k = 1 ; k <= n ; k ++) {
		for(int i = 1 ; i <= n ; i ++) {
			for(int j = 1 ; j <= n ; j ++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q --) {
		int x, y;
		cin>>x>>y;
		ll ans = 1e18;
		for(int i = 0 ; i < (int)V[x].size() ; i ++) {
			for(int j = 0 ; j < (int)V[y].size() ; j ++) {
				ll c = V[x][i].second + V[y][j].second;
				int u = V[x][i].first, v = V[y][j].first;
				ans = min(ans, f[u][v] + c + w[x] + w[y]);
			}
		}
		cout<<ans<<endl;
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false), cout.tie(0), cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int TC = 1;
#ifdef MSOD
	cin>>TC;
#endif
	while(TC --) TEST();
	return 0;
}
