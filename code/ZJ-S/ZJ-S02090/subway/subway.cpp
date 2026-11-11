#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;

long long c , n , m , d , q ;
long long w[N] , k[510] , t[N] ;
long long mp[510][510] ;
long long vis[N] ;
long long ans[N] ;

void dp ( long long x ){
	for ( long long i = 1 ; i <= m ; i++ ){
		if ( mp[x][i] = 1 && !vis[i] ){
			ans[i] = ans[x] + w[i] + t[i] ;
			vis[i] = 1 ;
			dp( i ) ;
		}
	}
}

int main(){
	freopen ( "subway.in" , "r" , stdin ) ;
	freopen ( "subway.out" , "w" , stdout ) ;
	
	cin >> c >> n >> m >> d >> q ;
	for ( long long i = 1 ; i <= m ; i++ ){
		cin >> w[i] ;
	}
	for ( long long i = 1 ; i <= n ; i++ ){
		cin >> k[i] ;
		for ( long long j = 1 ; j <= 2 * k[i] ; j += 2 ){
			long long u , v , f = 0 ;
			cin >> u ;
			cin >> v ;
			mp[u][f] = mp[f][u] = 1 ;
			f = u ;
			t[u] = v ;
		}
	}
	while ( q-- ){
		long long x , y ;
		cin >> x >> y ;
		memset ( ans , 5e5+10 , sizeof ans ) ;
		ans[x] = w[x] + t[x] ;
		memset ( vis , 0 , sizeof vis ) ;
		vis[x] = 1 ;
		dp( x ) ;
		cout << ans[y] << "\n" ;
	}
	
	return 0 ;
}
