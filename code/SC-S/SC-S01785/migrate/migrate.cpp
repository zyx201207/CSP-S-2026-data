#include <bits/stdc++.h>

#define N 2000010
typedef long long LL ;
using namespace std ;

vector<int> g[N] ;
int c , T , n ;
bool sta[N] ;
LL d , x[N] , dis[N] , cnt[N] ;    //搜索时统计每个点的最短距离和方案数 
queue<int> q ;

inline void bfs(int s) {    //01bfs 到每个点第一次的值就是dis的最小值 
	memset(cnt , 0 , sizeof cnt) ;
	memset(dis , 0 , sizeof dis) ;
	memset(sta , false , sizeof sta) ;
    while(!q.empty()) q.pop() ;
	dis[s] = 0 , sta[s] = true ; q.push(s) ;
	while(!q.empty()) {
		int u = q.front() ; q.pop() ;
		for(auto v : g[u]) {
			if(sta[v] && dis[v] != dis[u]+1) {    //如果距离相等却第二次扫到 只能说明还应该加一次 
				continue ;
			} 
			dis[v] = dis[u]+1 , sta[v] = true , cnt[v] ++ ;
			q.push(v) ;
		}
	}
	return ;
}

int main() {
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	scanf("%d%d" , &c , &T) ;
	while(T --) {
		scanf("%d %lld" , &n , &d) ;
		for(int i = 1 ; i <= n ; ++i) {
			g[i].clear() ;
			scanf("%lld" , &x[i]) ;
		}
		for(int i = 1 ; i <= n ; ++i) {
			for(int j = i+1 ; j <= n ; ++j) {
				//如果这样建的话 就会变成01bfs
				if(x[j]-x[i] <= d) {
					g[i].push_back(j) ;    //鸟不会反向走 因为这样需要至少两步 显然不如一步跳过去 
				} 
			}
		}
		int ans = 0 ;
		for(int i = 1 ; i <= n ; ++i) {
			bfs(i) ;
			for(int j = 1 ; j <= n ; ++j) {
				ans += (cnt[j] == 2) ;
			} 
		}
		printf("%d\n" , ans) ;
	}
	return 0 ;
}