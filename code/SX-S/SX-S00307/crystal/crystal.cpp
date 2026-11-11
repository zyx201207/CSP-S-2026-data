#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int x, y;
ll b[100000];
ll a[100000], cmp, cnt = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int m, n;
	int s;
	cin >> n >> m;
	s = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int v;
	for (int i = 1; i <= n; i++) {
		v = min(LLONG_MAX, a[i + 1] - a[i]);
	}
	if (v < m) {
		cout << "1" << endl;
		return 0;
	}
	if (v == m) {
		cout << "2" << endl;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		a[i] = b[i + 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cmp = (a[j] - a[j - 1]) * cnt;
			if (cmp <= s) {
				s = s - cmp;
				cnt++;
			} else {
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
