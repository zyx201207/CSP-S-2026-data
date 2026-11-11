#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void bfs(vector<vector<int>> &adj, vector<int> &dis, int start)
{
	queue<int> q;
	q.push(start);
	dis[start] = 0;
	vector<bool> vis(adj.size(),false);
	vis[start] = true;
	while(q.empty() == false)
	{
		int u = q.top();
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

void calc(vector<int>&s)
{
	
}

void search(vector<vector<int>> &adj,int k,int cur,vector<int> s,vector<bool> choose)
{
	if (cur > k)
	{
		return;
	}
	for(int i = 1; i < adj.size(); i ++)
	{
		if (choose[i] == false)
		{
			choose[i] = true;
			s.push_back(i);
			search(adj,k,cur+1,s,choose);
			s.pop_back();
			choose[i] = false;
		}
	}
}

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t > 0)
	{
		t --;
		int n,k
		cin >> n >> k;
		vector<vector<int>> adj(n+1);
		for (int i = 1; i < n; i ++)
		{
			int u,v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	return 0;
}
