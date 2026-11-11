/*

Start Code At 2026/10/31 17:43:22.

Code By Bestart (luogu uid : 1062290).

*/

#include <bits/stdc++.h>
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf , 1 , fread_cnt , stdin) , p1 == p2) ? EOF : *p1 ++)

using namespace std ;

using db = double ;
using ll = long long ;
using ldb = long double ;
using uint = unsigned int ;
using ull = unsigned long long ;

#define inline
//#define int long long

mt19937_64 rnd(chrono :: system_clock :: now() .time_since_epoch() .count()) ;
const size_t fread_cnt = 1<<20 ;
const size_t MN = 1e6 + 10 ;
const int mod = 998244353 ;
const int inf = 1e9 + 7 ;
//const ll inf = 1e18 ;

char buf[fread_cnt] , *p1 = buf , *p2 = buf ;

template <typename T = int>
inline T read()
{
	T x = 0 ;  bool f = 0 ;  char ch = gc() ;
	while(ch < '0' || ch > '9')  f ^= ch == '-' , ch = gc() ;
	while(ch >= '0' && ch <= '9')  x = (x << 3) + (x << 1) + (ch ^ 48) , ch = gc() ;
	return f ? -x : x ;
}

/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/


vector<int> vt[MN] ;
int n , k , res , ans , dis[MN] ;

inline void dfs (int u , int f) {
	if(f != 0 && dis[u] == inf)  dis[u] = dis[f]+1 ;
	for(auto v : vt[u])  if(v != f) {
		dfs(v, u) , dis[u] = min(dis[u], dis[v]+1) ;
	}
	res = max(res , dis[u]) ;
}

int fa[MN] , siz[MN] ;
inline int find (int x) {
	return fa[x] == x ? fa[x] : fa[x] = find(fa[x]) ;
}
inline void merge (int x , int y) {
	x = find(x) , y = find(y) ;
	if(x == y)  return ;
	if(siz[x] > siz[y])  swap(x, y) ;
	fa[x] = y , siz[y] += siz[x] ;
}
inline bool check() {
	for(int i = 1 ; i <= n ; ++ i)  fa[i] = i , siz[i] = 1 ;
	for(int u = 1 ; u <= n ; ++ u)  if(dis[u] == 0) {
		for(auto v : vt[u])  if(dis[v] == 0) {
			merge(u, v) ;
		}
	}
	int to1 = 0 , to2 = 0 ;
	for(int i = 1 ; i <= n ; ++ i)  if(dis[i] == 0) {
		int x = find(i) ;
		if(to1 == 0 || x == to1)  to1 = x ;
		else if(to2 == 0 || x == to2)  to2 = x ;
		else  return 0 ;
	}
	return 1 ;
}

inline bool solve()
{
	for(int i = 1 ; i <= n ; ++ i)  fa[i] = dis[i] = 0 , vt[i].clear() ;
	n = k = res = ans = 0 ;
	
	cin >> n >> k , ans = inf ;
	for(int i = 1 , u , v ; i < n ; ++ i)  cin >> u >> v , vt[u].push_back(v) , vt[v].push_back(u) ;
	for(int S = 0 ; S < (1<<n) ; ++ S) {
		if(__builtin_popcount(S) != k)  continue ;
		for(int i = 1 ; i <= n ; ++ i)  dis[i] = inf ;
		for(int i = 1 ; i <= n ; ++ i)  if(S>>(i-1)&1)  dis[i] = 0 ;
		if(!check())  continue ;
		res = 0 , dfs(1, 0) , ans = min(ans , res) ;
	}
	cout << ans << '\n' ;
	
	return 0 ;
}

signed main()
{
	freopen("hub.in" , "r" , stdin) ;
	freopen("hub.out" , "w" , stdout) ;
	
	cin.tie(0) -> sync_with_stdio(0) ;
	
//	system("fc hub.out hub2.ans") ;
	
	int __c_, __T_ ;  cin >> __c_ >> __T_ ;  while(__T_ --)  solve() ;
	
//	while(!solve()) ;
	
//	solve() ;
	
	return 0 ;
}
