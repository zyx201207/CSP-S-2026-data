#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long mx = 0, sum;
	cin >> a[0];
	sum = a[0];

	for (int i = 1; i < n; i++) {

		cin >> a[i];
		sum = sum & a[i];
		mx = max(mx, a[i]);
	}

	if (n == m) {
		cout << sum;
	} else if (m == 1) {
		cout << mx;
	} else {
		sort(a, a + n, cmp);
		cout << a[m - 1];
	}

	return 0;
}