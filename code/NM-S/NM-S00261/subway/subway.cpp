#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXF=1005;
int ex[MAXN];
int edge[25];
int edist[25];
int vis[MAXN];
int dist[MAXF][MAXF];
vector<int> g[MAXN];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin>>c;
	if(c>=1 and c<=6)
	{
		int n,m,d,p;
		cin>>n>>m>>d>>p;
		for(int i=1;i<=m;i++)
		{
			cin>>ex[i];
		}
		memset(dist,-1,sizeof(dist));
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x==1) continue;
			cin>>edge[1]>>edist[1];
			for(int j=2;j<=x;j++)
			{
				cin>>edge[j]>>edist[j];
				for(int k=1;k<=j;k++)
				{
					if(edge[j]==edge[k]) continue;
					dist[edge[j]][edge[k]]=edist[k]+edist[j];
					dist[edge[k]][edge[j]]=edist[k]+edist[j];
				}
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(dist[i][k]!=-1 and dist[k][j]!=-1)
					{
						if(dist[i][j]!=-1)
						{
							dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
						}
						else
						{
							dist[i][j]=dist[i][k]+dist[k][j];
						}
						if(dist[j][i]!=-1)
						{
							dist[j][i]=min(dist[j][i],dist[i][k]+dist[k][j]);
						}
						else
						{
							dist[j][i]=dist[i][k]+dist[k][j];
						}
					}
				}
			}
		}
		for(int i=0;i<p;i++)
		{
			int st,ed;
			cin>>st>>ed;
			cout<<dist[st][ed]+ex[st]+ex[ed]<<'\n';
		}
	}
	if(c>=7 and c<=11)
	{
		int n,m,d,p;
		cin>>n>>m>>d>>p;
		for(int i=1;i<=m;i++)
		{
			cin>>ex[i];
		}
		memset(dist,-1,sizeof(dist));
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x==1) continue;
			int u,d1,v,d2;
			cin>>u>>d1>>v>>d2;
			dist[u][v]=d1+d2;
			dist[v][u]=d1+d2;
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(dist[i][k]!=-1 and dist[k][j]!=-1)
					{
						if(dist[i][j]!=-1)
						{
							dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
						}
						else
						{
							dist[i][j]=dist[i][k]+dist[k][j];
						}
						if(dist[j][i]!=-1)
						{
							dist[j][i]=min(dist[j][i],dist[i][k]+dist[k][j]);
						}
						else
						{
							dist[j][i]=dist[i][k]+dist[k][j];
						}
					}
				}
			}
		}
		for(int i=0;i<p;i++)
		{
			int st,ed;
			cin>>st>>ed;
			cout<<dist[st][ed]+ex[st]+ex[ed]<<'\n';
		}
	}
	if(c>=12 and c<=19)
	{
		int n,m,d,p;
		cin>>n>>m>>d>>p;
		for(int i=1;i<=m;i++)
		{
			cin>>ex[i];
		}
		int di;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x==1) continue;
			cin>>edge[1]>>edist[1];
			for(int j=2;j<=x;j++)
			{
				cin>>edge[j]>>di;
				for(int k=1;k<=j;k++)
				{
					if(edge[j]==edge[k]) continue;
					g[edge[k]].push_back(edge[j]);
					g[edge[j]].push_back(edge[k]);
				}
			}
		}
		queue<int> q;
		for(int i=0;i<p;i++)
		{
			fill(vis,vis+m+1,-1);
			int st,ed;
			cin>>st>>ed;
			q.push(st);
			vis[st]=0;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				if(u==ed)
				{
					break;
				}
				for(int v:g[u])
				{
					if(vis[v]==-1)
					{
						vis[v]=vis[u]+1;
						q.push(v);
					}
				}
			}
			cout<<vis[ed]*di*2+ex[st]+ex[ed]<<'\n';
			while(!q.empty())
			{
				q.pop();
			}
		}
	}
	return 0;
}
