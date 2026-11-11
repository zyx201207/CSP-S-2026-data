#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,qq;
const int N=5e5+5;
int w[N];//表示每个地铁站从站口走到站厅需要的时间
int dis[505][505],a[505][505],u[N];
int used[505][505];
bool vis[505];
vector<int> e[N];
queue<pair<int,int> > q;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	system("fc myT2.out subway4.ans");
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)cin>>w[i];
	memset(dis,0x3f,sizeof(dis));
	if(m<=1000)
	{
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)
			{
				int t;
				cin>>u[j]>>t;
				a[u[j]][i]=t;
			}
			for(int j=1;j<=k;j++)
			{
				for(int jj=1;jj<=k;jj++)
				{
					if(j==jj)continue;
					if(used[u[j]][u[jj]])
					{
						if(a[u[j]][i]<dis[u[j]][used[u[j]][u[jj]]])used[u[j]][u[jj]]=i;
					}
					else used[u[j]][u[jj]]=used[u[jj]][u[j]]=i;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(used[i][j])dis[i][j]=w[i]+a[i][used[i][j]]+a[j][used[i][j]]+w[j];
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(i==j||j==k||k==j)continue;
					if(used[i][k]&&used[j][k])
					{
						dis[i][j]=min(w[i]+a[i][used[i][k]]+a[k][used[i][k]]+a[k][used[j][k]]+a[j][used[j][k]]+w[j],dis[i][j]);	
					}
				}
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(i==j||j==k||k==j)continue;
					dis[i][j]=min(dis[i][k]+dis[k][j]-w[k]*2,dis[i][j]);	
				}
			}
		}
		while(qq--)
		{
			int l,r;
			cin>>l>>r;
			cout<<dis[l][r]<<'\n';
		}	
	}
	else
	{
		
		int tim;
		for(int i=1;i<=n;i++)
		{
			int k;
			cin>>k;
			for(int j=1;j<=k;j++)cin>>u[j]>>tim;
			for(int j=1;j<=k;j++)
			{
				for(int jj=1;jj<=k;jj++)
				{
					if(j==jj)continue;
					e[u[j]].push_back(u[jj]);
					e[u[jj]].push_back(u[j]);	
				}
			} 
		}
//		for(int i=1;i<=m;i++)
//		{
//			for(auto j : e[i])cout<<i<<' '<<j<<' ';
//			cout<<'\n';
//		}
		while(qq--)
		{
			int l,r;
			cin>>l>>r;
			while(!q.empty())q.pop();
			q.push({l,0});
			int dkk=0;
			memset(vis,0,sizeof(vis));
			while(!q.empty())
			{
				int u=q.front().first,sum=q.front().second;
//				cout<<u<<' '<<sum<<'\n';
				q.pop();
				if(u==r)
				{
//					cout<<sum<<'\n';
					dkk=sum;
					break;
				}
				if(vis[u])continue;
				vis[u]=true;
				for(int i=0;i<e[u].size();i++)
				{
					int v=e[u][i];
					if(vis[v])continue;
//					cout<<v<<' ';
					q.push({v,sum+1});
				}
			}
//			cout<<dkk<<'\n';
			cout<<w[l]+dkk*2*tim+w[r]<<'\n';
		}
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
