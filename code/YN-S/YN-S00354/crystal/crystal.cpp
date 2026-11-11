#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100005] = {0};

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a - 1, a + n - 1 );
	int s = a[(n + 1) / 2];



	int ans = 0;

	for (int i = (n + 1) / 2; i >=  1; i--) {

		if (s - a[i] <= m) {
			ans++;
			int cz = s - a[i];

			m -= cz ;
		} else  {
			break;
		}
	}

	cout << endl;

	for (int i = (n + 1) / 2 + 1; i <= n; i++) {

		if (a[i] - s <= m) {
			ans++;
			int cz1 = a[i] - s;
			m -= cz1;

			if (m < 0) {
				break;
			}
		} else {
			break;
		}
	}

	cout << ans;
	return 0;
}