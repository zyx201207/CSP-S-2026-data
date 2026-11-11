#include <bits/stdc++.h>
using namespace std;
#define int long long
const int arr = 2e5;
int sum[arr], a[arr], t[arr];
char c1[arr];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string s, s1;
	int n, cnt = 0, ans = 0;
	cin >> n;
	char c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c1[i];
	}
	for (int i = 1; i <= n; i++) {
		cnt += a[i];
		for (int j = 0; j < a[i]; j++) {
			s += c1[i];
		}
	}
	if (cnt % 2 == 0) {
		for (int i = cnt / 2 - 1; i > 0; i--) {
			for (int j = cnt / 2; j < cnt; j++) {
				if (s[i] != s[j]) {
					ans++;;
				}
			}
		}
	} else {
		for (int i = cnt / 2 - 1; i > 0; i--) {
			for (int j = cnt / 2 + 1; j < cnt; j++) {
				if (s[i] != s[j]) {
					ans++;;
				}
			}
		}
	}
	cout << ans;
	return 0;
}