#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	long long n;
	int b[100010];
	char b1[100010];
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i] >> b1[i];
	}
	if (n == 2) {
		if (b1[1] == b1[2]) {
			cout << 0;
			return 0;
		} else {
			cout << min(b[1], b[2]);
			return 0;
		}
	}
	return 0;
}