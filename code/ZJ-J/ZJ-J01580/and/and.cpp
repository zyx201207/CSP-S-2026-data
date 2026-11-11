#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010], q[2], e = 0, mmx = 0;
bool check(int x)
{
	while(x != 1)
	{
		if(x % 2 == 1) return 0;
		x /= 2;
	}
	return 1;
}
bool cmp(int x, int y)
{
	return x > y;
}
int yu(int g[])
{
	int ans = g[1];
	for(int i = 2; i <= m; i++)
		ans &= g[i];
	return ans;
}
void dfs(int u)
{
	if(u == n + 1)
	{
		if(e != m) return;
		mmx = max(mmx, yu(q));
	}
	//Òª
	q[++e] = a[u];
	dfs(u + 1);
	q[e] = 0;
	e--;
	//²»Òª
	dfs(u + 1);
	return;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 1)
	{
		int mx = 0;
		for(int i = 1; i <= n; i++)
			mx = max(a[i], mx);
		cout << mx;
		return 0;
	}
	if(m == 2)
	{
		int mx = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(i == j) continue;
				mx = max(mx, a[i] & a[j]);
			}
		cout << mx;
		return 0;
	}
	if(m == n)
	{
		int ans = a[1];
		for(int i = 2; i <= n; i++)
			ans &= a[i];
		cout << ans;
		return 0;
	}
	if(m == n - 1)
	{
		int mx = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i == 1)
			{
				int ans = a[2];
				for(int j = 3; j <= n; j++)
					ans &= a[j];
				mx = ans;
			}
			else
			{
				int ans = a[1];
				for(int j = 2; j <= n; j++)
				{
					if(i == j) continue;
					ans &= a[j];
				}
				mx = max(mx, ans);
			}
		}
		cout << mx;
		return 0;
	}
	int tmp = 0;
	for(int i = 1; i <= n; i++)
	{
		tmp += a[i];
		if(tmp >= 4) break;
	}
	if(tmp < 4)
	{
		if(m >= 4)
		{
			cout << 0;
			return 0;
		}
		int a1 = 0, a2 = 0, a3 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] == 1) a1++;
			else if(a[i] == 2) a2++;
			else if(a[i] == 3) a3++;
		}
		if(a3 == 1)
		{
			if(m > 1) cout << 0;
			else cout << 3;
			return 0;
		}
		if(a2 == 1)
		{
			if(m >= 2) cout << 0;
			else cout << 2;
			return 0;
		}
		if(a1 > 0)
		{
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	bool flag_tmp = 1;
	for(int i = 1; i <= n; i++)
	{
		if(!check(a[i] + 1))
		{
			flag_tmp = 0;
			break;
		}
	}
	if(flag_tmp)
	{
		sort(a + 1, a + 1 + n, cmp);
		cout << a[m];
		return 0;
	}
	dfs(1);
	cout << mmx;
	return 0;
} 
