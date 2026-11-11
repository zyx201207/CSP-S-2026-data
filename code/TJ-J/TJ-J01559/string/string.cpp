#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string a = "";
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		char x;
		cin >> x;
		for (int j = 1; j <= m; j++) {
			a += x;
		}
	}
	string b = "";
	for (int i = a.size() - 1; i >= a.size() / 2; i--) {
		b += a[i];
	}
	for (int i = 0; i <= b.size() - 1; i++) {
		if (a[i] != b[i]) {
			ans++;

		}
	}
	cout << ans ;
	return 0;
}