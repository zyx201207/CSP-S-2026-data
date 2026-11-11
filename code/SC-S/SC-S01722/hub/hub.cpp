#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e6 + 5 ;
int n , k , c , p[N] ;
vector <int> g[N] ;

int find(int x) {
	if(x != p[x]) {
		p[x] = find(p[x]) ;
	}
	return p[x] ;
}

void solve() {
	cin >> n >> k ;
	for(int i = 1 ; i <= n ; ++ i) {
		g[i].clear() ;
	}
	for(int i = 1 ; i < n ; ++ i) {
		int u , v ; 
		cin >> u >> v ;
		g[u].push_back(v) ;
		g[v].push_back(u) ;
	}
	int ans = 1e9 ;
	for(int i = 0 ; i < 1 << n ; ++ i) {
		int cnt = 0 ;
		for(int j = 1 ; j <= n ; ++ j) {
			p[j] = j ;
		}
		for(int j = 0 ; j < n ; ++ j) {
			cnt += i >> j & 1 ;
		}
		if(cnt != k) continue ;
		for(int j = 0 ; j < n ; ++ j) {
			if((i >> j & 1) == 0) continue ;
			int u = j + 1 ;
			for(auto v : g[u]) {
				if(i >> (v - 1) & 1) {
					int pu = find(u) ;
					int pv = find(v) ;
					if(pu != pv) p[pu] = pv ;
				}
			}
		}
		int sum = 0 ;
		for(int j = 1 ; j <= n ; ++ j) {
			if((i >> (j - 1) & 1) == 0) continue ;
			if(find(j) == j) sum ++ ;
		}
		if(sum > 2) continue ;
		queue<int> q ;
		vector <int> bfs(n + 5 , 0) ;
		for(int j = 0 ; j < n ; ++ j) {
			if(i >> j & 1) {
				bfs[j + 1] = 1 ;
				q.push(j + 1) ;
			}
		}
		while(! q.empty()) {
			int u = q.front() ;
			q.pop() ;
			for(auto v : g[u]) {
				if(bfs[v]) continue ;
				bfs[v] = bfs[u] + 1 ;
				q.push(v) ;
			}
		}
		int mx = 0 ;
		for(int j = 1 ; j <= n ; ++ j) {
			mx = max(mx , bfs[j] - 1) ;
		}
		ans = min(ans , mx) ;
	}
	cout << ans <<'\n' ;
}

signed main() {
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	
	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;
	int  T ;
	cin >> c >> T ;
	while(T --) {
		solve() ;
	}
	return 0 ;
}