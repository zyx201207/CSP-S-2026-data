#include <bits/stdc++.h>

using namespace std;

const int N=5e5+5;

int opt,n,m,d,Q,l[N],r[N],e[1005][1005];

long long w[N],ans[1005][1005],k[N];

struct Node
{
	int x,step;
	bool operator<(const Node x)const
	{
		return step>x.step;
	}
};

void dijkstra(int st)
{
	priority_queue<Node> q;
	q.push(Node{st,0});
	while(!q.empty())
	{
		int x=q.top().x,ep=q.top().step;
		q.pop();
		for(int i=1;i<=m;i++)
		{
			if(e[x][i]!=1e9&&i!=x)
			{
				if(ep+e[x][i]<k[i])
				{
					k[i]=ep+e[x][i];
					q.push(Node{i,k[i]});
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>opt>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) e[i][j]=1e9;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++) scanf("%d%d",&r[j],&l[j]);
		for(int u=1;u<=k[i];u++)
		{
			for(int v=u+1;v<=k[i];v++)
			{
				e[r[v]][r[u]]=e[r[u]][r[v]]=min(e[r[u]][r[v]],l[u]+l[v]);
			}
		}
	}
	for(int i=1;i<=Q;i++) cin>>l[i]>>r[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++) k[j]=1e18;
		k[i]=0;
		dijkstra(i);
		for(int j=1;j<=m;j++) ans[i][j]=k[j];
	}
	for(int i=1;i<=Q;i++)
	{
		cout<<ans[l[i]][r[i]]+w[l[i]]+w[r[i]]<<endl;
	}
	return 0;
}
