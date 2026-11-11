#include <bits/stdc++.h>
using namespace std;
#define int long long
int l = 0, a[1000001], ans = 0, n;
char c[1000001];
string s = "";

inline bool hwc(string s) {
	for (int i = 0; i < ceil(l / 2.0); i++) {
		if (s[i] != s[l - i - 1 ])
			return 0;
	}
	return 1;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++)
			s += c[i];
		l += a[i];
	}
	if (hwc(s)) {
		cout << '0';
		return 0;
	} else {
		int cnt = 0;
		while (1) {
			if (cnt > l || hwc(s))
				break;
			s[l - cnt - 1] = s[cnt];
			cnt++;
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


