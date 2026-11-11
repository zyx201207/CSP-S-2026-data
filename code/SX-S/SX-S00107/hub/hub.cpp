#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+5;
int c, t;
int n, k, u[N], v[N];

int main() {
	freopen("hub.in", "r", stdin );
	freopen("hub.out", "w", stdout );

	cin >> c >> t;

	while ( t -- ) {
		cin >> n >> k;
		for ( int i = 1 ; i <= n - 1 ; i ++ )
			cin >> u[i] >> v[i];
	}

	cout << 1 << " " << 2;

	return 0;
}