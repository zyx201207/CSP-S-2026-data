#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll a[N], s[N], m, maxn = LLONG_MIN, sum = 0;
int n;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		s[i] = a[i] - a[i - 1];
	}
	long long k = 0;
	for (int i = 2; i <= n; i++) {

		if (s[i] == s[i - 1]) {
			k++;
		}
	}
	if (k == n - 1) {
		for (int i = 1; i <= n; i++) {
			m -= abs(a[i]) - abs(a[1]);
			if (m <= 0) {
				cout << i - 1;
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			if (a[j + 1] == a[j]) {
				sum++;
			}
			if (m <= 0) {
				maxn = max(maxn, sum);
				break;
			}
			if (a[j - 1] != a[j]) {
				m -= a[j] - a[i];
				sum++;
			}
		}
	}
	cout << maxn;
	return 0;
}