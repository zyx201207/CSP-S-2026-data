#include <bits/stdc++.h>
using namespace std;
long long n, m, c[500005], b[500005], ans = 0, t, mans = -1, a;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)

		cin >> c[i];
	sort(c + 1, c + 1 + n);

	for (int i = 2; i <= n; i++) {

		for (int j = 1; j < i; j++)

			b[j] = c[i] - c[j];
		t = i - 1;
		ans = 0;
		a = m;

		while (a > 0 && t >= 1) {
			a -= b[t];
			ans++;
			t--;
		}

		if (a == 0)
			ans++;
		mans = max(ans, mans);
	}

	cout << mans << endl;
	return 0;
}