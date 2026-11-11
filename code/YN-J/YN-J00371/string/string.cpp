#include <bits/stdc++.h>
using namespace std;
char c[100000];
char c2[100000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int a;
	char b;
	int k = 0;
	int inp;
	cin >> inp;
	for (int i = 0; i < inp; i++) {
		cin >> a;
		cin >> b;
		for (int j = k; j < k + a; j++) {
			c[j] = b;
		}
		k += a;
	}
	for (int i = k / 2; i >= 0; i--) {
		c2[k / 2 - i] = c[i];
	}
	int ans = 0;
	for (int i = 0; i <= k / 2; i++) {
		if (c[i] != c2[i])
			ans++;
	}
	cout << ans;
	return 0;
}