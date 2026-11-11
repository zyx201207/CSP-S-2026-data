#include <bits/stdc++.h>
using namespace std;


string a;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int x, y;

	for (int i = 0; i < n; i++) {

		cin >> x >> y;
		int m = x;

		while (m--) {
			int cnt = 0;
			a[cnt++] = y;
		}
	}

	int ans = 0;

	for (int i = 0; i <= a.size(); i++) {

		for (int j = a.size(); j >= 0; j--) {

			if (a[i] != a[j]) {
				ans++;
			}

			continue;
		}
	}

	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}