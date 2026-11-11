#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int line = a[n / 2 + 1];
//	cout << line << endl;
	int maxx = 0;
	int p = n, q = m;
	while (p--) {
		maxx = 0;
		q = m;
		int sum = 0;

		for (int i = n; i >= 1; i--) {
			if (a[i] == line)
				sum++;
		}

		for (int i = n; i >= 1; i--) {
			int t = line - a[i];

			if (t <= 0)
				continue;
			//cout << t << "----------" << endl;
			if (q == 0)
				break;
			if (q < 0 ) {
				sum--;
				line--;
				break;
			} else {
				q -= t;
				sum++;
			}
		}
		maxx = max(maxx, sum);
		if (q > 0) {
			line++;
		}

	}
	cout << maxx;
	return 0;
}
