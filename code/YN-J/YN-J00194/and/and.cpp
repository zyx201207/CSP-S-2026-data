#include <bits/stdc++.h>
using namespace std;

long long a[1000001];

long long power(long long a, long long b) {
	long long sum = 0;
	while (b--) {
		sum += a * a;
	}
	return sum;
}

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long ma = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	if (m == 1) {
		cout << ma;
		return 0;
	}
	return 0;
}