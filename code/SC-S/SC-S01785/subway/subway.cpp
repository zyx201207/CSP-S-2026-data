#include <bits/stdc++.h>

#define N 510
#define M 500010
typedef long long LL ;
using namespace std ;

int c , n , m , d , qu ;
vector<pair<int,LL>>ln[M] , g[N] ;
LL dis[N][N] , w[M] ;
bool sta[N] ;
queue<int>q ;

inline void BellmanFord_Queue(int s) {
	while(!q.empty()) q.pop() ;
	memset(dis[s] , 0x3f , sizeof dis[s]) ;
	memset(sta , false , sizeof sta) ;
	q.push(s) , sta[s] = true , dis[s][s] = 0 ;
	while(!q.empty()) {
		int u = q.front() ; q.pop() ; sta[u] = false ;
		for(auto k : g[u]) {
			int v = k.first ; LL w = k.second ;
			if(dis[s][v] > dis[s][u]+w) {
				dis[s][v] = dis[s][u]+w ;
				if(!sta[v]) sta[v] = true , q.push(v) ;
			}
		}
	}
	return ;
}

int main() {
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ; 
	scanf("%d %d %d %d %d" , &c , &n , &m , &d , &qu) ;
	for(int i = 1 ; i <= m ; ++i) {
		scanf("%lld" , &w[i]) ;
	}
	for(int i = 1 ; i <= n ; ++i) {
		for(int j = 1 ; j <= n ; ++j) dis[i][j] = -1 ;
		dis[i][i] = 0 ;
	}
	for(int i = 1 , k ; i <= n ; ++i) {
		scanf("%d" , &k) ;
		for(int j = 1 , a ; j <= k ; ++j) {
			LL t ;
			scanf("%d %lld" , &a , &t) ;
			ln[a].push_back({i , t}) ;    //第i条线过a站 需要步行t的时间 
		}
	}
	for(int i = 1 ; i <= m ; ++i) {
		//我终于知道d是干嘛的了
		int len = ln[i].size() ;
		for(int k1 = 0 ; k1 < len ; ++k1) {
			for(int k2 = k1+1 ; k2 < len ; ++k2) {
				int u = ln[i][k1].first , v = ln[i][k2].first ;
				LL w = ln[i][k1].second+ln[i][k2].second ;
				dis[u][v] = dis[v][u] = (dis[u][v] == -1)?w:min(dis[u][v] , w) ;    //两条线之间最短就是换乘距离和最短的那一站 
			}
		} 
	}
	for(int i = 1 ; i <= n ; ++i) {
		for(int j = 1 ; j <= n ; ++j) {
			if(i == j || dis[i][j] == -1) continue ;
			g[i].push_back({j , dis[i][j]}) ;
			g[j].push_back({i , dis[i][j]}) ;
		}
	}
	for(int i = 1 ; i <= n ; ++i) {
		BellmanFord_Queue(i) ;
	}
	while(qu--) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		LL ans = 0x3f3f3f3f3f3f3f3f ;
		for(auto k1:ln[x]) {
			for(auto k2:ln[y]) {
				ans = min(ans , dis[k1.first][k2.first]+k1.second+k2.second) ;
			}
		}
		printf("%lld\n" , ans+w[x]+w[y]) ;
	}
	return 0 ;
}