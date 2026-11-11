#include <bits/stdc++.h>
using namespace std;
int a[500005];
struct node
{
	int id,t;
}line[500005];
struct sub
{
	int to,w;
};
vector <sub> g[2005]; 
int st,ed;
int dist[2005][2005];
int c , n ,m,d,q;

void dijt(int i,int j)
{
	queue<int> q;
	for(auto k : g[i])
	{
		q.push(k.to);
	}
	while(!q.empty())
	{
		int nn = q.front();
		q.pop();
		for(auto k : g[nn])
		{
			if(dist[i][nn]+dist[nn][k.to]<dist[i][k.to])
			{
				dist[i][k.to] = dist[i][nn]+dist[nn][k.to];
				q.push(k.to);
			}
		}
		
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof(dist));
	
	cin >> c >> n >> m >>d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j =1; j <= k; j++)
		{
			cin >> line[j].id>>line[j].t;
		}
		for(int j = 1; j <= k; j++)
		{
			for(int l = j+1;l <= k; l++)
			{
				g[line[j].id].push_back({line[l].id,line[j].t+line[l].t});
				g[line[l].id].push_back({line[j].id,line[j].t+line[l].t});
				dist[line[j].id][line[l].id] =min(line[j].t+line[l].t,dist[line[j].id][line[l].id]);
				dist[line[l].id][line[j].id] =min(line[j].t+line[l].t,dist[line[l].id][line[j].id]);
			}
		}
	}	
	for(int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = i+1; j <= m; j++)
		{
			dijt(i,j);
		}
	}
	
	while(q--)
	{
		cin >> st >> ed;
		cout << dist[st][ed]+a[st]+a[ed]<<"\n";
	}
	return 0;
}
