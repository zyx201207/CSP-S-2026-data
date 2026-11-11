#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 10;
int n, m;
int a[MAXN];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int L = 1, R = 2, ned = 0, ans = 1;
	for(; R <= n; R++)
	{
		ned += (R - L) * (a[R] - a[R - 1]);
		while(L <= R && ned > m)
		{
			ned -= (a[R] - a[L]);
			L++;
		}
		ans = max(ans, R - L + 1);
	}
	cout << ans;
	return 0;
}