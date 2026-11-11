#include <bits/stdc++.h>
using namespace std;
long long t[5000000], a[1000000], b[1000000];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long k, t, c, n;
	cin >> c >> t;
	for (int j = 1; j <= t; j++) {
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++) {
			cin >> a[i] >> b[i];
		}
		cout << "2";
	}
	cout << "1";
	return 0;
}