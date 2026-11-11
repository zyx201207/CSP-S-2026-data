#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a[1000];
	string c[1000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		if (c[i - 1] == c[i]) {
			cout << 0;
		}
	}
	return 0;
}