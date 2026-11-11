#include <bits/stdc++.h>
using namespace std;
long long n, l = 0, ans = 0, h = 0;
char z[1000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 0; i <=  n; i++) {

		int a;
		char b;
		cin >> a >> b;

		for (int j = h; j <= l; j++) {

			z[j] = b;
			h = j;
			l = l + a;
		}
	}

	for (int i = 0; i <= n / 2; i++) {

		for (int j = n; j >= n / 2; j--) {

			if (z[i] != z[j]) {
				ans++;
				z[j] = z[i];
			}
		}
	}

	cout << ans << endl;
	return 0;
}
