#include <bits/stdc++.h>
using namespace std;
int n;
string s1;
int a[2050];
char c[2050];

int main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	int  l = 0, ii = 0, k = 0;
	char c1;
	for (k; k < n; k++) {
		cin >> a[k] >> c[k];
		l += a[k];
		if (k > 0) {
			if (c[k - 1] == c[k]) {
				a[k - 1] += a[k];
				k -= 1;
			}
		}
		if ((ii + 1) == n) {
			break;
		}
		ii++;
	}
//	for (int i = 0; i <= k; i++) {
//		cout << a[i] << c[i] << endl;
//	}

	bool b = 0;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < k / 2; i++) {
		if (a[i] == a[k  - i]) {
			if (c[i] == c[k - i]) {
				cnt1++;
			} else {
				cnt2 += a[i];
			}
		} else {
			b = 1;
		}
	}
	if (cnt1 == ((k + 1) / 2)) {
		cout << 0;
	} else {
		if (!b) {
			cout << cnt2;
		} else {
			for (int j = 0; j <= k; j++) {
				for (int i = 0; i < a[j]; i++) {
					s1 += c[j];
				}
			}
			string s2;
			for (int i = 0; i < l; i++) {
				s2 += s1[l - i - 1];
			}
			int cnt = 0;
			for (int i = 0; i < l; i++) {
				if (s1[i] != s2[i]) {
					cnt++;
				}
			}
			int ans = cnt / 2;
			cout << ans;
		}
	}
	return 0;
}