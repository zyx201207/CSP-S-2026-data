#include<iostream>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<queue>
#include<fstream>
using namespace std ;
int main( ){
	freopen( "travel.in" , "r" , stdin ) ;
	freopen( "travel.out" , "w" , stdout ) ;
	int a , b , c , d , e , f , g , h ;
	char i , j , k , l , m ;
	cin >> a >> b >> i >> c >> d >> j ;
	if( a != c ){
	    cout << 0 ;
	}
	else{
		cout << 1 ;
	}
	if( a == c && b == d ){
		cout << 1 ;
	}
	else{
		cout << 0 ;
	}
	if( a == c && b == d ){
		if( i <= 'C' && j <= 'C' ){
			cout << 1 ;
		}
		else if( i >= 'D' && j >= 'D' ){
			cout << 1 ;
		}
		else{
			cout << 0 ;
		}
	}
	else{
		cout << 0 ;
	}
	if( a == c && b == d ){
		if( i <= 'C' && j <= 'C' ){
			if( i == 'A' && j == 'B' ){
				cout << 1 ;
			}
			else if( i == 'B' && j == 'A' ){
				cout << 1 ;
			}
			else if( i == 'B' && j == 'C' ){
				cout << 1 ;
			}
			else if( i == 'C' && j == 'B' ){
				cout << 1 ;
			}
			else{
				cout << 0 ;
			}
		}
		else if( i >= 'D' && j >= 'D' ){
			if( i == 'D' && j == 'F' ){
				cout << 1 ;
			}
			else if( i == 'F' && j == 'D' ){
				cout << 1 ;
			}
			else{
				cout << 0 ;
			}
		}
		else{
			cout << 0 ;
		}
	}
	else{
		cout << 0 ;
	}
    return 0 ;
}
