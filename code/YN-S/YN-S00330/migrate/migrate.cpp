#include <bits/stdc++.h>
using namespace std;
long long num[2000100];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		long long n, m, sum = 0;
		cin >> n >> m;
		for (int j = 1; j <= n; j++) {
			cin >> num[j];
		}
		long long cnt = m * 2 - 1;
		for (int j = 4; j <= n; j++) {
			if (num[j] - num[j - 3] == cnt && num[j] - num[j - 1] <= m && num[j - 1] - num[j - 2] <= m) {
				sum++;
			}
		}
		cout << sum << endl;
	}
	return 0;
}
