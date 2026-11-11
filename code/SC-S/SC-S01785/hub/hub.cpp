#include <bits/stdc++.h>

#define N 3010
using namespace std ;

bool sta[N] ;
int c , T , n , kn , dep[N] , dis[N][N] , ans = 0x3f3f3f3f ;
vector<int> g[N] ;

inline void dfs(int u , int fa) {
	dep[u] = dep[fa]+1 , dis[u][fa] = dis[fa][u] = 1 ;
	for(auto v : g[u]) {
		if(v == fa) continue ;
		dfs(v , u) ;
	}
	return ;
}
inline void get_ans(int k , int ps , int bs) {    //pointsum blocksum
	if(k == kn+1) {
		int res = 0 ;
		for(int i = 1 ; i <= n ; ++i) {
			if(sta[i]) continue ;
			int tot = 0x3f3f3f3f ;
			for(int j = 1 ; j <= n ; ++j) {
				if(!sta[j]) continue ;
				tot = min(tot , dis[i][j]) ; 
			}
			res = max(res , tot) ;
		}
		ans = min(ans , res) ;
		return ;
	}
	for(int i = 1 ; i <= n ; ++i) {
		if(sta[i]) continue ;
		int res = 0 ;
		for(auto v:g[i]) {
			//判断能否连进连通块 
			res += sta[v] ;
		}
		if(res == 0) {
			if(bs == 2) continue ;
			sta[i] = true ;
			get_ans(k+1 , ps+1 , bs+1) ;
		}
		if(res == 1) {
			sta[i] = true ;
			get_ans(k+1 , ps+1 , bs) ;
		}
		if(res == 2) {
			sta[i] = true ;
			get_ans(k+1 , ps+1 , bs-1) ;
		}
		sta[i] = false ;
	}
	return ;
}

int main() {
	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;
	ios::sync_with_stdio(0) ;
	cin.tie(0) , cout.tie(0) ;
	cin >> c >> T ;
	while(T --) {
		cin >> n >> kn ;
		ans = 0x3f3f3f3f ;
		for(int i = 1 ; i <= n ; ++i) {
			g[i].clear() , sta[i] = false ;
			memset(dis[i] , 0x3f , sizeof dis[i]) ;
			dis[i][i] = 0 ;
		} 
		for(int i = 1 , u , v ; i < n ; ++i) {
			cin >> u >> v ;
			g[u].push_back(v) , g[v].push_back(u) ;
		}
		dfs(1 , 0) ;
		for(int k = 1 ; k <= n ; ++k) {
			for(int i = 1 ; i <= n ; ++i) {
				if(i == k) continue ;
				for(int j = 1 ; j <= n ; ++j) {
					if(k == j || i == j) continue ; 
					dis[i][j] = dis[j][i] = min(dis[i][j] , dis[i][k]+dis[k][j]) ;
				}
			}
		}
		get_ans(1 , 0 , 0) ;
		cout << ans << endl ;
	}
	return 0 ;
}