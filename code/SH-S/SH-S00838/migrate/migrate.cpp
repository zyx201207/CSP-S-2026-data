#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

long long a[2000010];
int nxt[2000010] , prv[2000010] , dis[4010][4010];

int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int c , T;
	cin >> c >> T;
	while (T--)
	{
		int n;
		long long d;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++)
		{
			nxt[i] = upper_bound(a + 1 , a + n + 1 , a[i] + d) - a - 1;
			prv[i] = lower_bound(a + 1 , a + n + 1 , a[i] - d) - a;
		}
		if (c <= 10)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					dis[i][j] = 1e9;
				}
				dis[i][i] = 0;
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (a[j] - a[j - 1] > d) break;
					dis[i][j] = dis[i][max(i , prv[j])] + 1;
				}
			}
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = i + 3; j <= n; j++)
				{
					if (dis[i][j] >= n) break;
					vector<int> path;
					path.push_back(i);
					for (int cur = i; cur < j; cur = nxt[cur])
					{
						path.push_back(cur);
					}
					path.push_back(j);
					int sz = 0;
					for (int k = 1; k + 1 < path.size(); k++)
					{
						int cur = path[k];
						if (cur - 1 != path[k - 1] && dis[i][cur - 1] + dis[cur - 1][j] == dis[i][j]) sz++;
						if (cur > 2) if (cur - 2 != path[k - 1] && dis[i][cur - 2] != path[max(0 , k - 2)]) sz++;
						if (cur + 1 != path[k + 1] && dis[i][cur + 1] + dis[cur + 1][j] == dis[i][j]) sz++;
						if (cur < n - 1) if (cur + 2 != path[k + 1] && cur + 2 != path[min(k + 1 , (signed)path.size() - 1)] && dis[i][cur + 2] == dis[cur + 2][j]) sz++;
					}
					cnt += (sz == 1);
				}
			}
			cout << cnt << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	return 0;
}
