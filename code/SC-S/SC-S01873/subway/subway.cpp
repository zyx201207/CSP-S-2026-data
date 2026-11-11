#include<bits/stdc++.h>
#define int long long
#define pii pair<int , int>
using namespace std ;
const int MAXN = 505 ;
const int MAXM = 5e5 + 7 ;
const int INF = 0x3f3f3f3f3f3f3f3f ;
int w[MAXM] ;

vector<pii> b[MAXN] ;

vector<pii> g[MAXM] ;

int dis[MAXN][MAXN] ;

int z[MAXM] ;

signed main() {
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;

	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	int c , n , m , d , q ;
	
	cin >> c >> n >> m >> d >> q ;
	
	for (int i = 1 ; i <= m ; i ++) {
		cin >> w[i] ;
	}
	
	for (int i = 1 ; i <= n ; i ++) {
		int k ;
		cin >> k ;
		
		for (int j = 1 ; j <= k ; j ++) {
			int u , w ;
			cin >> u >> w ;
			b[i].push_back({u , w}) ;
			g[u].push_back({i , w}) ;
		}
	}
	
	memset(dis , 0x3f , sizeof(dis)) ;
	
	for (int i = 1 ; i <= n ; i ++) {
		dis[i][i] = 0 ;
	}
	
	memset(z , 0x3f , sizeof(z)) ;
	for (int i = 1 ; i <= m ; i ++) {
		for (auto u : g[i]) {
			for (auto v : g[i]) {
				dis[u.first][v.first] = min(dis[u.first][v.first] , u.second + v.second) ;
			}
		}
	}
	
//	cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n" ;
	
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++) {
			for (int k = 1 ; k <= n ; k ++) {
				dis[j][k] = min(dis[j][k] , dis[j][i] + dis[i][k]) ;
			}
		}
	}
	
//	cerr << clock() * 1.0 / CLOCKS_PER_SEC << "\n" ;
	
	for (int i = 1 ; i <= q ; i ++) {
		int x , y ;
		cin >> x >> y ;
		
		int ans = INF ;
		for (auto p : g[x]) {
			for (auto e : g[y]) {
				ans = min(ans , p.second + e.second + dis[p.first][e.first] + w[x] + w[y]) ;
			}
		}
		
		cout << ans << "\n" ;
	}
	
	return 0 ;
}
