#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
using namespace std ;
long long n[220000] ;
char o[220000] ;
int main( ){
	freopen( "string.in" , "r" , stdin ) ;
	freopen( "string.out" , "w" , stdout ) ;
	long long a , b , c , d , e , f , g , h ;
	char i , j , k , l , m ;
	cin >> a ;
	for( b = 0 ; b < a ; b += 1 ){
		cin >> n[b] >> o[b] ;
	}
	c = 0 , d = a - 1 , e = n[c] , f = n[d] , i = o[c] , j = o[d] , g = 0 ;
	while( c < d ){
		if( e > f ){
			if( i != j ){
				g += f ;
			}
			e -= f ;
			d -= 1 ;
			if( c == d || d < 0 ){
				break ;
			}
			f = n[d] , j = o[d] ;
		}
		else if( e < f ){
			if( i != j ){
				g += e ;
			}
			f -= e ;
			c += 1 ;
			if( c == d || c >= a ){
				break ;
			}
			e = n[c] , i = o[c] ;
		}
		else if( e == f ){
			if( i != j ){
				g += e ;
			}
			c += 1 , d -= 1 ;
			if( c == d || c >= a || d < 0 ){
				break ;
			}
			e = n[c] , f = n[d] , i = o[c] , j = o[d] ;
		}
	}
	cout << g << endl ;
	return 0 ;
}
