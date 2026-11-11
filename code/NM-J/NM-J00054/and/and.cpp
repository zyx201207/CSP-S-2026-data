#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+10;
int n,m;
ll a[N],pre[N];
ll ans;
bool f = 1,f2 = 1,f3 = 0;
inline void dfs(int idx,int step,ll sum)
{
	if (idx == n+1)
	{
		if (step == m)
		{
			ans = max(ans,sum);
		}
		return ;
	}
	if (step < m)
	{
		dfs(idx+1,step+1,sum&a[idx]);
	}
	dfs(idx+1,step,sum);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	pre[0] = (1<<30)-1;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != i-1)
		{
			f2 = 0;
		}
		pre[i] = pre[i-1]&a[i];
		bool flag = 0;
		for (int k = 0;k <= 30;k++)
		{
			if (a[i] == (1<<k)-1)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			f = 0;
		}
	}
	int tt = 0;
	for (int k = 0;k <= 30;k++)
	{
		if (n == (1<<k)-1)
		{
			f3 = 1;
			tt = k;
			break;
		}
	}
	bool f4 = (f2&&f3);
	if (m == n)
	{
		cout << pre[n];
		return 0;
	}
	else if (m == 1)
	{
		ll mx = LLONG_MIN;
		for (int i = 1;i <= n;i++)
		{
			mx = max(mx,a[i]);
		}
		cout << mx;
		return 0;
	}
	else if (m == 2)
	{
		ll mx = LLONG_MIN;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (i == j)
				{
					continue;
				}
				mx = max(mx,(a[i]&a[j]));
			}
		}
		cout << mx;
		return 0;
	}
	else if (m == n-1)
	{
		ll mx = LLONG_MIN;
		for (int p = 1;p <= n;p++)
		{
			ll s = (1<<30)-1;
			for (int i = 1;i <= n;i++)
			{
				if (i == p)
				{
					continue;
				}
				s &= a[i];
			}
			mx = max(mx,s);
		}
		cout << mx;
		return 0;
	}
	else if (f)
	{
		sort(a+1,a+n+1);
		cout << a[n-m+1];
		return 0;
	}
	else if (f4)
	{
		if (m <= tt)
		{
			cout << (1<<(tt-1));
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
	dfs(1,0,(ll)((1<<30)-1));
	cout << ans;
	return 0;
}
