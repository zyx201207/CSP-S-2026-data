#include<bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
using namespace std;
const int N = 510, M = 5e5 + 10;
int c, n, m, d, q, w[M];
ll f[N][N];
vector<PII> g[M];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int x, t;
			cin >> x >> t;
			g[x].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) f[i][j] = 1e18;
		f[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(auto p : g[i]){
			for(auto k : g[i]){
				if(p.first == k.first) continue;
				int u = p.first, v = k.first, w1 = p.second, w2 = k.second;
				f[u][v] = min(f[u][v], (ll)w1 + w2);
				f[v][u] = f[u][v];
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		ll ans = 1e18;
		for(auto p : g[l]){
			for(auto k : g[r]){
				int u = p.first, v = k.first, w1 = p.second, w2 = k.second;
				ans = min(ans, (ll)w1 + w2 + f[u][v]);
			}
		}
		cout << ans + w[l] + w[r] << '\n';
	}
	return 0;
}
