#include <bits/stdc++.h>
using namespace std;
int a[200000];
char c[200000];
char m[2000000];

int main() {
	int n, l = 1, ans = 0, t = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = l; j < l + a[i]; j++) {
			m[j] = c[i];
		}
		l += a[i] - 1;
	}

	for (int i = 1; i <= l / 2 + 1; i++) {
		if (m[i] != m[l + 1 - i]) {
			t = 0;
			ans += 1;
		}
	}
	if (t == 0) {
		ans += 1;
	}
	cout << ans;
	return 0;
}