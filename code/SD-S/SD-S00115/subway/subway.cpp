#include<bits/stdc++.h>
#include<vector>
#include<utility>
#include<climits>
#define re register
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lll __int128
#define db double
#define fi const int&
#define fl const ll&
#define ful const ull&
#define fll const lll&
#define fc const char&
#define fs const string&
#define debug() puts("Running Successfully!")
using namespace std ;
/*---------------------------------------*/
#if defined(HINA) && defined(_WIN32)
#include<io.h>
struct _Clip {
	FILE *f = _popen("powershell -NoP -c Get-Clipboard 2>nul","r") ;
	_Clip () {if (f) _dup2(_fileno(f),0) ;}
	~_Clip () {if (f) _pclose(f) ;}
}_clip ;
#endif
namespace IO {
	template<class T>inline void read (T &x) {x = 0 ;char c = getchar(),f = 0 ;while (c < 48 || c > 57) {f |= (c == 45),c = getchar() ;}while (c >= 48 && c <= 57) {x = (x << 1) + (x << 3) + (c ^ 48),c = getchar() ;}if (f) {x = ~x + 1 ;}}
	template<class T,class ...Arg>inline void read (T &x,Arg &...arg) {read(x),read(arg...) ;}
	template<class T>inline void write (T x) {if (x < 0) {putchar(45),x = ~x + 1 ;}if (x > 9) {write(x / 10) ;}putchar(x % 10 | 48) ;}
	template<class T>inline void write (T x,fc c) {write(x),putchar(c) ;}
}using namespace IO ;
const int M = 5e5 + 2,N = 502 ;
int T = 1 ;
int c,n,m,d,q ;
ll w[M] ;
vector<pair<int,ll>> g[M] ;
ll ng[N][N] ;
inline void solve () {
	read(c,n,m,d,q) ;
	for (re int i = 1 ; i <= m ; ++i) read(w[i]) ;
	for (re int i = 1,k ; i <= n ; ++i) {
		read(k) ;
		for (re int j = 1,v,val ; j <= k ; ++j) {
			read(v,val) ;
			g[v].emplace_back(i,val) ;
		}
	}
	for (re int i = 1 ; i <= n ; ++i) {
		for (re int j = 1 ; j <= n ; ++j) ng[i][j] = 1e18 ;
		ng[i][i] = 0 ;
	}
	for (re int i = 1 ; i <= m ; ++i) {
		if (g[i].size() < 2) continue ;
		for (re int j = 1 ; j < (int)g[i].size() ; ++j) {
			for (re int k = 0 ; k < j ; ++k) {
				re int u = g[i][j].first,v = g[i][k].first ;
				ng[u][v] = min(ng[u][v],g[i][j].second + g[i][k].second) ;
				ng[v][u] = ng[u][v] ;
			}
		}
	}
	for (re int k = 1 ; k <= n ; ++k) {
		for (re int i = 1 ; i <= n ; ++i) {
			for (re int j = 1 ; j <= n ; ++j) {
				ng[i][j] = min(ng[i][j],ng[i][k] + ng[k][j]) ;
			}
		}
	}
	while (q--) {
		re int u,v ;
		re ll ans = LLONG_MAX ;
		read(u,v) ;
		for (re auto &e1 : g[u]) {
			for (re auto &e2 : g[v]) {
				ans = min(ans,1ll * w[u] + w[v] + e1.second + e2.second + ng[e1.first][e2.first]) ;
			}
		}
		write(ans,endl) ;
	}
}
int main () {
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	solve() ;
	return 0 ;
}
/*
fc D:\c++\subway.out D:\c++\subway7.ans
*/
