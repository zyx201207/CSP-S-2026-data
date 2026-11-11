#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200010];
char t[200010];
string s;
int len;
int ret;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i += 1) {
		cin >> a[i];
		cin >> t[i];
		len += a[i];
		for (int j = 1; j <= a[i]; j += 1) {
			s += t[i];
		}
	}
	for (int i = 0; i <= len / 2; i += 1) {
		if (s[i] != s[len - i - 1]) {
			ret += 1;
		}
	}
	cout << ret;
	return 0;
}
