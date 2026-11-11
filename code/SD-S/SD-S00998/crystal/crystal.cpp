#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N], b[N];
bool cmp(int a, int b) {
	return a < b;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	bool fla = true;
	for (int i = 1; i <= n + 1; i++) {
		b[i] = a[i] - a[i - 1];
		if (b[i] != b[i - 1] && i > 1) {
			fla = false;
		}
	}
	if (fla == true) {
		if (b[2] == 0) {
			cout << n;
		} else {
			int d = b[2];
			int len = 1;
			while (m > 0) {
				m -= d * len;
				len++;
			}
			cout << len;
		}
	} else {
		int i = 2, len = 1, ans = 0, cur = 0, ls = 0, ld = 1;
		while (i <= n + 1) {
			cur += b[i] * len;
			ls += b[i];
			if (cur > m) {
				ans = max(ans, len);
				while (cur > m) {
					len--;
					cur -= ls;
					ls -= b[ld];
					ld++;
				}
			} else {
				len++;
			}
			i++;
		}
		cout << ans;
	}
	return 0;
} 
/*
10 20
1 4 7 10 13 16 19 22 25 28
*/
