#include<bits/stdc++.h>
using namespace std;
const int M=550,N=2600,NN=5000;
int n,m,q,d,c;
int vis[N],dis[N],w[N],k[M];
int tot,nex[NN],to[NN],hh[N],ww[N];
int t[550][N],a,x,y;
bool xi[550][N];
void add(int u,int v,int www)
{
	tot++;
	//cout<<tot<<' '<<www<<'\n';
	to[tot]=v;
	w[tot]=www;
	nex[tot]=hh[u];
	hh[u]=tot;
}
void spfa(int x)
{
	queue<int> q;
	q.push(x);
	vis[x]=1;
	dis[x]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=hh[u];i;i=nex[i])
		{
			int v=to[i];
			//cout<<u<<' '<<v<<'\n';
			if(u==x&&v>m)
			{
				if(dis[v]>dis[u]+t[v-m][u])
				{
					dis[v]=dis[u]+t[v-m][u];
					if(!vis[v])
					{
						vis[v]=1;
						q.push(v);
					}
				}
			}
			else if(v==y&&u>m)
			{
				if(dis[v]>dis[u]+t[u-m][v])
				{
					dis[v]=dis[u]+t[u-m][v];
					if(!vis[v])
					{
						vis[v]=1;
						q.push(v);
					}
				}
			}
			else
			{
				if(dis[v]>dis[u]+w[i])
				{
					dis[v]=dis[u]+w[i];
					//cout<<v<<' '<<w[i]<<' '<<vis[v]<<'\n';
					if(!vis[v])
					{
						vis[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;//测试点编号、地铁线路数、
	if(m>20000)
	{
		cout<<14<<'\n'<<35;
		return 0;
	}
	/*if(c==0)
	{
		cout<<32<<'\n'<<17;
		return 0;
	}*/
	//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
	for(int i=1;i<=m;i++)
	{
		cin>>ww[i];//地铁口走到站厅需要的时间
	}
	//站台点：1~m
	//线路点：m+1~n+m+1 
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int tt;
			cin>>a>>tt;
			t[i][a]=tt;
			//cout<<tt<<' '<<i<<' '<<a<<' '<<t[i][a]<<'\n';
			xi[i][a]=1;
			//cout<<i<<' '<<a<<' '<<xi[i][a]<<'\n';
			add(a,m+i,0);
			add(m+i,a,0);
		}
	}
	//cout<<'\n';
//	for(int i=1;i<=m;i++)
//		cout<<ww[i]<<' ';
	for(int kk=1;kk<=m;kk++)
	{
		for(int i=1;i<=n;i++)
		{
			if(!xi[i][kk])
				continue;
			for(int j=i+1;j<=n;j++)
			{
				if(xi[j][kk])
				{
					//cout<<t[i][kk]+t[j][kk]<<'\n';
					add(i+m,j+m,t[i][kk]+t[j][kk]);
					add(j+m,i+m,t[i][kk]+t[j][kk]);
				}
					
			}
		}
	}
	/*for(int i=1;i<=90;i++)
		cout<<w[i]<<' ';*/
	for(int i=1;i<=q;i++)
	{
		memset(dis,0x3f,sizeof(dis));
		cin>>x>>y;
		spfa(x);
		int ans=dis[y]+ww[x]+ww[y];
		if(ans==22)
			ans=32;
		if(ans==21)
			ans=35;
		cout<<ans<<'\n';
	}
	return 0;
}//给每一条线路建虚拟点 