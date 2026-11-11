#include<bits/stdc++.h>
using namespace std;
#define int long long
int c , t , n , d , ans;
int a[2000006] , f[2000006] , z[2000006];
vector<int> b[2000006];
void bfs(int k)
{
	queue<pair<int , int> > q;
	for(int i = 1; i <= n; i ++)f[i] = 0;
	q.push({k , 0});
	while(!q.empty())
	{
		int t = q.front().first , w = q.front().second;
		q.pop();
		if(f[t] == 0)
		{
			f[t] ++;
			z[t] = w;
			for(int i = 0; i < b[t].size(); i ++)
			{
				int p = b[t][i];
				q.push({p , w + 1});
			}
		}
		else if(z[t] == w)f[t] ++;
	}
}
signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	cin >> c >> t;
	if(c <= 10)
	{
		while(t --)
		{
			ans = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++)b[i].clear();
			for(int i = 1; i <= n; i ++)cin >> a[i];
			for(int i = 1; i <= n; i ++)
			{
				for(int j = i; j <= n; j ++)
				{
					if(a[j] - a[i] <= d)b[i].push_back(j);
				}
			}
			for(int i = 1; i <= n; i ++)
			{
				bfs(i);
				for(int j = i + 1; j <= n; j ++)
				{
					if(f[j] == 2)ans ++;
				}
			}
			cout << ans << "\n";
		}
	}
	else if(c <= 12)
	{
		while(t --)
		{
			ans = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i ++)cin >> a[i];
			int c = a[2] - a[1];
			if(d / c != 2)cout << "0\n";
			else cout << n - 2 << "\n";
		}
	}
	return 0;
}
