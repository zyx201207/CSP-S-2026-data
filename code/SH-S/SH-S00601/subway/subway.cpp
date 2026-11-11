#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 5e5 + 550;
const int M = 5e5 + 10;

int C, n, m, d, Q;//n:nums of train
//m:nums of station
int sum;
int bas[M];
vector<pair<int, int> > g[N];//{weight, toWhere}

int dij(int st, int ed)
{
//	cout<<st<<endl;
	vector<int> dis(n + m + 2, 0x3f3f3f3f);
	vector<bool> vis(n + m + 2, 0);
	priority_queue<pair<int, int> > q;//{dis, where}
	dis[st] = 0;
	q.push({0, st});
	while(!q.empty())
	{
		auto p = q.top();
		q.pop();
		if(vis[p.second]) continue;
		vis[p.second] = 1;
		
//		cout<<p.second<<endl;
		
		for(auto nx : g[p.second])
		{
			int i = nx.first;
			int j = nx.second;
			if(vis[j]) continue;
//			cout<<i<<':'<<j<<endl;
			dis[j] = min(dis[j], i - p.first);
			q.push({-dis[j], j});
		}
	}
	
	return dis[ed] + bas[st] + bas[ed];
	
//	cout<<endl<<st<<endl;
//	for(int i = 1; i <= m ; i ++)
//	{
//		cout<<dis[i]<<' ';
//	}
//	cout<<endl;
	
//	ans[st][0] = 1;
//	for(int i = 1; i <= m; i ++)
//	{
//		ans[st][i] = dis[i] + bas[st] + bas[i];
//	}
//	return ;
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>C>>n>>m>>d>>Q;
	for(int i = 1; i <= m ; i ++)
	{
		cin>>bas[i];
	}
	for(int i = 1; i <= n; i ++)
	{
		int k;
		cin>>k;
		sum += k; 
		for(int j = 1; j <= k ; j ++)
		{
			int u, v;
			cin>>u>>v;
			g[m + i].push_back({v, u});
			g[u].push_back({v, m + i});
		}
	}
	
//	for(int i = 1; i <= m ; i ++)
//	{
//		cout<<i<<' ';
//		for(auto p : g[i])
//		{
//			cout<<p.first<<':'<<p.second<<' ';
//		}
//		cout<<endl;
//	}
//	for(int i = 1; i <= n; i ++)
//	{
//		cout<<i + m<<' ';
//		for(auto p : g[i + m])
//		{
//			cout<<p.first<<':'<<p.second<<' ';
//		}
//		cout<<endl;
//	}
	
	while(Q--)
	{
		int st, ed;
		cin>>st>>ed;

		cout<<dij(st, ed)<<endl;

//		if(!ans[st][0])
//		{
////			cout<<"dji "<<st<<endl;
//			dij(st);
//		}
//		cout<<ans[st][ed]<<endl;
	}

	return 0;
}
