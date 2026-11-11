#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 10;
int a[N], sum[N], n, m;
bool check(int mid)
{
	for (int i = 1; (i + mid - 1) <= n; i += 1)
	{
		int num = (mid * a[i + mid - 1]) - (sum[i + mid - 1] - sum[i - 1]);
		if (num <= m) return true;
	}
	return false;
}
signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i += 1) cin >> a[i];

	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i += 1) sum[i] = sum[i - 1] + a[i];

	int l = 0, r = n, ans = -1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}

	cout << ans << endl;
	return 0;
}
