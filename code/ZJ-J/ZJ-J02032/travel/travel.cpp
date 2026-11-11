#include<bits/stdc++.h>

using namespace std;

#define int long long

string c1, s1, c2, s2, com1, com2;

bool q1, q2, q3, q4;

map < char, int > mp = { { 'A', 1 }, { 'B', 2 }, { 'C', 3 }, { 'D', 99 }, { 'F', 100 } };

signed main ( ) {
	
	freopen ( "travel.in", "r", stdin );
	
	freopen ( "travel.out", "w", stdout );
	
	ios::sync_with_stdio ( 0 );
	
	cin.tie ( 0 );
	
	cout.tie ( 0 );
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if ( c1 == c2 ) q1 = 1;
	
	else {
		
		cout << "0000";
		
		return 0;
		
	}
	
	if ( s1[0] == s2[0] && s1[1] == s2[1] ) {
		
		q2 = 1;
		
	}
	
	else {
		
		cout << "1000";
		
		return 0;
		
	}
	
	if ( abs ( mp[ s1[2] ] - mp [ s2[2] ] ) < 3 ) {
		
		q3 = 1;
		
	}
	
	else {
		
		cout << "1100";
		
		return 0;
		
	}
	
	if ( abs ( mp[ s1[2] ] - mp[ s2[2] ] ) == 1 ) {
		
		q4 = 1;
		
	}
	
	else {
		
		cout << "1110";
		
		return 0;
		
	}
	
	cout << "1111";
	
	return 0;
	
}
