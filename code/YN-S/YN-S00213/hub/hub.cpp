#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	int n, k;
	string u, v;
	cin >> c >> t;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		cin >> u[i] >> v[i];
		cout << u[i] - v[i];
	}

	return 0;
}