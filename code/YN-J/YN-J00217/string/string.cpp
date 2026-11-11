#include <bits/stdc++.h>
using namespace std;
const

int main() {
	freope(".in", "r", stdin);
	freopen(".out", 'w', stdin);
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		for (int j = 1; j <= a[i]; j++; k++) {
			t += s[i];
			if (k <= n / 2) {
				x += s[i];
			} else {
				y += s[i];
			}

		}
	}
	return 0;
}