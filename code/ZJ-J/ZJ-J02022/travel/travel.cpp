#include<bits/stdc++.h>
using namespace std ;

string xc , xs , rc , rs ;

int main(){
	freopen( "travel.in" , "r" , stdin ) ;
	freopen( "travel.out" , "w" , stdout ) ;
	
	cin >> xc >> xs >> rc >> rs ;
	
	if ( xc == rc ){
		cout << "1" ;
		if ( xs[0] == rs[0] && xs[1] == rs[1] ){
			cout << "1" ;
			if ( xs[2] == 'A' ){
				if ( rs[2] == 'B' ){
					cout << "11" ;
				}else if ( rs[2] == 'C' ){
					cout << "10" ;
				}else{
					cout << "00" ;
				}
			}else if ( xs[2] == 'B' ){
				if ( rs[2] == 'A' || rs[2] == 'C' ){
					cout << "11" ;
				}else{
					cout << "00" ;
				}
			}else if ( xs[2] == 'C' ){
				if ( rs[2] == 'A' ){
					cout << "10" ;
				}else if ( rs[2] == 'B' ){
					cout << "11" ;
				}else{
					cout << "00" ;
				}
			}else if ( xs[2] == 'D' ){
				if ( rs[2] == 'F' ){
					cout << "11" ;
				}else{
					cout << "00" ;
				}
			}else if ( xs[2] == 'F' ){
				if ( rs[2] == 'D' ){
					cout << "11" ;
				}else{
					cout << "00" ;
				}
			}
		}else{
			cout << "000" ;
		}
	}else{
		cout << "0000" ;
	}
	
	
	
	return 0 ;
}
