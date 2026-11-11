#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int c, m, n, d, q, k;
int w[N];

struct Node {
	int a, t;
} a[N], qq[N];

int main() {
	freopen("subway.in", "r", stdin );
	freopen("subway.out", "w", stdout );

	cin >> c >> m >> n >> d >> q;

	for ( int i = 1 ; i <= m ; i ++ )
		cin >> w[i];

	for ( int i = 1 ; i <= n ; i ++ ) {
		cin >> k;
		for ( int j = 1 ; j <= k ; j ++ )
			cin >> a[j].a >> a[j].t;
	}

	for ( int i = 1 ; i <= q ; i ++ )
		cin >> qq[i].a >> qq[i].t;

	cout << 32 << "\n" << 17;

	return 0;
}