#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[N]; 
int cnt = 0;
int maxn = -INF;

signed main()
{
	freopen("ans.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1, greater<int>() );
	int ans = a[1];
	if(n == m)
	{
		for(int i=1; i<=n; i++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	else if(m == 1)
	{
		cout << a[1];
		return 0;
	}
	else if(m == 2)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=i+1; j<=n; j++)
			{
				cnt = a[i] & a[j];
				if(cnt > maxn)
				{
					maxn = cnt;
				}
			}
		}
		cout << maxn;
		return 0;
	}
	else
	{
		for(int i=2; i<=m; i++)
		{
			ans &= a[i];
		}
		cout << ans;
	}
	return 0;
}
