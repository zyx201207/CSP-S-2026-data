#include<bits/stdc++.h>
using namespace std;
int C,T,n,k;
vector<int> d[15];
bitset<15> vis;
void dfs1(int x,int status)
{
	vis[x] = 1;
	for(int to:d[x]) if(!vis[to] and ((1<<to-1)&status))
	{
		dfs1(to,status);
	}
}
bool check(int x)
{
	int tol(0);
	for(int i(1);i <= n;++i) if(!vis[i] and ((1<<i-1)&x))
	{
		dfs1(i,x);
		++tol;
	}
	return (tol <= 2);
}
deque<pair<int,int>> q;
int bfs(int status)
{
	while(!q.empty())
	{
		int x(q.front().first);
		int val(q.front().second);
		q.pop_front();
		if(vis[x]) continue;
		vis[x] = 1;
		if((1<<x-1)&status)
		{
			return val;
		}
		for(int to:d[x]) if(!vis[to]) q.emplace_back(make_pair(to,val+1));
	}
	return n-1;
}
void subtask1to3()
{
	for(cin >> T;T;--T)
	{
		cin >> n >> k;
		for(int i(1),u,v;i^n;++i)
		{
			cin >> u >> v;
			d[u].emplace_back(v);
			d[v].emplace_back(u);
		}
		int ans(n+1);
		for(int status(0);status^(1<<n);++status)
		{
			if(__builtin_popcount(status) != k) continue;
			vis.reset();
			if(!check(status)) continue;
			int tmp(0);
			for(int i(1);i <= n;++i)
			{
				q.clear();
				q.emplace_back(make_pair(i,0));
				vis.reset();
				tmp = max(tmp,bfs(status));
			}
			ans = min(ans,tmp);
		}
		cout << ans << "\n"; 
		
		for(int i(1);i <= n;++i) d[i].clear();
		vis.reset();
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> C;
	subtask1to3();
	return 0; 
}
