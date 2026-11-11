#include <bits/stdc++.h>
using namespace std;

long long t, n, c, a[1000005], k;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
			cin >> a[i] >> a[i + 1];
			
		cout << k << endl;
	}
	return 0;
} 
