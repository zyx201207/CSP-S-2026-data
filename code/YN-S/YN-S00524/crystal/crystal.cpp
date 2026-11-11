#include <bits/stdc++.h>
using namespace std;

int n, m, re[500005], xc[500005], dan, danmax;


int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> re[i];
	}

	sort(re + 1, re + 1 + n);

	int a = n / 2;

	if (n % 2 != 0) {
		a++;
	}

	int ans = a - sqrt(n) / 2;

	while (ans <= a + sqrt(n) / 2) {
		for (int i = 1; i <= n; i++) {

			xc[i] = abs(re[i] - re[ans]);
		}

		sort(xc + 1, xc + 1 + n);

		int b = m;

		for (int i = 1; i <= n; i++) {

			if (xc[i] <= b) {
				dan++;
				b -= xc[i];
			} else {
				break;
			}
		}

		danmax = max(danmax, dan);

		dan = 0;

		ans++;
	}

	cout << danmax;

	return 0;
}