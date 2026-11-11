#include<bits/stdc++.h>
using namespace std;
const int N = 3 + 5e5;
int c, t;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--) {
		int n, k, u[N], v[N];
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
		}
		n /= 8;
		int qwq = n % k;
		qwq /= 2;
		cout << n - qwq + 1;
	}
	return 0;
}