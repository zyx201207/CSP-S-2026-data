#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int C , T;
int n , k;
vector <int> ff[N];
bool f[N] , vis[N];
int dis[N] , ans;
void dfs2(int x)
{
	vis[x] = 1;
	for(auto i : ff[x])
	{
		if(vis[i] || (!f[i])) continue;
		dfs2(i);
	}
}
void dfs(int step , int cnt)
{
	if(cnt > k) return;
	if((cnt + (n - step + 1)) < k) return;
	if(step > n)
	{
		if(cnt != k) return;
		queue <int> q;
		for(int i = 1;i <= n;i ++)
		{
			vis[i] = 0;
			dis[i] = -1;
			if(f[i])
			{
				q.push(i);
				dis[i] = 0;
			}
		}
		int cnt = 0;
		for(int i = 1;i <= n;i ++)
		{
			if(vis[i] || (!f[i])) continue;
			cnt ++;
			if(cnt >= 3) return;
			dfs2(i);
		}
		if(cnt > 2) return;
		int anss = 0;
		while(!q.empty())
		{
			int t = q.front();
			q.pop();
			for(auto i : ff[t])
			{
				if(dis[i] != -1) continue;
				dis[i] = dis[t] + 1;
				q.push(i);
				anss = max(anss , dis[i]);
			}
		}
		ans = min(ans , anss);
		return;
	}
	f[step] = 0;
	dfs(step + 1 , cnt);
	f[step] = 1;
	dfs(step + 1 , cnt + 1);
}
void solve()
{
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)
	{
		ff[i].clear();
		f[i] = 0;
		vis[i] = 0;
	}
	for(int i = 1;i < n;i ++)
	{
		int u , v;
		cin >> u >> v;
		ff[u].push_back(v);
		ff[v].push_back(u);
	}
	ans = 1e9;
	dfs(1 , 0);
	cout << ans << endl;
}
int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> C >> T;
	while(T --)
	{
		solve();
	}
    return 0;
}
//Expected 12pts
//mondayrain


//bu yao tian cuo zhun kao zheng hao!!!!!!!!!!!!!!!!!!!!
//bu yao xie cuo wen jian ming
//bu yao bu kai freopen
//bu yao bu kai longlong
//bu yao kai xiao shu zu
