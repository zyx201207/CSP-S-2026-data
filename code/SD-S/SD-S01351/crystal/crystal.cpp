#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], b[500005], ans, cnt, c[500005];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i = n-1;i >= 1;i--)
	{
		b[i] = a[i+1] - a[i];
	}
	b[n] = 0;
	for(int i = n-1;i >= 1;i--)
	{
		b[i] += b[i+1];
	}
	for(int i = n-1;i >= 1;i--)
	{
		c[i] = c[i+1] + b[i];
	}
	b[0] = 0;
	ans = 1;
	for(int i = n;i >= 1;i--)
	{
		if(i <= ans)
		{
			break;
		}
		for(int j = i-ans+1;j >= 1;j--)
		{
			if(c[j] - c[i] - b[i] * (i - j) <= m)
			{
//				cout << i << ' ' << j << ' ' << c[j] - c[i] - b[i] * (i - j) << '\n';
				ans = max(ans, i - j + 1);
			}
			else
			{
				break;
			}
		}
	}
//	cout << b[] - (j - i + 1) * b[i-1] << '\n';
	cout << ans;
	return 0;
}

