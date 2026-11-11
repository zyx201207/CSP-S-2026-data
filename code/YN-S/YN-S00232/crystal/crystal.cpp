#include <bits/stdc++.h>
using namespace std;

long long n, m, d = 1, same;
long long a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] == a[j]) {
				same++;
			}
		}
	}
	while (m - (a[same + 1] - a[same])*same >= 0) {
		m -= (a[same + 1] - a[same]) * same;
		a[same] = a[same + 1];
		same++;
	}
	cout << same;
	return 0;
}