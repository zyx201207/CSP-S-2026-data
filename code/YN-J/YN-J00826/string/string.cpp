#include <bits/stdc++.h>
using namespace std;
long long n, len;
long long  a[10001];
string c[10000001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		len += a[i];
	}
	long long  i = 1, j = n, num = 0, cn;
	while (i < j) {
		if (c[i] != c[j]) {
			num += min(a[i], a[j]);
		}
		cn = a[i] - a[j];
		if (cn > 0) {
			a[i] = cn;
			j--;
		} else if (cn < 0) {
			a[j] = -cn;
			i++;
		} else {
			a[i] = 0;
			a[j] = 0;
			i++;
			j--;
		}
	}
	cout << num;
	return 0;
}