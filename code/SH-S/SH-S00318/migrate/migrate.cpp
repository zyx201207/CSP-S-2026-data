#include <bits/stdc++.h>
using namespace std;

long long c, t, n, d, x[2440], cnt, minn;
void dfs(int a, int b, int ti)
{
	if(ti > minn) return;
	if(a == b)
	{
		if(minn > ti)
		{
			minn = ti;
			cnt = 1;
			return;
		}
		if(minn == ti) 
		{
			cnt++;
			return;
		}
		return;
	}
	if((x[b]-x[a]) <= d)
	{
		dfs(b, b, ti+1);
		return;
	}
	for (int i = a+1; i <= b; i++)
	{
		long long dis = x[i]-x[a];
		if(dis > d) break;
		dfs(i, b, ti+1);
	}
	return;
}
bool check(int a, int b)
{
	cnt = 0;
	minn = 0x3f3f3f3f;
	dfs(a, b, 0);
	if(cnt == 2) return 1;
	return 0;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n >> d;
		memset(x, 0, sizeof(x));
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				if(check(i, j)) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
