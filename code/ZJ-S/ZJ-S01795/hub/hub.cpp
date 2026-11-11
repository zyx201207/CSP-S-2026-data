#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int c , T , n , k;
int tot , d[N]; 
bool tag[N] , vis[N];
vector<int>g[N];
void Dfs1(int u)
{
	tag[u] = 0;
	for(int v : g[u])
	{
		if(!tag[v])continue ;
		Dfs1(v);
	}
}
void Solve()
{
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
		g[i].clear();
	for(int i = 2 ; i <= n ; i++)
	{
		int u , v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = n + 1;
	for(int s = 1 ; s < (1 << n) ; s++)
	{
		if(__builtin_popcount(s) == k)
		{
			tot = 0;
			for(int i = 1 ; i <= n ; i++)
				tag[i] = ((s >> (i - 1)) & 1);
			for(int i = 1 ; i <= n ; i++)
				if(tag[i])
				{
					tot++;
					Dfs1(i);
					if(tot > 2)break ;
				}
			if(tot > 2)continue ;
			queue<int>qu;
			for(int i = 1 ; i <= n ; i++)
				vis[i] = 0;
			for(int i = 1 ; i <= n ; i++)
			{
				if((s >> (i - 1)) & 1)
				{
					// cerr << i << ',';
					d[i] = 0;
					vis[i] = 1;
					qu.push(i);
				}
			}
			while(!qu.empty())
			{
				int u = qu.front(); qu.pop();
				for(int v : g[u])
				{
					if(vis[v])continue ;
					d[v] = d[u] + 1;
					vis[v] = 1;
					qu.push(v);
				}
			}
			int res = 0;
			for(int i = 1 ; i <= n ; i++)
				res = max(res , d[i]);
			if(tot <= 2)
				ans = min(ans , res);
			// cerr << '\n';
			// for(int i = 1 ; i <= n ; i++)
			// 	cerr << d[i] << " \n"[i == n];
			// cerr << ":" << res << "\n";
		}
	}
	cout << ans << "\n";
	return ;
}
int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> c >> T;
	while(T--)Solve();
	return 0;
}