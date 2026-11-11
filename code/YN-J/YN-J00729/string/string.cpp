#include <bits/stdc++.h>
using namespace std;
long long a[200005], n, sum[200005], ans, t[36], l;
string s;
char c[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i], sum[i] = sum[i - 1] + a[i], t[c[i] - 'a' + 1] += a[i];
	if (sum[n] <= 1000000) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= a[i]; j++)
				s += c[i];
		for (int i = 0; i < (sum[n] + 1) / 2 ; i++)
			if (s[i] != s[sum[n] - i - 1])
				ans++;
		cout << ans;
	} else
		sort(t + 1, t + 27 + 1), cout << sum[n] - t[27];
	return 0;
}