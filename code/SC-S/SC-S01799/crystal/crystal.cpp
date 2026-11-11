#include <bits/stdc++.h>
#define int long long
#define TXT "crystal"
using namespace std;
const int N = 5e5 + 10;
void init() {
	freopen ( TXT".in", "r", stdin );
	freopen ( TXT".out", "w", stdout );
}

int n, m;
int a[N];
int ans = 0;
signed main() {
	init();
	cin >> n >> m;

	for ( int i = 0; i < n; i++ ) {
		cin >> a[i];
	}

	for ( int i = n - 1; i > 0; i-- ) {
		int b = m, cnt = 1;

		while ( b >= 0 && i - cnt >= 0 ) {
			b -= a[i] = a[i - cnt];
			cnt++;
		}

		ans = max ( ans, cnt );
	}

	cout << ans;
	return 0;
}
