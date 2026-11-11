/*

Start Code At 2026/10/31 14:33:31.

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


ll m , sum ;
int n , ans , a[MN] ;
priority_queue<int> q ;

inline bool solve()
{
	
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; ++ i)  cin >> a[i] ;
	sort(a+1 , a+n+1) ;
	for(int i = 1 ; i <= n ; ++ i) {
		if(i < n && a[i] == a[i+1]) {
			q .push(-a[i]) , sum += -a[i] ;
		}
		else {
			q .push(-a[i]) , sum += -a[i] ;
			ll val = static_cast<ll>(q.size())*static_cast<ll>(a[i]) ;
			while(sum + val > m) {
				sum -= q.top() , val -= a[i] , q.pop() ;
			}
			ans = max(ans , static_cast<int>(q.size())) ;
		}
	}
	cout << ans << '\n' ;
	
	return 0 ;
}

signed main()
{
	freopen("crystal.in" , "r" , stdin) ;
	freopen("crystal.out" , "w" , stdout) ;
	
	cin.tie(0) -> sync_with_stdio(0) ;
	
//	system("fc crystal.out crystal4.ans") ;
	
//	int __T_ ;  cin >> __T_ ;  while(__T_ --)  solve() ;
	
//	while(!solve()) ;
	
	solve() ;
	
	return 0 ;
}

/*
passkey is `Oct31==Dec25?`.
trans: jin tian shi sheng dan ma?
*/