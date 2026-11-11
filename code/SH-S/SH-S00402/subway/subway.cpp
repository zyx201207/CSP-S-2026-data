#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
#define ll long long

long long c , n , m , d , q , k , a , t , start ,  end , cost ,ans;
int mp[N][M] , s[M];
bool vis[M];

void dfs(int x)
{
	vis[start] = 1;
	
	if(cost > ans && ans != -1)
	{
		return;
	}
	
	if(x == end)
	{
		if(ans == -1)
		{
			ans = cost;
		}
		else
		{
			ans = min(ans , cost);
		}
		return;
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		if(mp[i][x])
		{
			for(int j = 1 ; j <= m ; j++)
			{
				if(mp[i][j] && vis[j] == 0 && j != x)
				{
					cost = cost + (mp[i][x] + mp[i][j]);
					vis[j] = 1;
					// cout << x << "->" << j << "\n";
					dfs(j);
					vis[j] = 0;
					cost = cost - (mp[i][x] + mp[i][j]);
				}
			}
		}
	}
}

int dfs2(int x)
{
	vis[start] = 1;
	
	if(x == end)
	{
		return cost;
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		if(mp[i][x])
		{
			for(int j = 1 ; j <= m ; j++)
			{
				if(mp[i][j] && vis[j] == 0 && j != x)
				{
					cost = cost + (mp[i][x] + mp[i][j]);
					vis[j] = 1;
					// cout << x << "->" << j << "\n";
					dfs(j);
					vis[j] = 0;
					cost = cost - (mp[i][x] + mp[i][j]);
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)
	{
		cin >> s[i];
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> k;
		for(int j = 1 ; j <= k ; j++)
		{
			cin >> a >> t;
			mp[i][a] = t;
		}
	}
	
//	for(int i = 1 ; i <= n ; i++)
//	{
//		cout << "路线" << i << "经过地铁站：";
//		for(int j = 1 ; j <= m ; j++)
//		{
//			if(mp[i][j]) cout << j << " ";	
//		}
//		cout << "\n";
//	}
	
	while(q--)
	{
		if(c >= 12 && c <= 19)
		{
			cin >> start >> end;
			bool vis[M] = {};
			cost = s[start] + s[end];
			cout << dfs2(start) << "\n";
			continue; 
		}
		cin >> start >> end;
		bool vis[M] = {};
		cost = s[start] + s[end];
		ans = -1;
		dfs(start);
		cout << ans << "\n";
	}
	
	return 0;	
}
