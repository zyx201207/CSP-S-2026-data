#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,c,d,t,k,x,y,w[500010],b[510],e[510][510],dis[510][510];
struct node
{
	int v,value;
	int operator<(node k)const
	{
		return value>k.value;
	}
};
priority_queue<node> q;
vector<node> line[500010],v[600010];
void dijkstra(int u)
{
	dis[u][u]=0;
	for(int i=1;i<=n;i++) b[i]=0;
	q.push({u,0});
	while(!q.empty())
	{
		int x=q.top().v,value=q.top().value;
		q.pop();
		if(b[x])continue;
		b[x]=1;
		dis[u][x]=value;
		for(int i=0;i<v[x].size();i++)
		  if(!b[v[x][i].v])
		    q.push({v[x][i].v,v[x][i].value+value});
	}
}
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
signed main()
{
	freopen("subway.in","r",stdin);
//	freopen("subway7.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();t=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)
		{
			x=read();
			y=read();
			line[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    e[i][j]=1e18;
	for(int i=1;i<=m;i++)
	  for(int j=0;j<line[i].size();j++)
		for(int l=j+1;l<line[i].size();l++) 
		if(e[line[i][j].v][line[i][l].v]>line[i][j].value+line[i][l].value)
		{
			x=line[i][j].value+line[i][l].value;
			e[line[i][j].v][line[i][l].v]=x;
			e[line[i][l].v][line[i][j].v]=x;
		}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    if(e[i][j]<1e18) v[i].push_back({j,e[i][j]});
	for(int i=1;i<=n;i++)dijkstra(i);
	while(t--)
	{
		x=read();
		y=read();
		ans=1e18;
		for(int i=0;i<line[x].size();i++)
		  for(int j=0;j<line[y].size();j++)
		    ans=min(ans,dis[line[x][i].v][line[y][j].v]+line[x][i].value+line[y][j].value);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
 } 
