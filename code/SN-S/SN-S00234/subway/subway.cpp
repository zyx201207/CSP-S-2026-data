#include<bits/stdc++.h>
using ll=long long;
using namespace std;

const int maxn=2005;

int c,n,m,d,q;

int dis[maxn][maxn],w[maxn],a[maxn][maxn];

struct node{
	int v,w;
};
vector<node> g[maxn];

void spfa(int x)
{
	queue<int> q;
	q.push(x);
	dis[x][x]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(dis[x][v.v]>dis[x][u]+v.w)
			{
				dis[x][v.v]=dis[x][u]+v.w;
				q.push(v.v);
			}
		}
	}
	return ;
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int v,w;
			cin>>v>>w;
			g[v].push_back(node{i+m,w});
			g[i+m].push_back(node{v,w});
		}
	}
	for(int i=1;i<=n+m;i++)
		spfa(i);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}
