#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], sum, num;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long b;
	if (n % 2 == 1) {
		b = a[n / 2 + 1];
	} else {
		b = (a[n / 2] + a[n / 2 + 1]) / 2;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] > b) {
			n = i - 1;
			break;
		}
	}
	for (int i = n; i >= 1; i--) {
		if (a[i] == b) {
			sum++;
		} else {
			if (m - (b - a[i]) > 0) {
				sum++;
			} else {
				break;
			}
		}
	}
	int i = n + 1;
	while (m - sum * (a[i] - b) > 0) {
		sum++;
		m -= sum * (a[i] - b);
		i++;
	}
	cout << sum;
	return 0;
}