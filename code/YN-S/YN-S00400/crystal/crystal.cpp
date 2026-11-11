#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long s[500005];
long long maxn = 0, ans, maxi, maxj;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	for (int i = 1; i < n; i++) {

		s[i] = a[i + 1] - a[i];
	}

	int j = 1;

	for (int i = 1; i <= n; i++) {


		m -= s[i - 1] * (i - j);

		if (m >= 0) {


			if (maxn < i - j + 1) {
				maxn = i - j + 1;
				maxi = i;
				maxj = j;
			}
		} else {
			while (m < 0) {
				m += a[i] - a[j];
				j++;

			}
		}

		//cout << j << ' ' << i << endl;
	}

	//cout << endl << maxi << ' ' << maxj << endl;
	cout << maxn;

	return 0;
}
