#include <bits/stdc++.h>
using namespace std;
int arr[600000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, y;
	long long c = 0, x = 0;
	cin >> n >> m;
	y = n / 2 + 1;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + n + 1);
	for (int i = y; i <= n; i++) {
		x = arr[n] - arr[i] + x;
	}
	for (int i = 1; i < y; i++) {
		c = arr[i]  + c;
	}
	if (c < 0) {
		c = c * -1;
	}
	if (x == m) {
		cout << n;
	} else {
		cout << c;
	}
	return 0;
}
