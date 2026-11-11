#include<bits/stdc++.h>
using namespace std;
int hx[561][500005];
int iddx[561];
struct st
{
	int to;
	int w;
	int next;
}edg[5000001];
int idx=0;
int head[2000001];
int w[500001];
void init(int n)
{
	for(int i=1;i<=2500000;i++)
	{
		head[i]=-1;
	}
}
void add(int u,int v,int w)
{
	//cout<<endl;
	//cout<<u<<" "<<v<<" "<<w<<endl;
	edg[idx]={v,w,head[u]};
	head[u]=idx;
	idx++;
}
bool vis[2500001];
int dist[2500001];
int rrr[5000001];
queue <int> pp;
int djstl(int x,int y,int n)
{
	for(int i=1;i<=2500000;i++)
	{
		dist[i]=1000000001;
		vis[i]=0;
	}
	for(int k=0;k<=1;k++)
		{
			for(int j=0;j<=20;j++)
			{
				for(int i=1;i<=n;i++)
				{
					dist[i+j*1000+k*1000000]=1000000001;
					vis[i+j*1000+k*1000000]=0;
				}
			}
		}
	dist[x]=0;
	pp.push(x);
	while(!pp.empty())
	{
		int u=pp.front();
		vis[u]=1;
		pp.pop();
	//	cout<<pp.size()<<" ";
		for(int i=head[u];i!=-1;i=edg[i].next)
		{
			int v=edg[i].to;
			int w=edg[i].w;
			/*if(u==1002003)
			{
				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<u<<" "<<v<<" "<<w<<" "<<dist[v]<<endl<<endl;
			}*/
			   
			dist[v]=min(dist[v],dist[u]+w);
		}
	//	cout<<u<<" ";
		int nin=1e9;
		int sss=0;
		for(int k=0;k<=1;k++)
		{
			for(int j=0;j<=20;j++)
			{
				for(int i=1;i<=n;i++)
				{
					if(vis[i+j*1000+k*1000000]==0)
					{
						
						if(dist[i+j*1000+k*1000000]<nin)
						{
							
							nin=dist[i+j*1000+k*1000000];
							sss=i+j*1000+k*1000000;
						}
					}
				}
			}
		}
		
		if(sss!=0)
		{
			//cout<<sss<<" "<<vis[sss]<<endl;
			//cout<<vis[1002003]<<endl;
			pp.push(sss);
		}
			
	}
	return dist[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	init(n);
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
	//	cout<<endl<<endl<<1<<endl<<endl;
		for(int j=1;j<=k;j++)
		{
			int v,w;
			cin>>v>>w;
			rrr[j]=v;
			add(1000*i+v,v+1000000+1000*i,w);
			add(v+1000000+1000*i,1000*i+v,w);
			iddx[j]++;
			hx[v][iddx[j]]=i;
		}
	//	cout<<endl<<endl<<2<<endl<<endl;
		for(int j=2;j<=m;j++)
		{
			add(rrr[j-1]+1000000+1000*i,rrr[j]+1000000+1000*i,0);
			add(rrr[j]+1000000+1000*i,rrr[j-1]+1000000+1000*i,0);
		}
	}
	//cout<<endl<<endl<<3<<endl<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=2;j<=iddx[i];j++)
		{
			if(hx[i][j]!=0&&hx[i][j-1]!=0)
			{
				add(i+1000*hx[i][j],i+1000*hx[i][j-1],0);
				add(i+1000*hx[i][j-1],i+1000*hx[i][j],0);
			}
			
		}
	}
	//cout<<endl<<endl<<4<<endl<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=d;j++)
		{
			add(i,1000*j+i,w[i]);
			add(1000*j+i,i,w[i]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<djstl(x,y,m)<<endl;
	}
}