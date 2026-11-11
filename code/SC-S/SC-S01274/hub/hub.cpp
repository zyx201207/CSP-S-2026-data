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
int c , T , n , k , col[500005] , ans = 1e9 , dp[4005][4005] ;
vector <int> g[500005] ;
bool vis[500005] ;
void dfs (int u , int fa , int cl) {
	col[u] = cl ;
	for (auto v : g[u]) {
		if (v == fa) continue ;
		if (!vis[v]) continue ;
		dfs (v , u , cl) ;
	}
}
void dfs1 (int st , int u , int ed , int dep , int fa) {
	if (u == ed) dp[st][ed] = dep ;
	for (auto v : g[u]) {
		if (v == fa) continue ;
		dfs1 (st , v , ed , dep + 1 , u) ;
	}
}
int dis (int u , int v) {
	return dp[u][v] ;
}
void solve () {
	n = read() ;
	k = read() , ans = 1e9 ;
	for (int i = 1 ; i <= n ; i++) g[i].clear() ;
	for (int i = 1 ; i <= n ; i++) col[i] = 0 ;
	for (int i = 1 , u , v ; i < n ; i++) {
		u = read() ;
		v = read() ;
		g[u].push_back (v) , g[v].push_back (u) ;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			dp[i][j] = 1e9 ;
		}
		dp[i][i] = 0 ;
	}
	for (int i = 1 ; i <= n ; i++) {
		for (int j = 1 ; j <= n ; j++) {
			dfs1 (i , i , j , 0 , 0) ;
		}
	}
	for (int i = 0 ; i < (1 << n) ; i++) {
		for (int j = 1 ; j <= n ; j++) vis[j] = col[j] = 0 ;
		int tot = 0 ;
		for (int j = 1 ; j <= n ; j++) {
			if ((i >> (j - 1)) & 1) vis[j] = 1 , ++tot ;
		}
		if (tot != k) continue ; 
		int cnt = 0 ;
		for (int j = 1 ; j <= n ; j++) {
			if (!vis[j]) continue ;
			if (!col[j]) {
				++cnt ;
				dfs (j , 0 , cnt) ;
			}
		}
		if (cnt > 2) continue ;
		int res = 0 ;
		for (int j = 1 ; j <= n ; j++) {
			if (vis[j]) continue ;
			int cur = 1e9 ;
			for (int v = 1 ; v <= n ; v++) {
				if (!vis[v]) continue ;
				cur = min (cur , dis (j , v)) ;
			}
			res = max (res , cur) ;
		}
		ans = min (ans , res) ;
	}
	printf("%d\n" , ans) ;
}
int main () {
	freopen ("hub.in" , "r" , stdin) ;
	freopen ("hub.out" , "w" , stdout) ;
	c = read() ;
	T = read() ;
	while (T--) solve () ;
	return 0 ;
}
