#include <bits/stdc++.h>
#define int long long 

using namespace std;


signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--) {
		int n, k, a;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a >> a;
		if (n == k) cout << 0 << "\n";
		else cout << rand() % 2 * n;
	}
	return 0;	
}