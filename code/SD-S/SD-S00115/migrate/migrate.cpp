#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
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
const int N = 2e6 + 2 ;
int T = 1 ;
int c ;
int n ;
ll a[N],ans,d ;
vector<int> g[N] ;
int dis[N],cnt[N] ;
bool vis[N] ;
inline void dijkstra (fi s) {
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
	fill(dis + 1,dis + 1 + n,2e9) ;
	fill(vis + 1,vis + 1 + n,0) ;
	fill(cnt + 1,cnt + 1 + n,0) ;
	dis[s] = 0,pq.push({0,s}),cnt[s] = 1 ;
	while (pq.size()) {
		re pair<int,int> nd = pq.top() ;
		pq.pop() ;
		re int u = nd.second,minn = nd.first ;
		if (vis[u]) continue ;
		vis[u] = 1 ;
		for (re int v : g[u]) {
			if (dis[v] > minn + 1) {
				dis[v] = minn + 1 ;
				cnt[v] = cnt[u] ;
				pq.push({dis[v],v}) ;
			}
			else if (dis[v] == minn + 1) ++cnt[v] ;
		}
	}
}
inline void solve () {
	read(n,d) ;
	for (re int i = 1 ; i <= n ; ++i) read(a[i]) ;
	for (re int i = 1 ; i <= n ; ++i) {
		re int j = i ;
		while (a[j + 1] - a[i] <= d && j + 1 <= n) ++j ;
		for (re int k = i + 1 ; k <= j ; ++k) g[i].push_back(k) ;
	}
	for (re int i = 1 ; i < n ; ++i) {
		dijkstra(i) ;
		for (re int j = i + 1 ; j <= n ; ++j) {
			if (cnt[j] == 2) ++ans ;
		}
	}
	write(ans,endl) ;
	ans = 0 ;
	for (re int i = 1 ; i <= n ; ++i) g[i].clear() ;
}
int main () {
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	read(c,T) ;
	while(T--) solve() ;
	return 0 ;
}

/*
fc D:\c++\migrate4.ans  D:\c++\migrate.out

I HAVE O(n\log n) BUT WRONG ANSWER!!!!!

only have 24 baoli

MY WC ... T^T

can I have 7 gou?

By _Sorasaki_Hina_ ...


%%% grylls orz
%%% water_lemon orz
%%% winter_forever orz
%%% uid 1077711 orz
%%% yzm6677 orz
%%% _CUI_ orz

they were all AKed ...
*/
