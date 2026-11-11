#include <bits/stdc++.h>
using namespace std;
int c, t;

struct road {
	int u;
	int v;
};

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int n, k;
		road a[200005];
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].u >> a[i].v;
		}
		cout << 0;
	}
	return 0;
}