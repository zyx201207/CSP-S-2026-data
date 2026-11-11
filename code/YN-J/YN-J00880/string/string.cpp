#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[105], c[105];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	int ans;
	for (int i = 0; i < a[i]; i++) {
		ans += c[i];
	}
	int ans2;
	for (int i = a[i]; i > 0; i--) {
		ans2 += c[i];
	}
	if (ans == ans2) {
		cout << "0";
	} else {
		cout << "2";
	}
	return 0;
}