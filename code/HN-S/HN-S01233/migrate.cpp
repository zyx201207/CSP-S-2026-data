# include <bits/stdc++.h>
# define int long long 
# define pb push_back
using namespace std ;
constexpr int N = 2e6 + 5 , INF = 1e18 ;  
int cid , T , n , d , a[N] ; 
namespace brute {
	vector < int > g[N] ;
	int dis[N] ;   
	pair < int , bool > cnt[N] ; 
	pair < int , bool > merge ( pair < int , bool > now , pair < int , bool > pre ) {
		if ( pre.second ^ 1 ) return { 0 , 0 } ; if ( now.second ^ 1 ) return { 0 , 0 } ; 
		if ( now.first + pre.first <= 2 ) return { now.first + pre.first , 1 } ; 
		return { 0 , 0 } ; 
	}
	int calc ( int RT ) {
		queue < int > q ; int res = 0 ; 
		for ( int i = 1 ; i <= n ; ++ i ) dis[i] = INF , cnt[i] = { 0 , 1 } ; 
		q.push ( RT ) , cnt[RT] = { 1 , 1 } , dis[RT] = 0 ; 
		while ( ! q.empty () ) {
			int u = q.front () ; q.pop () ; 
			for ( auto & v : g[u] ) {
				if ( dis[v] > dis[u] + 1 ) q.push ( v ) , dis[v] = dis[u] + 1 , cnt[v] = cnt[u] ; 
				else if ( dis[v] == dis[u] + 1 ) cnt[v] = merge ( cnt[v] , cnt[u] ) ; 
			}
		}  
		for ( int i = RT + 1 ; i <= n ; ++ i ) if ( cnt[i].second && cnt[i].first == 2 ) ++ res ;
		return res ; 
	}
	void main () {
		for ( int i = 1 ; i <= n ; ++ i ) g[i].clear () ; int res = 0 ; 
		for ( int i = 1 ; i <= n ; ++ i ) for ( int j = i + 1 ; j <= n ; ++ j ) 
			if ( a[j] - a[i] <= d ) g[i].pb ( j ) , g[j].pb ( i ) ; 
		for ( int i = 1 ; i <= n ; ++ i ) res += calc ( i ) ; 
		return cout << res << '\n' , void () ; 
	}
}
int nxt[N] ;
void solve () {
	cin >> n >> d ; for ( int i = 1 ; i <= n ; ++ i ) cin >> a[i] ; 
	if ( n <= 5000 ) return brute :: main () , void () ; 
	else if ( cid >= 11 && cid <= 12 ) {
		int diff = a[2] - a[1] ; 
		if ( diff > d ) return cout << "0\n" , void () ; 
		int lim = d / diff ; 
		if ( lim == 1 ) return cout << "0\n" , void () ; 
		int step = ( 2ll * lim - 1 ) * diff ; 
		for ( int i = 1 ; i <= n ; ++ i ) if ( a[i] - a[1] == step ) return cout << n - i + 1 << '\n' , void () ; 
		return cout << "0\n" , void () ; 
	}
	for ( int i = 1 ; i <= n ; ++ i ) {
		int rpos = 0 , l = i , r = n ; 
		while ( l <= r ) {
			int mid = ( l + r ) >> 1 ;
			if ( a[mid] - a[i] <= d ) rpos = mid , l = mid + 1 ; 
			else r = mid - 1 ;  
		}
		nxt[i] = rpos ; 
	}

}
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) ; 
	freopen ( "migrate.in" , "r" , stdin ) , freopen ( "migrate.out" , "w" , stdout ) ; 
	cin >> cid >> T ; while ( T -- ) solve () ; return 0 ; 
}
// 也就是说，几乎顶到上界，只能换位一次，你贪心的去跳是类似子序列自动机的东西
// 这个图应该是在某一位找到一个替换，后面的全部都是和贪心一样的跳
// 希望找到nxt_i表示最远跳跃点，则中间的所有点全部可以通过一次达成
// 对u扫描线，然后[u,nxt_u]中间从u跳一次,[nxt_u,nxt_{nxt_u}] 跳两次，以此类推
// 对(u , nxt_u] 中的i，所管辖的"跳一次"的区间[i,nxt_i]做区间覆盖
// 在[nxt_u,nxt_{nxt_u}]中覆盖次数为恰好一次的就是我们需要的点
// 曹了这个有更好做吗，先写写后面暴力/ll
