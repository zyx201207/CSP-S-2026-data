#include <bits/stdc++.h>
using namespace std;
//#define int long long
//#define ll long long
//#define ull unsigned long long
const int N = 2e6 + 10;
int u[N], v[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k;
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) cin >> u[i] >> v[i];
		cout << n / k - 1 << "\n";
	}
	return 0;
}
