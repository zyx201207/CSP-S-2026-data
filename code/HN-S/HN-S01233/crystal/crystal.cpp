# include <bits/stdc++.h>
# define int long long 
using namespace std ;
constexpr int N = 5e5 + 5 ; 
int n , m , a[N] , sum[N] , res ;
signed main () {
	ios::sync_with_stdio ( false ) , cin.tie ( 0 ) ; 
	freopen ( "crystal.in" , "r" , stdin ) , freopen ( "crystal.out" , "w" , stdout ) ; 
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; ++ i ) cin >> a[i] ; 
	sort ( a + 1 , a + n + 1 ) ;
	int l = 1 ; 
	for ( int i = 1 ; i <= n ; ++ i ) {
		sum[i] = sum[i - 1] + a[i] ; 
		while ( l <= i && ( i - l + 1 ) * a[i] - ( sum[i] - sum[l - 1] ) > m ) ++ l ; 
		res = max ( res , i - l + 1 ) ; 
	} 
	return cout << res << '\n' , 0 ; 
}