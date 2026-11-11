#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m, a[N], sum;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	sum = a[1];
	for (int i = 2; i <= m; i++) {
		sum &= a[i];
	}
	cout << sum << endl;
	return 0;
}