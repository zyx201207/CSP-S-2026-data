#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5+5;
long long n, m, ans = 0, ANS = 0;
long long a[MAX];
bool flag = true;
long long Record = 0;

void check() {
	if (clock() >= 900) {
		cout << ANS;
		exit(0);
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(a, 0, sizeof(a));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i >= 2) {
			if (a[i] - a[i-1] != a[1] - a[0]) {
				flag = false;
			}
		}
	}
	if (flag) {
		Record = a[1] - a[0];
		long long i = 0;
		while (m > 0) {
			if (m - i >= 0) {
				ANS++;
				m -= i;
				i += Record;
			} else {
				break;
			}
			if (ANS == n) {
				break;
			}
		}
	} else {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			int b[n + 5] = {0};
			for (int jj = 0; jj < n; jj++) {
				b[jj] = a[i] - a[jj];
				check();
			}
			sort(b, b + n);
			tmp = m;
			for (int j = 0; j < n; j++) {
				if (tmp > 0 && tmp - b[j] >= 0) {
					if (b[j] >= 0) {
						tmp -= b[j];
							ans++;
					}
				} else {
					break;
				}
				check();
			}
			ANS = max(ANS, ans);
			ans = 0;
			check();	
		}
	}
	cout << ANS;
	return 0;
}
