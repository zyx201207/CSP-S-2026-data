#include <bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;
int n;
ll m, l, r, ans, a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	l = 0, r = 1;
	for (; r <= n; r++) {
		while (a[r] * (r - l) - (s[r] - s[l]) > m)
			l++;
		ans = max(ans, r - l);
	}
	cout << ans;
	return 0;
}