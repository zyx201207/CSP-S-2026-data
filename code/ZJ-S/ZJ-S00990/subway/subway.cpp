#include<bits/stdc++.h>
using namespace std;
long long c,n,m,dr,q,a,t,w[114],k,tong[500004],u,v,sum,d[514];
bool vis[514];
priority_queue<pair<long long,long long>> qu;
vector<pair<long long,long long>> g[200004],h[514];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	cin >> c >> n >> m >> dr >> q;
	for(int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> k;
		for(int j = 1;j <= k;j ++)
		{
			cin >> a >> t;
			tong[a] ++;
			if(tong[a] >= 1)
			{
				for(auto bl : g[a])
				{
					long long blf = bl.first,bls = bl.second;
					h[blf].push_back({a,t + bls});
					h[a].push_back({blf,t + bls});
				}
			}
			g[a].push_back({i,t});
		}
	}
	for(int i = 1;i <= q;i ++)
	{
		cin >> u >> v;
		sum = 1e18;
		for(auto bl : g[u])
		{
			for(int i = 1;i <= n;i ++)
			{
				d[i] = 1e18;
				vis[i] = false;
			}
			int o = bl.first;
			d[o] = bl.second;
			qu.push({-d[o],o});
			while(!qu.empty())
			{
				auto hun = qu.top();
				int xz = hun.second;
				qu.pop();
				vis[xz] = true;
				for(auto nl : h[xz])
				{
					int nlf = nl.first,nls = nl.second;
					if(vis[nlf])
					{
						continue;
					}
					if(d[nlf] > d[xz] + nls)
					{
						d[nlf] = d[xz] + nls;
						qu.push({-d[nlf],nlf});
					}
				}
			}
			for(auto nl : g[v])
			{
				long long xz = nl.first,xzv = nl.second;
				sum = min(sum,d[xz] + xzv);
			}
		}
		cout << sum + w[u] + w[v] << endl;
	}
	return 0;
}