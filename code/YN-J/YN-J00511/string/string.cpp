#include <bits/stdc++.h>
using namespace std;

int n;
string s, y;

int main() {
	y = {};
	int ans = 0;
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	int a[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		for (int j = 1; j <= a[i]; j++) {
			y = y + s[i];
		}
	}
//	cout << y << endl;100000000

	if (y.size() % 2 == 0) {
		for (int i = 0; i < y.size() / 2; i++) {

			if (y[i] != y[y.size() - i - 1]) {

				ans++;

			}
		}
	} else if (y.size() % 2 != 0) {
		for (int i = 0; i < y.size() / 2; i++) {
			if (y[i] != y[y.size() - i - 1 ]) {
				//y[i] = y[n - i ];
				ans++;
			}
		}
	}
	cout << ans;
	fclose(stdout);
	fclose(stdout);
	return 0;
}