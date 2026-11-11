#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<long long> &dis, int start)
{
	queue<int> q;
	q.push(start);
	dis[start] = 0;
	vector<bool> vis(adj.size(),false);
	vis[start] = true;
	while(q.empty() == false)
	{
		int u = q.front();
		q.pop();
		for (int v : adj[u])
		{
			if (vis[v] == false)
			{
				vis[v] = true;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	vector<long long> w(m + 1);
	for (int i = 1; i <= m; i ++)
	{
		cin >>w[i];
	}
	vector<vector<int>> a(n + 1);
	vector<vector<long long>> t(n + 1);
	vector<vector<int>> lines(m + 1);
	bool spB = true;
	bool spA = true;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin>>k;
		if (k != 2)
		{
			spA = false;
		}
		a[i].resize(k + 1);
		t[i].resize(k + 1);
		for (int j = 1; j <= k; j ++)
		{
			cin >> a[i][j] >> t[i][j];
			if (j > 1)
			{
				if (t[i][j] != t[i][j - 1])
				{
					spB = false;
				}
			} else {
				if (i != 1 && t[i][j] != t[i - 1].back())
				{
					spB = false;
				}
			}
			lines[a[i][j]].push_back(i);
		}
	}
	while(q > 0)
	{
		q --;
		int x,y;
		cin >> x >> y;
		long long ans = 0;
		ans += w[x];
		ans += w[y];
		if (spB == true)
		{
			long long num = t[1][1];
			bool found = false;
			for (int xv : lines[x])
			{
				for (int yv : lines[y])
				{
					if (xv == yv)
					{
						ans += 2 * num;
						found = true;
						break;
					}
				}
				if (found == true)
				{
					break;
				}
			}
			if (found == true)
			{
				cout << ans << "\n";
				continue;
			}
			vector<vector<int>> adj(n + 1);
			for (int i = 1; i <= m; i ++)
			{
				for (int j = 0; j < lines[i].size() - 1; j ++)
				{
					for (int k = j + 1; k < lines[i].size(); k ++)
					{
						adj[lines[i][j]].push_back(lines[i][k]);
						adj[lines[i][k]].push_back(lines[i][j]);
					}
				}
			}
			vector<long long> dis(n + 1,2e6);
			long long res = 2e6;
			for (int i : lines[x])
			{
				bfs(adj,dis,i);
				for (int j : lines[y])
				{
					res = min(res,dis[j]);	
				}
			}
			ans += (res + 1) * 2 * num;
			cout << ans <<"\n";
		} else if (spA == true) {
			vector<vector<pair<int,long long>>> adj(m + 1);
			for (int i = 1; i <= n; i ++)
			{
				adj[a[i][1]].push_back({a[i][2], t[i][1] + t[i][2]});
				adj[a[i][2]].push_back({a[i][1], t[i][1] + t[i][2]});
			}
			vector<long long> dis(m + 1, 2e6);
			dis[x] = 0;
			vector<bool> vis(m + 1,false);
			priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
			pq.push({0,x});
			while(pq.empty() == false)
			{
				pair<long long,int> cur = pq.top();
				int u = cur.second;
				pq.pop();
				if (vis[u] == false)
				{
					vis[u] = true;
					for(pair<int,long long> nxt : adj[u])
					{
						long long w = nxt.second;
						int v = nxt.first;
						if (dis[u] + w < dis[v])
						{
							dis[v] = dis[u] + w;
							pq.push({dis[v],v});
						}
					}
				}
			}
			cout << dis[y] << "\n";
		}
	}
	return 0;
}
