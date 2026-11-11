#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 100;
int n, m, a[N], b[N];
bool cmp(int a, int b)
{
	return (a > b);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] + a[i];
	}
	int ret = 0;
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = n - i + 1, ans = 0;
		while(l <= r)
		{
			int mid = ((l + r) >> 1);
			if(mid * a[i] - (b[i + mid - 1] - b[i - 1]) <= m)
			{
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
//		printf("i=%lld, ans=%lld\n", i, ans);
		ret = max(ret, ans);
	}
	cout << ret;
	return 0;
}
