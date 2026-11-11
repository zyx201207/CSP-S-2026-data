#include <bits/stdc++.h>

using namespace std;
int a[500010], n;
long long m, cnt = -1, cn, i = 1, j = 2, d;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	for (int i1 = 1; i1 <= n; i1++) {
		cin >> a[i1];
	}
	sort(a + 1, a + 1 + n);

	while (j <= n) {

		d = a[j] - a[i];

		cn += d;
		if (cn <= m) {
			cnt = max(cnt, j - i + 1);
			for (int i1 = j; i1 <= n; i1++)
				if (a[i1] == a[i1 - 1])
					cnt++;
				else
					break;
			j++;
		} else {
			cn = 0;
			i++;
			for (int i1 = i; i1 < j; i1++) {
				cn += a[j] - a[i1];
			}
		}

	}
	cout << cnt << endl;
	return 0;
}
