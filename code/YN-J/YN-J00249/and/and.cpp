#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n, m;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		int maxx = 0;
		for (int i = 1; i <= n; i++)
			maxx = max(a[i], maxx);
	} else if (m == 2) {
		int maxx = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				maxx = max(maxx, a[i] & a[j]);
		cout << maxx << endl;
	} else if (m == n - 1) {
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= n; j++) {
				if (j == i)
					continue;
				if (sum != 0)
					sum &= a[j];
				else
					sum = a[j];
			}
			maxx = max(maxx, sum);
		}
		cout << maxx << endl;
	} else if (m == n) {
		int sum = a[1];
		for (int i = 2; i <= n; i++)
			sum &= a[i];
		cout << sum << endl;
	} else {
		sort(a + 1, a + 1 + n, cmp);
		cout << a[m] << endl;
	}
	return 0;
}