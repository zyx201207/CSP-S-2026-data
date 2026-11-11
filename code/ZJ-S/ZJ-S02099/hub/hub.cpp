#include<bits/stdc++.h>

using namespace std;

#define int long long

int c, t, a[2000001];

vector<int>e[2000001];

signed main ( ) {
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdin);
	cin >> c >> t;
	
	while ( t-- ) {
		
		int n, d;
		
		cin >> n >> d;
		int len = 0;
		for ( int i = 1; i < n; i++ ) {
			int _1, _2;
			cin >> _1 >> _2;
			e[_1].push_back(_2);
			e[_2].push_back(_1);
			a[_1]++;
			a[_2]++;
			len = max({len,_1,_2});
		}
		cout << len << '\n';
		
	}
	
	return 0;
	
}
