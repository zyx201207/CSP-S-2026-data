#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n, ans, l, r, mid;
ll m, sum, a[N], s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	for(int i = 1; i <= n; i ++) {
		l = 0;
		r = i - 1;
		while(l < r) {
			mid = (l + r) >> 1;
			if(a[i] * (i - mid) - (s[i] - s[mid]) <= m) r = mid;
			else l = mid + 1; 
		}
		ans = max(ans, i - l);
	}
	cout << ans << '\n';
	return 0;
}
