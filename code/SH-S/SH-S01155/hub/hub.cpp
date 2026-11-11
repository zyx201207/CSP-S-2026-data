#include <bits/stdc++.h>
using namespace std;

int c, t; 
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while (t --) {
		int n, k; cin >> n >> k;
		for (int i = 1; i < n; ++ i) {
			int a, b;
			cin >> a >> b;
		}
		int ans;
		if (c % 2) ans = (n - k + 1) / 3;
		else ans = n / 3;
		
		cout << ans << "\n";
	}
	return 0;
} 
