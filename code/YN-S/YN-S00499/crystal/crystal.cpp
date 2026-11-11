#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5;
int n, m, a[N], sum = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += 1;
	}
	for (int i = 1; i <= m ; i++) {

		if (a[i] == a[i]) {
			sum++;
		}

	}
	cout << sum;
	freopen("crystal.out", "w", stdout);
	return 0;
}