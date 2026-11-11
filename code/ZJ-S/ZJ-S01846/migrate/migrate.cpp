#include<bits/stdc++.h>
using namespace std;
void read(long long &x)
{
	int O = 0; char c; x = 0;
	for(c = getchar(); c < '0' || c > '9'; c = getchar()) O |= c == '-';
	for(; '0' <= c && c <= '9'; c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
	x = (O? -x : x);
}
long long c, t, n, d, x[2000002], cnt = 0, minn = 1e18;
void dfs(int st, int ed, int k)
{
	if(st == ed)
	{
		if(minn > k)
		{
			minn = k;
			cnt = 0;
		}
		cnt++;
		return;
	}
	for(int i = st + 1; i <= ed; i++)
	{
		if(x[i] - x[st] <= d) dfs(i, ed, k + 1);
	}
	return;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	read(c); read(t);
	for(; t--; )
	{
		read(n); read(d);
		if(d == 1)
		{
			cout << "0\n";
			continue;
		}
		int l = 1;
		for(int i = 1; i <= n; i++)
		{
			read(x[i]);
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 3; j <= n; j++)
			{
				minn = 1e18;
				cnt = 0;
				dfs(i, j, 1);
				if(cnt == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}