#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<fstream>
using namespace std ;
bool n[220000][40] ;
long long o[220000][40] ;
long long p[220000] ;
long long x[40] ;
int main( ){
	freopen( "and.in" , "r" , stdin ) ;
	freopen( "and.out" , "w" , stdout ) ;
	long long a , b , c , d , e , f , g , h , i , j , k , l , m ;
	cin >> a >> b ;
	for( c = 1 ; c <= a ; c += 1 ){
	    cin >> p[c] ;
	}
	e = 1 ;
	for( d = 0 ; d < 32 ; d += 1 ){
		x[d] = e ;
		e *= 2 ;
	}
	sort( p + 1 , p + a + 1 ) ;
	for( c = 1 ; c <= a ; c += 1 ){
		f = 1 ;
		for( d = 0 ; d < 32 ; d += 1 ){
			e = p[c] % ( f * 2 ) / f ;
			if( e == 1 ){
				n[c][d] = true ;
			}
			else{
				n[c][d] = false ;
			}
			f *= 2 ;
		}
	}
	for( d = 0 ; d < 32 ; d += 1 ){
		for( c = 1 ; c <= a ; c += 1 ){
			if( n[c][d] == true ){
				o[c][d] = o[ c - 1 ][d] + 1 ;
			}
			else{
				o[c][d] = o[ c - 1 ][d] ;
			}
		}
	}
	h = 0 , i = 1 , j = a ;
	for( d = 31 ; d >= 0 ; d -= 1 ){
		if( o[j][d] - o[ i - 1 ][d] < b ){
			continue ;
		}
		else{
			h += x[d] ;
			for( g = i ; g <= j ; g += 1 ){
				if( n[g][d] == true ){
					i = g ;
					break ;
				}
			}
		}
	}
	cout << h << endl ;
	return 0 ;
}
