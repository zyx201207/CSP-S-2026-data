#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 2e3 + 5 ;
int n , m , d , tot , dis[N][N] , a[N] ;
vector <pair<int , int>> g[N] ;
vector <pair<int , int>> vec[505] ;
map <pair<int , int> , int> mp ;

void dijk(int s , int dis[]) {
	dis[s] = 0 ;
	priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> q ;
	q.push({0 , s}) ;
	while(! q.empty()) {
		auto cur = q.top() ;
		int d = cur.first , u = cur.second ;
		q.pop() ;
		if(dis[u] < d) continue ;
		for(auto curr :g[u]) {
			int v = curr.first ;
			int w = curr.second ;
			if(d + w < dis[v]) {
				dis[v] = d + w ;
				q.push({dis[v] , v}) ;
			}
		}
 	}
}

signed main() {
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	int c , q  ; 
	cin >> c >> n >> m >> d >> q ;
	for(int i = 1 ; i <= m ; ++ i) cin >> a[i] ;
	tot = m ;
	for(int i = 1 ; i <= n ; i ++) {
		int k ;
		cin >> k ;		
		for(int j = 1 ; j <= k ; ++ j) {
			int u , w ;
			cin >> u >> w ;
			vec[i].push_back({u , w}) ;
			mp[{i , u}] = ++ tot ;
			g[u].push_back({tot , w}) ;
			g[tot].push_back({u , w}) ;
  		}
		for(int j = 0 ; j < k ; ++ j) {
			for(int l = j + 1 ; l < k ; ++ l) {
				int u = vec[i][j].first ;
				int v = vec[i][l].first ;
				u = mp[{i , u}] ;
				v = mp[{i , v}] ;
				g[u].push_back({v , 0}) ;
				g[v].push_back({u , 0}) ;
			}
		}
	}
	
	for(int i = 1 ; i <= m ; ++ i) {
		memset(dis[i] , 0x3f , sizeof(dis[i])) ;
		dijk(i , dis[i]) ;
 	}
	
	while(q --) {
		int x , y ;
		cin >> x >> y ;
		cout << a[x] + dis[x][y] + a[y] <<'\n' ; 
	}
	return 0 ;
}