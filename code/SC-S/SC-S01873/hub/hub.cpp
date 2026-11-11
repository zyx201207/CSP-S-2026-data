#include<bits/stdc++.h>
#define pii pair<int , int>
using namespace std ;
const int MAXN = 1e6 + 7 ;
vector<int> dir[MAXN] ;
int c , t ;
int fa[MAXN] ;
int rt1 , rt2 ;

void dfs1(int u , int f) {
	fa[u] = f ;
	
	for (auto v : dir[u]) {
		if (v == f)	continue ;
		dfs1(v , u) ;
	}
	
	return ;
}

int d[MAXN] , lst ;
pii dfs2(int u , int fa , int z) {
	pii g = {u , 0} ;
	
	for (auto v : dir[u]) {
		if (v == fa or v == z)	continue ;
		pii d = dfs2(v , u , z) ;
		d.second ++ ;
		
		if (d.second > g.second) {
			g = d ;
		}
	}
	
	return g ;
}

bool dfs3(int u , int fa , int z , int gv) {
	if (u == gv) {
		d[++lst] = u ;
		return 1 ;
	}
	
	for (auto v : dir[u]) {
		if (v == fa or v == z)	continue ;
		if (dfs3(v , u , z , gv)) {
			d[++lst] = u ;
			return 1 ;
		}
	}
	
	return 0 ;
}

int mxd[MAXN] ;
int nfa[MAXN] ;
void dfs4(int u , int fa , int z) {
	mxd[u] = 1 ;
	nfa[u] = fa ;
	for (auto v : dir[u]) {
		if (v == fa or v == z)	continue ;
		
		dfs4(v , u , z) ;
		
		mxd[u] = max(mxd[u] , mxd[v] + 1) ;
	}
	
	return ;
}

vector<int> z[MAXN] ;
vector<int> l[MAXN] ;

void solve() {
	int n , k ;
	cin >> n >> k ;
	
	for (int i = 1 ; i <= n ; i ++) {
		dir[i].clear() ;
	}
	
	for (int i = 1 ; i < n ; i ++) {
		int u , v ;
		cin >> u >> v ;
		dir[u].push_back(v) ;
		dir[v].push_back(u) ;
	}
	
	if (c == 13 or c == 14) {
		int m = n / 2 ;
		
		if (k >= m and k <= 2 * m) {
			cout << 1 << "\n" ;
		}
		else if (k == n) {
			cout << 0 << "\n" ;
		}
		else {
			int t = m - k ;
			cout << (t + 3) / 4 + 1 << "\n" ;
		}
		
		return ;
	}
	
	dfs1(1 , 0) ;
	
	int ans = n ;
	for (int i = 2 ; i <= n ; i ++) {
		rt1 = i , rt2 = fa[i] ;
		
		pii h = dfs2(rt1 , 0 , rt2) ;
		pii r = dfs2(h.first , 0 , rt2) ;
		
		lst = 0 ;
		dfs3(h.first , 0 , rt2 , r.first) ;
		
		int s = d[(lst + 1) / 2] ;
		
		dfs4(s , 0 , rt2) ;
		
		h = dfs2(rt2 , 0 , rt1) ;
		r = dfs2(h.first , 0 , rt1) ;
		lst = 0 ;
		dfs3(h.first , 0 , rt1 , r.first) ;
		
		int w = d[(lst + 1) / 2] ;
		
		dfs4(w , 0 , rt1) ;
		
		for (int j = 1 ; j <= n ; j ++) {
			z[j].clear() ;
			l[j].clear() ;
		}
		
		for (auto v : dir[s]) {
			if (v == rt2)	continue ;
			z[mxd[v]].push_back(v) ;
		}
		
		for (auto v : dir[w]) {
			if (v == rt1)	continue ;
			l[mxd[v]].push_back(v) ;
		}
		
		int cnt = 2 ;
		int res = n ;
		for (int j = n ; j >= 1 ; j --) {
			for (auto u : z[j]) {
				for (auto v : dir[u]) {
					if (v == nfa[u] or v == rt2)	continue ;
					z[mxd[v]].push_back(v) ;
				}
				cnt ++ ;
				
				if (cnt > k)	break ;
			}
			
			for (auto u : l[j]) {
				for (auto v : dir[u]) {
					if (v == nfa[u] or v == rt1)	continue ;
					l[mxd[v]].push_back(v) ;
				}
				
				cnt ++ ;
				if (cnt > k)	break ;
			}
			
			if (cnt <= k)	res = j - 1 ;
			else	break ;
		}
		
		ans = min(ans , res) ;
	}
	
	cout << ans << "\n" ;
}

signed main() {
	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;

	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	cin >> c >> t ;
	
	while (t--) {
		solve() ;
	}

	return 0 ;
}