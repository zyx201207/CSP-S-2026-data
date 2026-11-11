#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int maxn = 5e5 + 7;

int n;
LL m, a[maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	int L = 1, R = 1;
	int ans = 1;
	LL d = 0;
	for (R = 2; R <= n; R ++)
	{
		LL num = R - L;
		d += num * (a[R] - a[R - 1]);
		while (d > m) d -= (a[R] - a[L]), L ++;
		ans = max(R - L + 1, ans);
	}
	cout << ans;
	return 0;
}