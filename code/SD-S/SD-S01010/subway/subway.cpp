#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[500010],cost[10010][30],each[10010][30],st[10010][30];
long long w[510],dist[10010][30],td[5010][5010];
vector<int>e[20010][20];
struct node
{
	int u,op,w;
};
priority_queue<node,vector<node>,greater<node> >h;
bool operator >(const node &a,const node &b)
{
	if(a.w!=b.w)
	{
		return a.w>b.w;
	} 
	else if(a.u!=b.u)
	{
		return a.u>b.u;
	}
	else
	{
		return a.op>b.op;
	}
}
void dijkstra(int stt)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=d;j++)
		{
			st[i][j]=0;
		}
	}
	memset(dist,0x7f,sizeof dist);
	for(int j=1;j<=cost[stt][0];j++)
	{
		dist[stt][j]=cost[stt][j];
		h.push({stt,j,dist[stt][j]});
	}
	while(!h.empty())
	{
		node r=h.top();
		h.pop();
		int x=r.u,y=r.op,w=r.w;
		if(st[x][y]==1)
		{
			continue;
		}
		st[x][y]=1;
		for(int i=0;i<e[x][y].size();i++)
		{
			int v=e[x][y][i];
			int temp=0;
			for(int j=1;j<=each[v][0];j++)
			{
				if(each[v][j]==each[x][y])
				{
					if(dist[v][j]>dist[x][y])
					{
						dist[v][j]=dist[x][y];
						h.push({v,j,dist[v][j]});
					}
					temp=j;
					break;
				}
			}
			for(int j=1;j<=each[v][0];j++)
			{
				if(each[v][j]!=each[x][y]&&dist[v][j]>dist[v][temp]+cost[v][j]+cost[v][temp])
				{
					dist[v][j]=dist[v][temp]+cost[v][j]+cost[v][temp];
					h.push({v,j,dist[v][j]});
				}
			}
		}
	} 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>k[0];
		for(int j=1;j<=k[0];j++)
		{
			int x;
			cin>>k[j]>>x;
			each[k[j]][++each[k[j]][0]]=i;
			cost[k[j]][++cost[k[j]][0]]=x;
		}
		for(int j=2;j<=k[0];j++)
		{
			e[k[j-1]][each[k[j-1]][0]].push_back(k[j]);
			e[k[j]][each[k[j]][0]].push_back(k[j-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			{
				continue;
			}
			long long mn=1000000000000000000;
			for(int k=1;k<=each[j][0];k++)
			{
				mn=min(mn,dist[j][k]+cost[j][k]);
			}
			td[i][j]=mn;
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+td[x][y]+w[y]<<"\n";
	}
	return 0;
}
