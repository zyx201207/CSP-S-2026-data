#include <bits/stdc++.h>
using namespace std;
long long n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long a[n + 3] = {}, cnt = 0, g = 0, s = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int j = n; j >= 1; j--) {
		long long d = a[j], sum = 0;
		for (int i = 1; i <= j; i++) {
			sum += d - a[i];
			cnt ++;
			if (sum > m) {
				sum = sum - d + a[i - 1];
				cnt --;
				break;
			}

		}
		if (g < sum) {
			g = sum;
			s = cnt;
		}

	}
	cout << s;
	return 0;
}