#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int t;
int ans;
bool f;
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> t;
	for (int i = 1, x; i <= t; i++) {
		cin >> x >> c[i];
		ans += x;
		if (i >= 2 && c[i] != c[i - 1])
			f = 1;
	}
	if (!f)
		cout << 0;
	else
		cout << ans - (ans + 1) / 2;
	return 0;
}
