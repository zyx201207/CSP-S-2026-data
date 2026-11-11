#include <bits/stdc++.h>
using namespace std;
int n, m, sum;

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	long long a[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	sum = a[1];

	for (int i = 1; i <= m; i++) {
		sum &= a[i];
	}
	cout << sum;
	return 0;
}