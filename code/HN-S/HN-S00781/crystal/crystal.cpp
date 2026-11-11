#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
int n , m;
bool check(int x)
{
	int ans = 0;
	for (int i = x; i >= 1; i--) ans += (a[x] - a[i]);
	if (ans <= m) return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool flag = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != i) flag = 1;
	}
	sort (a + 1 , a + n + 1);
	if (n <= 5000)
	{
		int maxn = 0 , pos = 0;
		for (int i = a[n]; i >= 1; i--)
		{
			int ans = 0 , cnt = 0;
			for (int j = n; j >= 1; j--)
			{
				if (i < a[j]) continue;
				if (ans + i - a[j] > m) break;
				ans += (i - a[j]);
				cnt++;
			}
			maxn = max(maxn , cnt);
		}
		cout << maxn;
		return 0;
	}
	int l = 0 , r = n + 1 , tot = 0;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid) == 1)
		{
			l = mid + 1;
			tot = mid;
		}
		else r = mid - 1;
	}
	cout << tot;
	return 0;
}
