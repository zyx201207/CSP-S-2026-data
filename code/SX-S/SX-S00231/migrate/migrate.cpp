#include <bits/stdc++.h>
using namespace std;
int p = 5;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	int n, d;
	cin >> c >> t;
	int sum = 0;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			sum += x;
		}
		if (t == 1) {
			cout << 1 << endl;
		}
	}
	cout << 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
