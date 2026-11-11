#include <bits/stdc++.h>
using namespace std;

int c, t;
int n, k;
int u, v;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> u >> v;
		}
		cout << t << endl;
	}
	return 0;
}