#include <bits/stdc++.h>
using namespace std;

long long n, m, cnt, s, cnt1, d;
long long a[500100], b[500100];
bool f = true;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i > 2) {
			if (a[i] - a[i - 1] != a[2] - a[1])
				f = false;
		}
		//cout << 1;
	}
	sort(a + 1, a + 1 + n);
	if (f) {
		int i = 1;
		while (i * (i + 1) / 2 * (a[2] - a[1]) <= m) {
			i++;
		}
		cout << i ;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] - a[i - 1];
	}
	for (int i = n - 1; i >= 1; i--) {
		b[i] += b[i + 1];
	}
	for (int i = n; i >= 2; i--) {
		s = 0;
		cnt1 = 0;
		int x = i - 1;
		while (s <= m) {
			s += b[x] - b[i];
			x--;
			if (x == -1)
				break;
			cnt1++;
			//cout << s << endl;
		}
		cnt = max(cnt, cnt1);
	}
	cout << cnt;
	return 0;
}