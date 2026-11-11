#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m, max = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int k = 2;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			b[k] = b[k] + a[i] - a[j];
			if (b[k] < m && k > max) {
				max = k;
			}
		}
		k++;
	}
	cout << max;
	return 0;
}
