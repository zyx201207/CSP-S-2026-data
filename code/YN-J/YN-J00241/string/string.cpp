#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long a[n + 2], sum = 0;
	char a1[n + 2];
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> a1[i];
	}
	for (int i = n; i >= 1; i--) {
		if (a1[i] != a1[n - i + 1]) {
			if (a[i] == a[n - i + 1]) {
				sum += a[i];
			} else if (a[i] > a[n - i + 1]) {
				sum += max(a[i], a[n - i + 1]);
			} else if (a[i] < a[n - i + 1]) {
				sum += max(a[i], a[n - i + 1]);
			}
		}
	}
	cout << sum / 2;
	return 0;
}