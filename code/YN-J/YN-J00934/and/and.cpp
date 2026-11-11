#include <bits/stdc++.h>
int a[200005], max1 = INT_MIN, b[200005], m1;
using namespace std;

void f(int n, int m) {
	int i = 0;
	for (; i < n; i++) {
		b[m] = a[i];
		if (m == 1) {
			int sum = b[1];
			for (int i = 1; i <= m1; i++) {
				sum &= b[i];
			}
			max1 = max(max1, sum);
		}
	}
	if (m - 1) {
		f(i - 1, m - 1);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n;
	cin >> n >> m1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		b[m1] = a[i];
		f(i, m1 - 1);
	}
	cout << max1;
	return 0;
}