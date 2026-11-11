#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int n, m;
	cin >> n, m;
	int sum = 0;
	for (int i = 0; i <= m; i++) {

		if (n <= m) {
			sum = i + n;
			sum++;

		}
		cout << sum << endl;

	}
	return 0;
}