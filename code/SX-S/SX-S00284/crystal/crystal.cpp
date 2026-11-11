#include <bits/stdc++.h>
using namespace std;
long long int n, m, N[500005], sum = 0, n1 = 0, m1 = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> N[i];
	}
	sort(N + 1, N + n + 1);
	for (int i = 1; i <= n; i++) {
		m1 = 0, n1 = 0;
		for (int k = i; k <= n; k++) {
			if (m1 < m) {
				m1 += (N[k + 1] - N[k]) * (k - i + 1);
			}
			if (m1 == m) {
				n1 = k - i + 2;
				for (int k1 = n1; k1 <= n; k++) {
					if (N[n1] == N[n1 + 1]) {
						n1++;
					} else {
						break;
					}
				}
				break;
			}
			if (m1 > m) {
				n1 = k - i + 1;
				break;
			}
		}
		if (n1 > sum) {
			sum = n1;
		}

	}
	cout << sum;
	return 0;
}
