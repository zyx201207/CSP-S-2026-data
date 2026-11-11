#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5 * 1e5 + 5;
int n;
LL m, a[maxn], S[maxn];
int searchfor(int i) {
	int l = 1, r = i - 1, ans = i;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[i] * (i - mid) - (S[i - 1] - S[mid - 1]) <= m) {
			ans = mid;
			r = mid - 1;
		} else
			l = mid + 1;
	}
	return ans;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		S[i] = S[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, i - searchfor(i) + 1);
	cout << ans;
}
