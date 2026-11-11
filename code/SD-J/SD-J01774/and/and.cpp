#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[200005], ans = (1 << 30) - 1;
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		ans &= a[i];	
	} 
	if(n <= 20)
	{
		int x = (1 << n);
		for(int i = 1;i < x;i++)
		{
			int cnt = 0, sum = (1 << n) - 1;
			bool bj = 0;
			for(int j = 1;j <= n;j++)
			{
				bool pd = (i >> (j - 1)) & 1;
				if(pd)
				{
					cnt++;
					sum &= a[j];
				}
				if(cnt > m)
				{
					bj = 1;
					break;
				}
			}
			if(!bj&&cnt == m)
			{
				ans = max(ans, sum);
//				cout << sum << '\n';
			}
		}
	}
	else if(n <= 2000)
	{
		if(m == 1)
		{
			for(int i = 1;i <= n;i++)
			{
				ans = max(ans, a[i]);
			}
		}
		else if(m == 2)
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = i+1;j <= n;j++)
				{
					ans = max(ans, (a[i] & a[j]));
				}
			}
		}
	}
	else 
	{
		int maxn = 0;
		for(int i = 1;i <= n;i++)
		{
			maxn = max(maxn, a[i]);
		}
		if(maxn < 4)
		{
			int cnt[5];
			memset(cnt, 0, sizeof(cnt));
			for(int i = 1;i <= n;i++)
			{
				cnt[a[i]]++;
			}
			if(a[3] >= m)
			{
				ans = 3;
			}
			else
			{
				if(a[3] + a[2] >= m)
				{
					ans = 2;
				}
				else if(a[3] + a[2] >= m)
				{
					ans = 1;
				}
				else
				{
					ans = 0;
				}
			}
		}
		else
		{
			sort(a+1, a+n+1);
			ans = (1 << 30) - 1;
			for(int i = n;i >= n-m+1;i--)
			{
				ans &= a[i];
			}
		}
	}
	cout << ans;
	return 0;
}

