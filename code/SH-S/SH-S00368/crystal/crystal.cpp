#include<bits/stdc++.h> 
using namespace std ;

long long a[500010] = {} ;
int n ;
long long m ;
long long plu[500010] = {} ;        //前缀和 

int numb( int x ) {              //选择x作为基准能量时从哪颗石子开始可以合成 
	int end = 0 ;
	int s = 1 ; 
	int e = n ;
	int mid = (s+e) / 2 ;
	while ( s <= e ) {
		if ( a[mid] <= x ) {
			s = mid + 1 ;
			end = mid ;
		}
		else {
			e = mid - 1 ;
		}
		mid = (s+e) / 2 ;
	}
	return end ;
}

int counting( int y ) {           //y作为基准能量，有多少石子可以合成  
	int tar = 0 ;
	int end = numb(y) ;
	if ( end == 1 ) {
		return 1 ;
	}
	int s = 1 ;
	int e = end ;
	int mid = (s+e) / 2 ;
	while ( s <= e ) {
		if ( y * (end-mid+1) - (plu[end] - plu[mid-1]) <= m ) {
			e = mid - 1 ;
			tar = mid ;
		}
		else {
			s = mid + 1 ;
		}
		mid = (s+e) / 2 ;
	}
	return (end - tar + 1) ;
}

int main () {
	freopen( "crystal.in" , "r" , stdin ) ;
	freopen( "crystal.out" , "w" , stdout ) ;
	cin >> n >> m ;
	if ( n == 1 ) {
		cout << 1 ;
		return 0 ;
	}
	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> a[i] ;
	}
	sort ( a + 1 , a + n + 1 ) ;
	for ( int i = 1 ; i <= n ; i ++ ) {
		plu[i] = plu[i-1] + a[i] ;
	}
	
	int ans = 1 ;
	if ( m > 1000000000 ) {
		for ( int i = a[n-1] ; i <= a[n] ; i ++ ) {
			if ( counting(i) > ans ) {
				ans = counting(i) ;
			}
		}
		cout << ans ;
		return 0 ;
	}
	for ( int i = a[1] ; i <= a[n] ; i ++ ) {
		if ( counting(i) > ans ) {
			ans = counting(i) ;
		}
	}
	cout << ans ;
	return 0 ;
}
