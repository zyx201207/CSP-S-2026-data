#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
struct node {int v,w;};
vector<node> G[1010010];
int c,n,m,d,q,dis[1010010];
bool inq[1010010];
void SPFA(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	dis[s] = 0;
	inq[s] = 1;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		inq[u] = 0;
		q.pop();
		for(int i=0;i<G[u].size();i++)
		{
			int v = G[u][i].v,w = G[u][i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v] = dis[u]+w;
				if(inq[v]==0)
				{
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		int ti;
		cin >> ti;
		G[i].push_back({i+m,ti});
		G[i+m].push_back({i,ti});
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		while(k--)
		{
			int u = 2*m+i,v,w;
			cin >> v >> w;
			v+=m;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
		}
	}
	while(q--)
	{
		int u,v;
		cin >> u >> v;
		SPFA(u);
		cout << dis[v] << endl;
	}
	return 0;
 } 
