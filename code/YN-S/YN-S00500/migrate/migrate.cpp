#include <bits/stdc++.h>
using namespace std;
int c, t;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int n, d, ans;
	cin >> c >> t >> n >> d;
	for (int i = 0; i <= n; i++) {
		ans++;
		n = c + t;
		for (int j = 0; j <= n; j++) {
			ans += 2;
			d = c * t;
		}
	}
	cout << n << " " << d;
	return 0;
	fclose(stdin);
	fclose(stdout);
}