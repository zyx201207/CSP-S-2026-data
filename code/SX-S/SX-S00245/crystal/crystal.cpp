#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
long long n, m, a[N], s[N], ans = 0, mx = LLONG_MIN, v[N];
int bo = 0;

int cmp(long long a, long long b) {
	return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		s[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(v, 0, sizeof(v));

		for (int j = i; j <= n; j++) {

			s[j] = a[i] - s[j];
			v[j] = v[j - 1] + s[j];
			if (v[j] > m) {
				ans = j  - i;
				break;
			}
			if (j == n && v[j] <= m) {
				ans = n - i + 1;
				bo = 1;
			}

		}

		mx = max(mx, ans);
		if (bo) {
			break;
		}
	}

	cout << mx;
	return 0;
}
