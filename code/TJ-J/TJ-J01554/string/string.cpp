#include <bits\stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, co = 0;
	cin >> n;
	int a[n];
	char c[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 0, r = n - 1;
	for (int i = 0; i < (n / 2 + n % 2); i++) {
		if (c[l] != c[r]) {
			co += max(a[l], a[r]);
		}
		l++;
		r--;
	}
	cout << co;
	return 0;
}