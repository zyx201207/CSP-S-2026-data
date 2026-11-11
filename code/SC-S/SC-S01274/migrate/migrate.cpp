#include <bits/stdc++.h>

using namespace std ;

#define i64 long long

i64 read () {
	i64 res = 0 , f = 1 ;
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
int c , T , n ;
i64 a[2000005] , d , dp[305][305] , cnt[305][305] , ans ;
struct node {
	int to , nxt , val ;
}g[4000005] ;
int tot , head[2000005] ;
bool vis[2000005] ;
void add (int u , int v , int w) {
	g[++tot] = {v , head[u] , w} ;
	head[u] = tot ;
}
i64 iabs (i64 x) {
	return ((x < 0) ? -x : x) ;
}
void dij (int s) {
	for (int i = 0 ; i <= n ; i++) dp[s][i] = 1e18 , cnt[s][i] = 0 , vis[i] = 0 ;
	dp[s][s] = 0 , cnt[s][s] = 1 ;
	while (1) {
		int u = 0 ;
		for (int i = 1 ; i <= n ; i++) {
			if (vis[i] == 0 && dp[s][i] < dp[s][u]) u = i ;
		}
		if (!u) break ;
		vis[u] = 1 ;
		for (int v , i = head[u] ; i ; i = g[i].nxt) {
			v = g[i].to ;
			if (dp[s][v] > dp[s][u] + g[i].val) {
				dp[s][v] = dp[s][u] + g[i].val , cnt[s][v] = cnt[s][u] ;
			} else if (dp[s][v] == dp[s][u] + g[i].val){
				cnt[s][v] += cnt[s][u] ;
			}
		}
	}
}
void solve () {
	n = read() ;
	d = read() ;
	ans = 0 , tot = 0 ;
	for (int i = 1 ; i <= n ; i++) a[i] = read() , head[i] = 0 ;
	if (c <= 6) {
		for(int i = 1 ; i <= n ; i++) {
			for (int j = i + 1 ; j <= n ; j++) {
				if (iabs (a[i] - a[j]) <= d) {
					add (i , j , 1) , add (j , i , 1) ;	
				}
			}
		}
		for (int i = 1 ; i <= n ; i++) {
			dij (i) ;
		}
		for (int i = 1 ; i <= n ; i++) {
			for (int j = i + 1 ; j <= n ; j++) {
				if (cnt[i][j] == 2) ++ans ;
			}
		}
		printf ("%lld\n" , ans) ;
		
	}
}
int main () {
	freopen ("migrate.in" , "r" , stdin) ;
	freopen ("migrate.out" , "w" , stdout) ;
	c = read() ;
	T = read() ;
	while (T--) solve () ;
	return 0 ;
}
