#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
long long a[N], b[N], m, n, r, sum, maxx = 0, ge;
bool k;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			b[i] = 0;
		} else {
			b[i] = a[i + 1] - a[i];
			if (b[i] != 0) {
				k = 1;
			} else if (b[i] == 0) {
				k = 0;
			}
		}
	}
	if (k == 0) {
		cout << n;
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i ; j >= 1; j--) {
			if (sum > m) {
				break;
			}
			sum += b[j - 1] * (j - 1);
			ge++;
		}
		if (ge > maxx) {
			maxx = ge;
		}
		ge = 0;
		sum = 0;

	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}