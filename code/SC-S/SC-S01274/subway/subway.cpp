#include <bits/stdc++.h>

using namespace std ;

#define i64 long long

int read () {
	int res = 0 , f = 1 ;
	char ch = getchar() ;
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1 ;
		ch = getchar() ;
	}
	while (ch >= '0' && ch <= '9') {
		res = (res << 3) + (res << 1) + (ch ^ 48) ;
		ch = getchar() ;
	}
	return res * f ;
}
int c , n , m , d , Q , rm ;
struct node {
	int to , nxt , val ;
}g[2000006] ;
struct node1 {
	int u ;
	i64 w ;
	int cnt ;
};
i64 we[500005] ;
bool operator < (node1 a , node1 b) {
	return a.w > b.w ;
}
priority_queue <node1> q ;
int head[600005] , tot ;
bool vis[500505] ;
i64 dis[20505][505] , ans , common , dp[505][505] , dis1[500007][3] , dis2[500505] ;
void add (int u , int v , int w) {
	g[++tot] = {v , head[u] , w} ;
	head[u] = tot ;
}
const i64 INF = 1000000000000000000ll ; 
void dij (int s) {
	for (int i = 1 ; i <= rm ; i++) dis[i][s - m] = INF , vis[i] = 0 ;
	dis[s][s - m] = 0 ;
	q.push ({s , 0 , 0}) ;
	while (!q.empty()) {
		int u = q.top().u , cs = q.top().cnt ;
		i64 ww = q.top().w ;
		q.pop () ;
		if (cs >= 2 * n) continue ;
		if (vis[u]) continue ;
		vis[u] = 1 ;
		for (int v , i = head[u] ; i ; i = g[i].nxt) {
			v = g[i].to ;
			if (dis[v][s - m] > dis[u][s - m] + g[i].val) {
				dis[v][s - m] = dis[u][s - m] + g[i].val ;
				q.push ({v , dis[v][s - m] , cs + 1}) ;
			}
		}
	}
}
void dij1 (int s) {
	for (int i = 1 ; i <= rm ; i++) dis1[i][s - m] = INF , vis[i] = 0 ;
	dis1[s][s - m] = 0 ;
	q.push ({s , 0 , 0}) ;
	while (!q.empty()) {
		int u = q.top().u , cs = q.top().cnt ;
		i64 ww = q.top().w ;
		q.pop () ;
		if (cs >= 2 * n) continue ;
		if (vis[u]) continue ;
		vis[u] = 1 ;
		for (int v , i = head[u] ; i ; i = g[i].nxt) {
			v = g[i].to ;
			if (dis1[v][s - m] > dis1[u][s - m] + g[i].val) {
				dis1[v][s - m] = dis1[u][s - m] + g[i].val ;
				q.push ({v , dis1[v][s - m] , cs + 1}) ;
			}
		}
	}
}
void add1 (int u , int v , i64 w) {
	dp[u][v] = dp[v][u] = min(w  , dp[u][v]) ;
}
int main () {
	freopen ("subway.in" , "r" , stdin) ;
	freopen ("subway.out" , "w" , stdout) ;
	c = read() ;
	n = read() ;
	rm = m = read() ;
	d = read() ;
	Q = read() ;
	for (int i = 1 ; i <= m ; i++) we[i] = read() ;
	for (int k , i = 1 ; i <= n ; i++) {
		k = read() ;
		++rm ;
		for (int v , w , j = 1 ; j <= k ; j++) {
			v = read() ;
			w = read() ;
			add (v , rm , w) , add (rm , v , w) ;
		}
	}
	if (c <= 15) {
		for (int i = m + 1 ; i <= rm ; i++) {
			dij (i) ;
		}
		for (int x , y , i = 1 ; i <= Q ; i++) {
			x = read() ;
			y = read() ;
			ans = INF ;
			for (int j = m + 1 ; j <= rm ; j++) ans = min (ans , (i64)dis[x][j - m] + dis[y][j - m]) ;
			printf ("%lld\n" , (i64)ans + we[x] + we[y]) ;
		}
	}else {
		for (int i = m + 1 ; i <= rm ; i++) {
			dij1 (i) ;
		}
		for (int x , y , i = 1 ; i <= Q ; i++) {
			x = read() ;
			y = read() ;
			ans = INF ;
			for (int j = m + 1 ; j <= rm ; j++) ans = min (ans , (i64)dis1[x][j - m] + dis1[y][j - m]) ;
			printf ("%lld\n" , (i64)ans + we[x] + we[y]) ;
		}
	}
	return 0 ;
}