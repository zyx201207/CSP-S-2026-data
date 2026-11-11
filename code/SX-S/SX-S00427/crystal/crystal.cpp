#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, s, maxx = LLONG_MIN, t, f;
const int N = 5e5+10;
int a[N], c[5010][5010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i - 1; j++) {
				c[i][j] = a[i] - a[j];
			}
		}
		f = 0;
		for (int i = 1; i <= n; i++) {
			sum = 0;
			s = 0;
			for (int j = i - 1; j >= 1; j--) {
				sum += c[i][j];
				if (sum <= m) {

					s++;
				} else {
					f = 1;
					break;
				}
			}
			s++;
			maxx = max(maxx, s);
			if (f == 1) {
				break;
			}
		}
		cout << maxx;
	} else {
		t = a[2] - a[1];
		for (int i = 1; i <= n - 1; i += t) {
			sum = sum + i;
			if (sum <= m) {
				s++;
			}
		}
		s++;
		cout << s;
	}
	return 0;
}
