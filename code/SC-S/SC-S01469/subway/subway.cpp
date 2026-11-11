/*

Start Code At 2026/10/31 14:46:01.

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
const ll inf = 1e18 ;

char buf[fread_cnt] , *p1 = buf , *p2 = buf ;

template <typename T = int>
inline T read()
{
	T x = 0 ;  bool f = 0 ;  char ch = gc() ;
	while(ch < '0' || ch > '9')  f ^= ch == '-' , ch = gc() ;
	while(ch >= '0' && ch <= '9')  x = (x << 3) + (x << 1) + (ch ^ 48) , ch = gc() ;
	return f ? -x : x ;
}

int head[MN] , edge_cnt ;
struct edge {
	int u , v , w , nex ;
	edge() {u = v = w = nex = 0 ;}
	edge(int _u , int _v , int _w , int _nex) : u(_u) , v(_v) , w(_w) , nex(_nex) {}
	#define adde(u,v,w)  e[++edge_cnt]=edge(u,v,w,head[u]),head[u]=edge_cnt
	#define fre(i,u,to)  for(int i=head[u],to=e[i].v;i;i=e[i].nex,to=e[i].v)
} e[MN] ;

struct node {
	int v ;  ll w ;
	node() {v = 0 , w = 0 ;}
	node(int _v , ll _w) : v(_v) , w(_w) {}
	bool operator < (const node &x) const {return w>x.w ;}
};

bool vis[MN] ;
priority_queue<node> q ;
ll dis[510][510] , V ;
inline void dijkstra (int s) {
	while(!q.empty())  q.pop() ;
	for(int i = 1 ; i <= V ; ++ i)  dis[s][i] = inf , vis[i] = 0 ;
	dis[s][s] = 0 , q .push(node(s,0)) ;
	while(!q.empty()) {
		int u = q.top().v ;  q.pop() ;
		if(vis[u])  continue ;
		vis[u] = 1 ;
		fre(i,u,v)  if(dis[s][v] > dis[s][u] + e[i].w) {
			dis[s][v] = dis[s][u]+e[i].w , q.push(node(v,dis[s][v])) ;
		}
	}
}

struct uin {
	int v , t ;
	uin() {v = t = 0 ;}
	uin(int _v , int _t) : v(_v) , t(_t) {}
};


vector<uin> a[MN] , vt[MN] ;
int __c_ , n , m , d , qu , __C[MN] ;

inline void init() {
	V = n ;
	for(int u = 1 ; u <= n ; ++ u) {
		for(auto fi : a[u]) {
			for(auto no : vt[fi.v]) {
				int v = no.v , cost = fi.t + no.t ;
				if(u != v)  adde(u, v, cost) ;
			}
		}
	}
	for(int u = 1 ; u <= n ; ++ u)  dijkstra(u) ;
}

inline ll calc (int u , int v) {
	ll val = inf ;
	for(auto s : vt[u])  for(auto t : vt[v])  val = min(val, dis[s.v][t.v]+s.t+t.t) ;
	return val ;
}

inline bool solve()
{
	
	cin >> __c_ >> n >> m >> d >> qu ;
	for(int i = 1 ; i <= m ; ++ i)  cin >> __C[i] ;
	for(int i = 1 , tot ; i <= n ; ++ i) {
		cin >> tot ;
		for(int j = 0 , v , t ; j < tot ; ++ j)  cin >> v >> t , a[i] .push_back(uin(v,t)) , vt[a[i][j].v] .push_back(uin(i,a[i][j].t)) ;
	}
	init() ;
	for(int i = 1 , u , v ; i <= qu ; ++ i) {
		cin >> u >> v ;
		cout << __C[u] + __C[v] + calc(u, v) << '\n' ;
	}
	
	return 0 ;
}

signed main()
{
	freopen("subway.in" , "r" , stdin) ;
	freopen("subway.out" , "w" , stdout) ;
	
	cin.tie(0) -> sync_with_stdio(0) ;
	
//	system("fc subway.out subway6.ans") ;
	
//	int __T_ ;  cin >> __T_ ;  while(__T_ --)  solve() ;
	
//	while(!solve()) ;
	
	solve() ;
	
	return 0 ;
}

/*
15:34:35  da wan le bao li, fa xian que shi shi shuang xiang bian. zhun bei kai shi xie shen mi zheng jie. xian ran shuang xiang bian shi yi ge fei chang zhong yao de tiao jian.
15:55:18  tiao shi wan cheng
*/

/*
bao li
inline bool solve()
{
	
	cin >> __c_ >> n >> m >> d >> qu , V = m*(n+1) ;
	for(int i = 1 ; i <= m ; ++ i)  cin >> __C[i] ;
	for(int i = 1 ; i <= n ; ++ i) {
		cin >> tot[i] , a[i].reserve(tot[i]) , t[i].reserve(tot[i]) ;
		for(int j = 0 ; j < tot[i] ; ++ j)  cin >> a[i][j] >> t[i][j] ;
		for(int j = 0 ; j+1 < tot[i] ; ++ j)  adde(m*i+a[i][j] , m*i+a[i][j+1] , 0) ;
		for(int j = 0 ; j+1 < tot[i] ; ++ j)  adde(m*i+a[i][j+1] , m*i+a[i][j] , 0) ;
		for(int j = 0 ; j < tot[i] ; ++ j)  adde(m*i+a[i][j] , a[i][j] , t[i][j]) ;
		for(int j = 0 ; j < tot[i] ; ++ j)  adde(a[i][j] , m*i+a[i][j] , t[i][j]) ;
	}
	for(int i = 1 ; i <= m ; ++ i)  dijkstra(i) ;
	for(int i = 1 , u , v ; i <= qu ; ++ i)  cin >> u >> v , cout << __C[u] + __C[v] + dis[u][v] << '\n' ;
	
	return 0 ;
}
*/