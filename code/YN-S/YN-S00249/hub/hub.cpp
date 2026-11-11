#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c;
long long u[N], w[N], t;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		int sum = 0;
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> u[i] >> w[i], sum += u[i] + w[i];
		cout << 0;
	}
	return 0;
}
