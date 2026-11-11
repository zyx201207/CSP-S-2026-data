#include <bits/stdc++.h> 
using namespace std ;

stack <char> q ;

int main() {
	freopen( "string.in" , "r" , stdin ) ;
	freopen( "string.out" , "w" , stdout ) ;
	long long n = 0 ;
	string s ;
	cin >> n ;
	long long cc  = 0 ;
	if ( n % 2 != 0 ) {
		long long a_ , aa ;
		char ch_ ;
		for ( int i = 0 ; i < n / 2 ; i ++ ) {
		long long a = 0 ;
		char ch ;
		cin >> a >> ch ;
		if ( n == n /2 ) {
			for (long long i = 0 ; i < a / 2 ; i ++){
			q.push(a) ;	
			aa = a ;
			a_= i ;
			ch_ = ch;
	}
		}else {
		for (long long i = 0 ; i < a ; i ++){
			q.push(a) ;	
		}
		}
	}
	 for (long long i = a_ ; i < aa ; i ++){
			char cch = q.top() ;
			if ( cch != ch_ ) {
				cc ++ ;
			} 
			q.pop() ;
		}
	for ( int i = n / 2 - 1; i < n ; i ++ ) {
		long long a = 0 ;
		char ch ;
		cin >> a >> ch ;
		for (long long i = 0 ; i < a ; i ++){
			char cch = q.top() ;
			if ( cch != ch ) {
				cc ++ ;
			} 
			q.pop() ;
		}
	}
	} else {
	for ( int i = 0 ; i < n / 2 ; i ++ ) {
		long long a = 0 ;
		char ch ;
		cin >> a >> ch ;
		for (long long i = 0 ; i < a ; i ++){
			q.push(a) ;	
		}
	}
	for ( int i = n / 2 ; i < n ; i ++ ) {
		long long a = 0 ;
		char ch ;
		cin >> a >> ch ;
		for (long long i = 0 ; i < a ; i ++){
			char cch = q.top() ;
			if ( cch != ch ) {
				cc ++ ;
			} 
			q.pop() ;
		}
	}
	}	
	
	cout << cc ;
		
	return 0 ;
}
