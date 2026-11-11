#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	int cnt = 1;
	int sum = 0;

	for (int i = 1; i <= m; i++) {

		if ((a[i + 1] + a[i]) % 2 == 1 and sum <= n) {
			sum ++;
		}
	}

	cout << sum;
	return 0;
}
