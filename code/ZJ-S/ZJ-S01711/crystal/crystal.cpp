#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10;
long long a[N];
int vis[210];

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	if (n <= 5000)
	{
		sort (a + 1, a + n + 1);
		for (int i = n; i >= 1; i--)
		{
			long long mm = m;
			int pos = 0;
			for (int j = i; j >= 1; j--)
			{
				if (mm - (a[i] - a[j]) >= 0)
				{
					pos = j;
					mm -= (a[i] - a[j]);
				}
				else break;
			}
			ans = max(ans, i - pos + 1);
		}
		cout << ans << endl;
		return 0;
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (abs(a[i]) > 100)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		map <long long, int> b;
		for (int i = 1; i <= n; i++)
		{
			a[i] += 100;
			b[a[i]]++;
		}
		int cur = 0;
		for (int i = 0; i <= 200; i++)
		{
			if (b[i] > 0) vis[++cur] = i;
		}
		for (int i = cur; i >= 1; i--)
		{
			int cnt = b[vis[i]], mm = m;
			for (int j = i - 1; j >= 1; j--)
			{
				int d = vis[i] - vis[j];
				int num = min(mm / d, b[vis[j]]);
				cnt += num;
				mm -= d * num;
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;
		return 0;
	}
	flag = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != i)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (i * (i + 1) / 2 <= m)
			{
				cout << i + 1 << endl;
				return 0;
			}
		}
		return 0;
	}
	flag = 0;
	for (int i = 3; i <= n; i++)
	{
		if (a[i] - a[i - 1] != a[2] - a[1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		int d = a[2] - a[1];
		for (int i = n - 1; i >= 0; i--)
		{
			if (d * i * (i + 1) / 2 <= m)
			{
				cout << i + 1 << endl;
				return 0;
			}
		}
		return 0;
	}
	return 0;
}
