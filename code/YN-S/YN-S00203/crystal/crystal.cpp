#include <bits/stdc++.h>
using namespace std;
long long A[500010];
long long m;
int ans = 0, n;
vector<int>B[5010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);


	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> A[i];
	}

	sort(A + 1, A + n + 1);

	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= n; j++) {

				B[j].push_back(A[j] - A[i]);
			}
		}

		for (int i = 1; i <= n; i++) {

			int num = 0, ans1 = 0;
			sort(B[i].begin(), B[i].end());

			for (int j = 0; j < n; j++) {

				if (B[i][j] < 0) {
					continue;
				}

				num += B[i][j];

				if (num <= m) {
					ans1++;
				} else {
					break;
				}
			}

			ans = max(ans1, ans);
		}

		cout << ans;
	} else {
		long long a = m / (A[2] - A[1]);

		for (int i = 1; i <= n; i++) {

			a -= i;

			if (a >= 0) {
				ans++;
			} else {
				break;
			}
		}

		cout << ans + 1;
	}

	return 0;
}
