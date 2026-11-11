#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long a[N], loss[N];
int w[N];
int n, ans, sum, x, y;
long long m, r;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {

		loss[i] = a[i + 1] - a[i];
		if (loss[i] == loss[i - 1])
			y++;
		if (loss[i] > m) {
			break;
		} else {
			sum++;
		}
	}
	if (y + 2 == n) {
		long long  z = m / loss[1];
		for (long long i = 1; i <= 1000000000000000005; i++) {
			z -= i;
			if (z == 0) {
				cout << i + 1 ;
				return 0;
			} else if (z < 0) {
				cout << i;
				return 0;
			}
		}

	}
	int o = 1;
	for (int i = sum + 1; i >= 1; i--) {
		r = 0;
		for (int j = i - 1; j >= 1; j--) {
			r = r + r + loss[j];
			if (r > m) {
				break;
			} else {
				w[o]++;
			}
		}
		o++;
	}
	for (int i = 1; i <= o; i++) {
		ans = max(ans, w[i]);
	}
	cout << ans + 1;
}
