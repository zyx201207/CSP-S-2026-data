#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, cnt;
int a[N];
char s[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> s[i];
	for (int i = 1; i <= n / 2; i++) {
		int j = n - i + 1;
		if (s[i] != s[j])
			cnt += max(a[i], a[j]);
	}
	cout << cnt;
	return 0;
}