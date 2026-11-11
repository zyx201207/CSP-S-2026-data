#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int c[200005];

int ec(int x) {
	int sum = 1;
	while (x > 1) {
		x /= 2;
		sum++;
	}
	return sum;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (m == 1) {
		cout << a[n - 1];
		return 0;
	}
	int ecmin = 31;
	for (int i = n - 1; i > n - 1 - m; i--) {
		if (ec(a[i]) <= ecmin) {
			ecmin = ec(a[i]);
		}
	}
	int min = pow(2, ecmin) - 1;
	//cout << ecmin << endl << min << endl;
	for (int i = n - 1; i > n - m; i--) {
		b[i] = min - (a[i] & min)  ;
		//cout << b[i];
	}
	for (int i = n - m; i >= 0; i--) {
		b[i] =  a[i] - min  ;
		//cout << b[i];
	}
	for (int i = 0; i < n; i++) {
		c[i] = abs(b[i]);
	}
	sort(c, c + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (abs(b[j]) == c[i]) {
				c[i] = b[j];
			}
		}
	}
	int max = min + c[0];
	//for (int i = 0; i < n; i++) {
	//cout << b[i] << endl;
	//cout << c[i] << endl;
	//}
	for (int i = 0; i < m; i++) {
		max = max & (min + c[i]);
	}
	cout << max;
	return 0;
}