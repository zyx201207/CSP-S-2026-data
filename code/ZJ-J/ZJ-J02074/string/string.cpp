#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100010];
char s[100010];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t, n = 1, ans = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		char c;
		scanf("%d %c", &a[i], &c);
		for (int j = 1; j <= a[i]; n++, j++)
			s[n] = c;
	}
	for (int i = 1; i <= n / 2; i++)
		if (s[i] != s[n - i])
			ans++;
	cout << ans << endl;
	return 0;
}
