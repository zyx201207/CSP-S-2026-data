#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
char c, m[200010];
int cnt, n, s1[200010], sum, ans;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d%s", &cnt, &c);
		m[i] = c;
		s1[i] = cnt;
		sum += cnt;
	}
	int l = 0, r = n - 1;
	while (sum && l != r) {
		int minn = min(s1[l], s1[r]);
		if (m[l] != m[r])
			ans += minn;
		s1[l] -= minn;
		s1[r] -= minn;
		if (!s1[l])
			l++;
		if (!s1[r])
			r--;
		sum -= 2 * minn;
	}
	cout << ans;
	return 0;
}