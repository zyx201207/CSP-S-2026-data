#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define ull unsigned ll  

int main() {
	freopen( "string.in", "r", stdin );
	freopen( "string.out", "w", stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr );
	int n;
	cin >> n;
	int x;
	char c;
	string str;
	while ( n -- ) {
		cin >> x >> c;
		str += string( x, c );
	}
//	cout << str << endl;
	ull count{ 0 };
	for ( size_t i{ 0 }; i < str.size() / 2; i ++ ) {
		count += ( str[ i ] != str[ str.size() - i - 1 ] );
//		if ( str[ i ] != str[ str.size() - i ] ) cout << i << ':' << str[ i ] << ' ' << str.size() - i << ':' << str[ str.size() - i - 1 ] << endl;
	}
	cout << count << endl;
	return 0;
}
