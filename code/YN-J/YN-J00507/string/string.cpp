#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	int a[n + 5] = {};
	char b[n + 5] = {};
	int s = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
		s += a[i];
	}
	bool flag = 0;
	for (int i = 1; i < n; i++) {
		if (b[i] != b[i - 1]) {
			flag = 1;
		}
	}
	if (flag = 0) {
		cout << 0;
	}
	int z = s / 2;
	int num = 0;
	for (int i = 0; i < z; i++) {
		if (a[i] != a[s - i - 1]) {
			num++;
		}
	}
	cout << num;
	return 0;
}