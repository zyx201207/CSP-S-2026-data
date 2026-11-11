#include<bits/stdc++.h>
using namespace std ;

long long n , ans = 0 ;
string s = " " ;

int main(){
	freopen( "string.in" , "r" , stdin ) ;
	freopen( "string.out" , "w" , stdout ) ;
	
	scanf( "%lld" , &n ) ;
	
	long long l = 0 ;
	for ( long long i = 1 ; i <= n ; i++ ){
		long long k ;
		string x ;
		cin >> k >> x ;
		l += k ;
		for ( long long j = 1 ; j <= k ; j++ ){
			s += x ;
		}
	}
	for ( long long i = 1 ; i <= ( l + 1 ) / 2 ; i++ ){
		if ( s[i] != s[l-i+1] ){
			ans++ ;
			s[i] = s[l-i+1] ;
		}
	}
	cout << ans ;
	
	
	return 0 ;
}
