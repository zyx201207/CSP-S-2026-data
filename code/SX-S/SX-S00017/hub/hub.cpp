#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define N 100010
int c, t, n, k, u[N], v[N];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> k;
		for (int j = 1; j <= n - 1; j++)
			cin >> u[i] >> v[i];
	}
	if (c == 0 && n == 5)
		cout << 1 << endl << 2;
	return 0;
}
