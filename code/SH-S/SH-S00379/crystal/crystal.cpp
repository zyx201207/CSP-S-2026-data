#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long LL;
const int N = 5e5 + 5;
int n, p, ans;
LL m, a[N], s[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	p = 1;
	for (int i = 1; i <= n; i++)
	{
//		if (a[i] * i - s[i] + s[p - 1] < 0)cout << i << " " << p << endl;
//		assert(a[i] * i - s[i] + s[p - 1] < 0);
		while (a[i] * (i - p + 1) - s[i] + s[p - 1] > m)
		{
			p++;
		}
		ans = max(ans, i - p + 1);
	}
	cout << ans;
	return 0;
}
