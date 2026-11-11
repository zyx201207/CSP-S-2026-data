#include <bits/stdc++.h>
using namespace std;
int a[500005], n, ca;
long long m, num;

int qh(int a, int c) {
	int z = 0;
	for (int i = ca; i < a; i += ca) {
		z += i;
	}
	return z;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ca = a[2] - a[1];
	for (int i = n; i >= 1; i--) {
		if (qh(a[i], ca) <= m) {
			num = i;
			break;
		}
	}
	cout << num;
	return 0;
}