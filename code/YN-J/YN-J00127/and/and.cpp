#include <bits/stdc++.h>
using namespace std;
const int MJ = 1e6 + 10;
long long n, m;
long long a[MJ];

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
	if (n <= 5) {
		cout << a[n];
		return 0;
	}
	sort(a + 1, a + 1 + n, cmp);
	cout << a[1];
	return 0;
}
