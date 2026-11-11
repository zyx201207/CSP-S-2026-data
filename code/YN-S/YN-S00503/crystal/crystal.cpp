#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N];
long long n, m;
long long sum, cnt = 0, maxx = 0, f, y, yx;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	for (int i = n; i >= 1; i--) {

		sum = 0;
		cnt = 0;
		f = 0;

		for (int j = i - 1; j >= 1; j--) {

			if (sum + (a[i] - a[j]) <= m) {
				sum += a[i] - a[j];
				cnt++;
			} else {
				if (maxx < cnt)
					maxx = cnt;
				f = 1;
				break;
			}
		}

		if (f == 0) {
			if (maxx < cnt)
				maxx = cnt;
		}
	}

	cout << maxx + 1;
	return 0;
}
