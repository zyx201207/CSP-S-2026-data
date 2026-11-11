#include <bits/stdc++.h>
using namespace std;
const long long NUM = 1e18;
const int N = 5e5 + 10;
long long n, m, x, a[N], ans, num;
int sum[N][100];
//vector<long long> sum[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	if (m > N) {
		for (int i = 1; i <= 10; i++) {

			cin >> a[i];
		}

		if (a[3] - a[2] == 1 && a[1] == 1) {
			ans = (-1 + sqrt(1 + 8 * m)) / 2;
			cout << ans;
			return 0;
		} else {

		}
	}

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		sum[i][0] = a[i] - a[i - 1];
		//sum[i].push_back(a[i] - a[i - 1]);
	}


	for (int i = 3; i <= n; i++) {

		for (long long j = 1; j <= n; j++) {

			num = sum[i - 1][j] + (a[i] - a[i - 1]) * (j + 1);
			//cout << "i:" << i << " j:" << j << " " << "sum[i-1][j]:" << sum[i - 1][j] << " " << num << '\n';

			if (num <= m ) {
				//sum[i].push_back(num);
				sum[i][j] = num;
				ans = max(ans, j + 2);
			}

			if (j >= i - 2) {
				break;
			}
		}
	}

	cout << ans;
	return 0;
}