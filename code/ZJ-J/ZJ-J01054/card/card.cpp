#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
using namespace std ;
int n[560000] ;
int o[560000] ;
int p[340000] ;
int t[340000] ;
int main( ){
	freopen( "card.in" , "r" , stdin ) ;
	freopen( "card.out" , "w" , stdout ) ;
	int a , b , c , d , e , f , g , h , i , j , k , l , m ;
	cin >> a >> b ;
	for( c = 0 ; c < a ; c += 1 ){
		cin >> n[c] ;
	}
	if( a <= 5000 ){
		for( c = 0 ; c < a ; c += 1 ){
	    	e = 0 ;
	    	for( f = 1 ; f <= b ; f += 1 ){
	    		p[f] = -1 ;
	    	}
	    	for( d = c ; d < a ; d += 1 ){
	    		if( p[ n[d] ] == -1 ){
	    			o[e] = n[d] ;
	    			p[ n[d] ] = e ;
	    			e += 1 ;
	    		}
	    		else{
	    			for( f = p[ n[d] ] + 1 ; f < e ; f += 1 ){
	    				p[ o[f] ] = -1 ;
	    			}
	    			e = p[ n[d] ] + 1 ;
	    		}
    		}
	    	for( f = 1 ; f <= b ; f += 1 ){
	    		if( p[f] != -1 ){
	    			t[f] += 1 ;
	    		}
	     	}
    	}
    }
    else{
    	for( c = 0 ; c < a ; c += 1 ){
		    if( n[c] == n[ a - 1 ] ){
		    	t[ n[c] ] += 1 ;
			}
			else{
				t[1] += 1 , t[2] += 1 ;
			}
		}
	}
	for( f = 1 ; f <= b ; f += 1 ){
		cout << t[f] << ' ' ;
	}
	cout << endl ;	
		
	return 0 ;
}
