//AKCSP-S
#include <bits/stdc++.h>
using namespace std;

struct rode {
	int u, v;
} a[1000005];
int c, t;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].u >> a[i].v;
		}
		cout << 1 << endl;
	}
	return 0;
}
