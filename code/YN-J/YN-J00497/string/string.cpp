#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 2;
int a[MAXN], b[MAXN];
string s[MAXN];

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, ans1 = 0, ans2 = 0, ans3 = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> s[i];
	if (n == 1)
		cout << 0;
	else if (n == 2) {
		ans1 = max(a[1], a[2]);
		ans2 = min(a[1], a[2]);
		ans3 = a[1] + a[2];
		if (ans3 % 2 == 0)
			cout << ans3 / 2 - ans2;
		else
			cout << (ans3 - 1) / 2;
	} else {
		cout << n - 1;
	}
	return 0;
}