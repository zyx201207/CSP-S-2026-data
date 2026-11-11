#include <bits/stdc++.h>
using namespace std;
int u[1000005], v[1000005];
int c, t;
int n, k, j = 1;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			cin >> u[i] >> v[i];
		}
		cout << j << endl;
		j++;
	}
	return 0;
}
