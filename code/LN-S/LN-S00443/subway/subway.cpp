#include <bits/stdc++.h>
using namespace std;
const int M=1e5+10,N=5e2+10;
int w[M],lo[N],a[M],t[N][M],ti[N][N],f[N],c,n,m,d,tim;
vector<int> v[M];
int g[N][N];
queue<int>q;
void bfs(int x,int y)
{
	q.push(x);
	f[x]=0;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=1;i<=n+2;i++)
		{
			if(g[u][i]!=0 and f[i]>g[u][i]+f[u])
			{
				q.push(i);
				f[i]=g[u][i]+f[u];
			}
		}
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>tim;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>lo[i];
		for(int j=1;j<=lo[i];j++)
		{
			int x;
			cin>>x;
			cin>>t[i][x];
			v[x].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)ti[i][j]=INT_MAX;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)(v[i].size());j++)
		{
			for(int k=j+1;k<(int)(v[i].size());k++)
			{
				int qi=v[i][j],h=v[i][k];
				ti[qi][h]=min(ti[qi][h],t[qi][i]+t[h][i]);
				ti[h][qi]=ti[qi][h];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(ti[i][j]==INT_MAX)ti[i][j]=0;
			g[i][j]=ti[i][j];
			g[j][i]=g[i][j];
		}
	}
	while(tim--)
	{
		int l,r;
		if(l==r)
		{
			cout<<0;
			continue;
		}
		for(int i=1;i<=n+2;i++)f[i]=INT_MAX;
		cin>>l>>r;
		for(int i=1;i<=n;i++)g[n+1][i]=0,g[i][n+2]=0;
		for(int x:v[l])g[n+1][x]=t[x][l];
		for(int x:v[r])g[x][n+2]=t[x][r];
		bfs(n+1,n+2);
		cout<<f[n+2]+w[l]+w[r]<<endl;
	}
	return 0;
}
