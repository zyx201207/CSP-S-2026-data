#include <bits/stdc++.h>

using namespace std;

typedef pair<int,long long> PII;

int c,n,m,d,q;
long long w[500010];
map<PII,long long> dis;
vector<PII> p[500010];
vector<int> g[500010];

struct node
{
	long long val;
	int idx;
	int sub;
};

bool operator > (node A,node B)
{
	return A.val < B.val;
}

long long dij(int u,int v)
{
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			dis[{i,j}] = 0x3f3f3f3f3f3f3f3f;
	
	priority_queue<node,vector<node>,greater<node> > q;
	for (PII ite : p[u])
	{
		int a = ite.first;
		long long t = ite.second;
		q.push({w[u] + t,u,a});
		dis[{u,a}] = w[u] + t;
	}

	while (!q.empty())
	{
		node tp = q.top();
		q.pop();
		
		int u1 = tp.idx;
		long long w1 = tp.val;
		int sb = tp.sub;
		for (int v1 : g[u1])
		{
			for (PII ite : p[v1])
			{
				int a = ite.first;
				
				long long ans = 0;
				if (a != sb)
				{
					bool flag = false;
					bool flag1 = false;
					for (PII op : p[v1])
					{
						if (op.first == sb)
						{
							flag = true;
							break;
						}
					}
					
					for (PII op : p[u1])
					{
						if (op.first == a)
						{
							flag1 = true;
							break;
						}
					}
					
					long long sum = 0,sum1 = 0;
					for (PII op : p[v1])
						if (op.first == sb || op.first == a)
							sum += op.second;
					
					for (PII op : p[u1])
						if (op.first == sb || op.first == a)
							sum1 += op.second;
					
					if (flag && flag1)
						ans = min(sum,sum1);
					else if (flag)
						ans = sum;
					else if (flag1)
						ans = sum1;
				}
				
				if (dis[{v1,a}] > w1 + ans)
				{
					dis[{v1,a}] = w1 + ans;
					q.push({w1 + ans,v1,a});
				}
			}
		}
	}
	
	long long mn = 0x3f3f3f3f3f3f3f3f;
	for (PII ite : p[v])
	{
		int a = ite.first;
		long long t = ite.second;
		mn = min(mn,dis[{v,a}] + t + w[v]);
	}
	return mn;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	
	for (int i = 1; i <= m; i++)
		cin >> w[i];
		
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		
		int last = -1;
		for (int j = 1; j <= k; j++)
		{
			int a;
			long long t;
			cin >> a >> t;
			
			p[a].push_back({i,t});
			
			if (last != -1)
				g[last].push_back(a);
			last = a;
		}
	}
	
	while (q--)
	{
		int u,v;
		cin >> u >> v;
		
		cout << dij(u,v) << "\n";
	}
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
