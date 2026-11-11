#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen( "travel.in" , "r" , stdin );
	freopen( "travel.out" , "w" , stdout );
	int c1 , c2;
	string s1 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int a = ( s1[0] - '0' ) * 10 + ( s1[1] - '0' );
	int b = ( s2[0] - '0' ) * 10 + ( s2[1] - '0' );
	int sa = ( s1[2] - 'A' );
	int sb = ( s2[2] - 'A' );
	if( c1 != c2 ){
		cout << "0000";
	}else if( a != b ){
		cout << "1000";
	}else if( ( sa > 2 && sb <= 2 ) ||  ( sa <= 2 && sb > 2 )){
		cout << "1100";
	}else if( sa != sb - 1 && sb != sa - 1 ){
		cout << "1110";
	}else{
		cout << "1111";
	}
	fclose( stdin );
	fclose( stdout );
	return 0;
}
