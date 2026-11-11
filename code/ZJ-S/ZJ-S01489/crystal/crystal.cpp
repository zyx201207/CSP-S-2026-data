#include <bits/stdc++.h>
using namespace std;

const int N = 500010;
typedef long long ll;

int n, ans;
ll m, a[N], s[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    	cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
    	s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i ++) {
    	int l = i, r = n, j = -1;
    	while (l <= r) {
    		int mid = l + r >> 1;
    		if (1ll * (mid - i + 1) * a[mid] - (s[mid] - s[i - 1]) <= m)
				l = mid + 1, j = mid;
			else r = mid - 1;
		}
		ans = max(ans, j - i + 1);
	}
	cout << ans;
	return 0;
}