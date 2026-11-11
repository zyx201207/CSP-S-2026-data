#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000 + 3;
vector<int> G[N];
int d[N][N];
bool use[N], col[N];
void solve(){
	int n , k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i) G[i] . clear();
	for(int i = 1; i < n; ++ i){
		int u , v;
		cin >> u >> v;
		G[u] . emplace_back(v); G[v] . emplace_back(u);
	}
	for(int i = 1; i <= n; ++ i){
		queue<int> q;
		q . push(i);
		vector<int> vis(n + 3);
		d[i][i] = 0; vis[i] = 1;
		while(q . size()){
			int x = q . front(); q . pop();
			for(auto y : G[x]){
				if(!vis[y]){
					vis[y] = 1;
					d[i][y] = d[i][x] + 1;
					q . push(y);
				}
			}
		}
	}
	if(k == 2){
		int tot = 1e18;
		for(int i = 1; i <= n; ++ i){
			for(int j = i + 1; j <= n; ++ j){
				int ans = 0;
				for(int k = 1; k <= n; ++ k) ans = max(ans , min(d[i][k] , d[j][k]));
				tot = min(tot , ans);
			}
		}
		cout << tot << '\n';
	}
	else if(n <= 10){
		int tot = 1e18 , cccc = 0;
		for(int i = 0 ; i < (1 << n); ++ i){
			if(__builtin_popcount(i) == k){
				for(int i = 1; i <= n; ++ i) use[i] = 0 , col[i] = 0;
				for(int j = 0; j < n; ++ j){
					if(i >> j & 1){
						col[j + 1] = 1;
					}
				}
				int cnt = 0;
				for(int i = 1; i <= n; ++ i){
					if(!use[i] && col[i] == 1){
						use[i] = 1;
						queue<int> q;  q . push(i);
						while(q . size()){
							int x = q . front(); q . pop();
							for(auto y : G[x]){
								if(!use[y] && col[y]){
									use[y] = 1;
									q . push(y);
								}
							}
						}
						++ cnt;
					}
				}
				if(cnt <= 2){
					int ans = 0;
					for(int i = 1; i <= n; ++ i){
						int tmp = 1e18;
						for(int j = 1; j <= n; ++ j){
							if(col[j] == 1)
								tmp = min(tmp , d[i][j]);
						}
						ans = max(ans , tmp);
					}
					++cccc;
				//	cout << ans << '\n';
					tot = min(tot , ans);
				}
			}
		}
	//	cerr << cccc << '\n';
		cout << tot << '\n';
	}
}
signed main(){
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out", "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c , t;
	cin >> c >> t;
	while(t --) solve();
	return 0;
}

