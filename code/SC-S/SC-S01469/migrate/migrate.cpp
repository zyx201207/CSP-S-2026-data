/*

Start Code At 2026/10/31 15:58:51.

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
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/


ll d , ans , a[MN] ;
int n , dis[5010][5010] , cnt[5010][5010] ;

inline bool solve()
{
	for(int i = 1 ; i <= n ; ++ i)  for(int j = 1 ; j <= n ; ++ j)  dis[i][j] = cnt[i][j] = 0 ;
	for(int i = 1 ; i <= n ; ++ i)  a[i] = 0 ;
	ans = d = 0 , n = 0 ;
	
	cin >> n >> d ;
	for(int i = 1 ; i <= n ; ++ i)  cin >> a[i] ;
	for(int i = 1 ; i <= n ; ++ i)  for(int j = i ; j <= n ; ++ j)  dis[i][j] = inf , cnt[i][j] = 0 ;
	for(int i = 1 ; i <= n ; ++ i) {
		dis[i][i] = 0 , cnt[i][i] = 1 ;
		for(int j = i+1 ; j <= n ; ++ j) {
			for(int k = j-1 ; k >= i ; -- k) {
				if(a[j]-a[k] <= d) {
					if(dis[i][j] > dis[i][k]+1)  dis[i][j] = dis[i][k]+1 , cnt[i][j] = 1 ;
					else if(dis[i][j] == dis[i][k]+1) {
						cnt[i][j] += cnt[i][k] ;
						if(cnt[i][j] > 3)  cnt[i][j] = 3 ;
					}
				}
				else  break ;
			}
		}
	}
	for(int i = 1 ; i <= n ; ++ i) {
		for(int j = i+1 ; j <= n ; ++ j) {
			ans += cnt[i][j] == 2 ;
		}
	}
	cout << ans << '\n' ;
	
	return 0 ;
}

signed main()
{
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	
	cin.tie(0) -> sync_with_stdio(0) ;
	
//	system("fc migrate.out migrate3.ans") ;
	
	int __c_ , __T_ ;  cin >> __c_ >> __T_ ;  while(__T_ --)  solve() ;
	
//	while(!solve()) ;
	
//	solve() ;
	
	return 0 ;
}

/*
16:38:39 ma bao li dou bu hui da zen me ban. ke wu.
*/