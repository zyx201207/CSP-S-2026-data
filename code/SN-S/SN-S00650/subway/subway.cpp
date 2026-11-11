#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, n, m, d, q;
vector<int> w(500045);
vector<int> k(512);
vector<vector<int> > a(512);
vector<vector<int> > t(512);
int ans = 60000000000;
map<int, int> mp[512];
vector<int> vis(512);

void dfs(int x, int u, int v, int num)
{
	if(u == v)
	{
		ans = min(ans, num);
		
		return;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(mp[i][u] == 1 and i != x and vis[i] == 0)
		{
			int idx = 0;
			
			for(int j = 1; j <= k[i]; j++)
			{
				if(a[i][j] == u)
				{
					idx = j;
					
					break;
				}
			}
			
			for(int j = 1; j <= k[i]; j++)
			{
				if(a[i][j] == u)
				{
					continue;
				}
				
				vis[i] = 1;
				
				dfs(i, a[i][j], v, num + t[i][j] + t[i][idx]);
				
				vis[i] = 0;
			}
		}
	}
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	} 
	
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		
		for(int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
			
			mp[i][a[i][j]] = 1;
		}
	}
	
	while(q--)
	{
		int x, y;
		
		cin >> x >> y;
		
		ans = 60000000000;
		int flag = 0;
		
		for(int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			
			if(mp[i][x] == 1 and mp[i][y] == 1)
			{
				int idx1 = 0;
				int idx2 = 0;
				
				for(int j = 1; j <= k[i]; j++)
				{
					if(a[i][j] == x)
					{
						idx1 = j;
					}
					
					if(a[i][j] == y)
					{
						idx2 = j;
					}
				}
				
				ans = min(ans, t[i][idx1] + t[i][idx2]);
				flag = 1;
			}
		}
		
		if(flag != 1)
		{
			dfs(0, x, y, 0);
		}
		
		cout << ans + w[x] + w[y] << "\n";
	}
	
	return 0;
}
