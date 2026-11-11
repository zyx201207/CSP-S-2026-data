#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, b, top = 0, cnt, ans, num;
char c;
string s;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> b >> c;
		if (c == s[0])
			num++;
		cnt += b;
		for (int j = 1; j <= b; j++)
			s += c;
	}
	if (num == cnt) {
		cout << 0;
		return 0;
	}
	if (cnt % 2 == 0) {
		for (int i = 0; i < cnt / 2; i++)
			if (s[i] != s[cnt - i])
				ans++;
	} else
		for (int i = 0; i < cnt / 2; i++)
			if (s[i] != s[cnt - i - 1])
				ans++;
	cout << ans;
	return 0;
}