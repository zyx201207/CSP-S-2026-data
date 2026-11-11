#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 100000;
long long n, m;
int a[N], v[N];
int sum;

int main() {
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	int c = 1;
	cin >> n >> m;
	sum = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= 1; j--) {
			v[j] = a[sum] - a[j];
			if (v[j] > m) {
				sum--;
				continue;
			}
		}
	}
	for (int i = sum - 1; i >= 1; i--) {
		if (v[i] <= m) {
			m = m - v[i];
			c++;
		}
	}
	cout << c;
	return 0;
}