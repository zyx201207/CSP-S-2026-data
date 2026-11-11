#include<bits/stdc++.h>
using namespace std;
bool v[550];
int c,n,m,d,q;
priority_queue<pair<int,int>> q;
struct node
{
	int v,e,edge;
}edge[550];
void add(int x,int y,int z)
{
	edge[++y]=({y,z,h[z]})
}
void dijkstra(int s,int x)
{
	memset(dist,0x3f,sizeof dist);
	memset(v,0,sizeof v);
	q.push({0,s});
	v[s]=1;
	while(!q.empty())
	{
		int temp=q.top().first,tamp=q.top().second;q.pop();
		if(v[tamp]==1) continue;
	}
}
int main()
{
	freopen("migrate.in","r",stdin); 
 	freopen("migrate.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
			if(j!=1)
			{
				add(a[j-1],a[j],0);
				add(a[j],a[j-1],0);
			}
			add(a[j],a[j]+m,t[j]);
			add(a[j]+m,a[j],t[j]);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		dijkstra(x+m,y+m);
		cout<<w[x]+w[y]+dist[y+m];
	}
	return 0;
}
