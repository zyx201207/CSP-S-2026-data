#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5,inf = 1e18;
int c,t,d,f[N],dp[N],inn[N],innn[N],ans,n,x[N];
vector <int> e[N];
void clear()
{
	for (int i = 1; i <= n; i ++)
	{
		inn[i] = 0;
		e[i].clear();
	}
}
void solve()
{
	ans = 0;
	clear();
	cin >> n >> d;
	for (int i = 1; i <= n; i ++)
	{
		cin >> x[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i + 1; j <= n; j ++)
		{
			if (x[j] - x[i] > d)
				break;
			e[i].push_back(j);
			inn[j] ++;	
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i ++)
	{
		for (int j = i; j <= n; j ++)
		{
			if (inn[j] == 0)
				q.push(j);
			f[j] = inf;
			dp[j] = 0;
			innn[j] = inn[j];
		}
		f[i] = 0;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int v : e[u])
			{
				f[v] = min(f[v],f[u] + 1);
				innn[v] --;
				if (!innn[v])
					q.push(v);	
			}
		}
		for (int j = i; j <= n; j ++)
		{
			if (inn[j] == 0)
				q.push(j);
			innn[j] = inn[j];
		}
		dp[i] = 1;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int v : e[u])
			{
				if (f[u] + 1 == f[v])
					dp[v] += dp[u];
				innn[v] --;
				if (!innn[v])
					q.push(v);	
			}
		}
		for (int j = i; j <= n; j ++)
		{
			if (dp[j] == 2)
				ans ++;
			//cout << i << " " << dp[j] << " " << j << " " << f[j] << endl; 
		} 
		for (int v : e[i])
			inn[v] --;
	}
	cout << ans << "\n";
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("cpp.txt","r",stdin);
	cin >> c >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}

