#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50;

int a[N], b[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	if (n % 2 == 0) {
		cout << a[n / 2] << "\n";
	} else {
		cout << a[n / 2 + 1] << "\n";
	}

	return 0;
}