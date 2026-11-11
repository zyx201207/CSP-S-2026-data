#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repb(i, a, b) for(int i = (a); i >= (b); --i)

typedef long long ll;

const int N = 500 + 5;
const int M = 5e5 + 5;
const ll INf = 1e18;

int c, n, m, d, q;
int w[M];

vector<pair<int, int>> z[M];
ll dp[N][N];

void update(ll &x, ll y){
	if(x > y) x = y;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m) cin >> w[i];
	rep(i, 1, n){
		int k, a, t;
		cin >> k;
		rep(j, 1, k){
			cin >> a >> t;
			z[a].emplace_back(make_pair(i, t));
		}
	}
	
	rep(i, 1, n){
		rep(j, 1, n){
			if(i != j) dp[i][j] = INf;
			else dp[i][j] = 0;
		}
	}
	
	rep(u, 1, m){
		for(int i = 0; i < z[u].size(); ++i){
			for(int j = i + 1; j < z[u].size(); ++j){
				auto p1 = z[u][i], p2 = z[u][j];
				update(dp[p1.first][p2.first], p1.second + p2.second);
				update(dp[p2.first][p1.first], p1.second + p2.second);
			}
		}
	}
	
//	rep(i, 1, n){
//		rep(j, 1, n){
//			cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
//		}
//	}
	
	rep(x, 1, n){
		rep(i, 1, n){
			rep(j, 1, n){
				update(dp[i][j], dp[i][x] + dp[j][x]);
			}
		}
	}
	
//	rep(i, 1, n){
//		rep(j, 1, n){
//			cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
//		}
//	}
	
	while(q--){
		int u, v;
		cin >> u >> v;
		ll ans = INf;
		for(auto i : z[u]){
			for(auto j : z[v]){
				ans = min(ans, dp[i.first][j.first] + i.second + j.second + w[u] + w[v]);
//				cout << i.first << ' ' << i.second << ' ' << j.first << ' ' << j.second << ' ' << i.second + j.second + w[u] + w[v] + dp[i.first][j.first] << '\n';
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}