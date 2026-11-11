#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int n;
LL m;
LL a[500005];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, ans = 0;
	LL sm = 0;
	for (int i = 1; i <= n; i++)
	{
		sm += a[i];
		while (a[i] * (i - l + 1) - sm > m) sm -= a[l++];
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/