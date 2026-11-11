#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a, t;
};
int c, n, m, d, q, w[500005], dis[505][505];
vector<node> e[500005];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++){
			int a, t;
			cin >> a >> t;
			e[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= m; i++){
		for(auto j : e[i]){
			for(auto k : e[i]){
				if(j.a == k.a) continue;
				dis[j.a][k.a] = min(dis[j.a][k.a], j.t + k.t); 
			}
		} 
	}
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		int ans = LLONG_MAX;
		for(auto i : e[x]){
			for(auto j : e[y]){
				ans = min(ans, w[x] + w[y] + i.t + j.t + dis[i.a][j.a]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
