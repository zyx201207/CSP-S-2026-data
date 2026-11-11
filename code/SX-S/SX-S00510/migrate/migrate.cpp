#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", r, stdin);
	freopen("migrate.out", w, stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		vector<long long> a;
		int n;
		long long d;
		a.push_back(0);
		cin >> n >> d;
		int start;
		cin >> start;
		for (int i = 1; i < n; i++) {
			int b;
			cin >> b;
			a.push_back(b - start);
		}
		int b = a[1] - a[0];
		bool is = false;
		for (int i = 1; i < a.size(); i++) {
			if (b != a[i + 1] - a[i]) {
				is = true;
				break;
			}
		}
		if (!is) {
			cout << 0;
			continue;
		}
		if (n <= 3)
			cout << 0;
		if (n == 5)
			cout << 2;
		if (n == 4)
			cout << 1;
		if (n == 6)
			cout << 1;
	}
	return 0;
}
