#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,f,x[200005],sum,best;
int d[200005];
void dfs(int now,int step,int end)
{
	if (now == end)
	{
		if (step < best)
		{
			best = step;
			sum = 1;
		}
		else
		{
			sum++;
		}
	}
	if ((step > best) || (x[now + 1] - x[now] > f))
	{
		return ;
	}
	for (int i = now + 1; i <= end; i++)
	{
		if (x[i] - x[now] <= f)
		{
			dfs(i,step + 1,end);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		if ((c == 13) || (c = 14))
		{
			cout << "0\n";
			continue;
		}
		cin >> n >> f;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		for (int i = 2; i <= n; i++)
		{
			for(int j = 1; j < i; j++)
			{
				best = 2147483647;
				sum = 0;
				dfs(j,0,i);
				if (sum == 2)
				{
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}