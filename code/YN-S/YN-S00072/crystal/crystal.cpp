#include <bits/stdc++.h>
using namespace std;
int n, a[500010], sum[500010], cz,  maxn = -100;
long long m, num;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		sum[i - 1] = abs(a[i] - a[i - 1]);
		//cout << sum[i - 1] << endl;
	}
	for (int i = 1; i <= n; i++) {
		num = 0;
		for (int j = i; j <= n - 1; j++) {
			num = num + sum[j] * (j + 1  - i);

			//cout << i << "  " << j << "  " << sum[i] << " " << num << " " << maxn << endl;
			if (num > m) {
				maxn = max(maxn, j + 1 - i );
				if (maxn >= n - j ) {
					cout << maxn;
					return 0;
				}
				break;
			}
			maxn = max(maxn, j + 1 - i);
		}
	}
	cout << maxn;
	return 0;
}