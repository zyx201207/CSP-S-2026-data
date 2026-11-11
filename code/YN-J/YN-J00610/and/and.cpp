#include <bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b) {
	return a < b;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long a[200005];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	if (n % 2 != 0)
		n = n / 2 + 1;
	else
		n /= 2;
	cout << a[n];
	return 0;
}