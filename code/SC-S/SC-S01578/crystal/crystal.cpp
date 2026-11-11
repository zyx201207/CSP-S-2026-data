#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
constexpr int MAXN = 500005; 
int n, m;
int a[MAXN];
int s[MAXN];
int bs (int start)
{
	int l = start + 1, r = n, mid;
	int ans = start;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (s[mid] - s[start - 1] - (a[mid] - a[start - 1]) * (start - 1) <= m)
		{
			l = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			r = mid - 1;
		}
	}
	return ans - start;
}
int an = 0;
signed main ()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2 ; i <= n ; i ++)
	{
		s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		an = max(an, bs(i));
	}
	cout << an + 1;
	return 0; 
}//15:17  AC!!! 