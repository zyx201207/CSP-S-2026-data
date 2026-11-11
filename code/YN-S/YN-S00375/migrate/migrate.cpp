#include <bits/stdc++.h>
using namespace std;

int f(int n, int d, vector<long long> &length) {
	bool is = true; //是否等差
	long long gap = v[1] - v[0]; //等差大小

	for (long long i = 0; i < n; i++) {

		if (v[i + 1] - v[i] != gap) {
			is = false;
		}
	}

	if (is) {
		if (gap == d) {
			return 0;
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	cin >> c >> t;

	for (int i = 0; i < t; i++) {

		int n, d;
		cin >> n >> d;
		vector<long long> length;

		for (int j = 0; j <= n; j++) {

			int t1;
			cin >> t1;
			length.push_back(t1);
		}

		int gap = INT_MAX;

		for (int j = 1; j < n; j++) {

			int tgap = v[j] - v[j - 1];
			gap = min(tgap, gap);
		}

		if (gap > t) {
			cout << 0 << endl;
			continue;
		}

		cout << f(n, d, length) << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}