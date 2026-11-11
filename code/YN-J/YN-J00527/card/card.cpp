#include <bits/stdc++.h>
using namespace std ;

vector<int> a;

int main() {
	ios::sync_with_stdio(0) ;
	cin.tie(0) ;
	freopen("card.in", "r", stdin) ;
	freopen("card.out", "w", stdout) ;
	int n, m ;
	cin >> n >> m ;

	for ( int i = 1 ; i <= n ; i ++ ) {

		int x ;
		cin >> x ;
		a.push_back(x) ;
	}

	cout << 0 ;
	return 0 ;
}