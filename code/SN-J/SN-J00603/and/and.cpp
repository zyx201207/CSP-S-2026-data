#include <bits/stdc++.h> 
using namespace std ;

long long a[200005] = {0} ;

int main() {
	freopen( "and.in" , "r" , stdin ) ;
	freopen( "and.out" , "w" , stdout ) ;
	long long n = 0 , m = 0 ;
	cin >> n >>m ;
	for (int i =0 ; i < n ; i ++) {
		cin >> a[i] ;
	}
	sort( a , a + n ) ;
	cout << a[n - m] ;
	
	return 0 ;
}
