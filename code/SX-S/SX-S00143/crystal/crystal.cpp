#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], m, b[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	int num = 0;
	bool bo = true;
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
		if (b[i] == b[i - 1])
			num = b[i];
		else
			bo = false;
		if (!bo)
			break;
	}
	if (bo) {
		int jj = num, da = 0;
		while (m > 0) {
			m -= jj;
			jj += num;
			da++;
		}
		cout << da;
		return 0;
	}
	int maxx = 0;
	for (long long i = 1; i <= n; i++) {
		bool t = false;
		int x = i - 1, ans = 1, y = m;
		while (!t && x > 0) {
			if (a[i] - a[x] <= y) {
				y -= a[i] - a[x];
				ans++;
			} else
				t = true;
			x--;
		}
		maxx = max(maxx, ans);
	}
	cout << maxx;

	return 0;
}
