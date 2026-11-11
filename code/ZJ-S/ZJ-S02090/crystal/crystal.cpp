#include<bits/stdc++.h>
using namespace std ;

const int N = 5e5 + 10 ;

long long n , m , ans = 1 ;
long long a[N] ;

long long check ( long long x ){
	long long t = x , sum = m , cnt = 0 ;
	while ( sum > 0 && t > 0 ){
		if ( sum >= ( a[t] - a[t-1] ) ){
			sum -= ( a[t] - a[t-1] ) ;
			cnt++ ;
			t-- ;
		}else{
			break ;
		}
	}
	return cnt ;
}

int main(){
	freopen ( "crystal.in" , "r" , stdin ) ;
	freopen ( "crystal.out" , "w" , stdout ) ;
	
	scanf( "%lld" , &n ) ;
	scanf( "%lld" , &m ) ;
	
	for ( long long i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
	}
	sort ( a + 1 , a + n + 1 ) ;
	for ( long long i = 2 ; i <= n ; i++ ){
		if ( a[i] == a[i+1] ){
			continue ;
		}
		ans = max ( ans , check ( i ) ) ;
	}
	cout << ans ;
	
	return 0 ;
}
