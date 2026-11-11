#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct ra
{
	int x,y;
};
struct sta
{
	int num;
	int t;
};
struct node
{
	int minn;
	int fr;
};
int c,n,m,d,qq;
int w[500010];
vector<sta> st[500010];
int mp[510][510];
node a[510][510];
int vis[510];
queue<ra> q;
int main()
{
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			st[i].push_back({x,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<st[i].size();j++)
		{
			for(int k=j+1;j<st[i].size();k++)
			{
				int x=st[i][j].num,y=st[i][k].num,nt=st[i][j].t+st[i][k].t;
				if(mp[x][y]==0)
				{
					mp[x][y]=mp[y][x]=nt;
				}
				else
				{
					mp[x][y]=mp[y][x]=min(mp[x][y],nt);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]&&vis[j]==0)
			{
				q.push({i,j});
			}
		} 
		while(!q.empty())
		{
			ra r=q.front();
			q.pop();
			int rx=r.x,ry=r.y;
			int l=mp[rx][ry];
			if(a[i][ry].minn>a[i][rx].minn+l)
			{
				a[i][ry].minn=a[i][rx].minn+l;
				a[i][ry].fr=rx;
			}
			a[rx][ry]=a[ry][rx];
			for(int j=1;j<=n;j++)
			{
				if(mp[ry][j]&&a[rx][ry].fr!=j&&vis[j]==0)
				{
					q.push({ry,j});
				}
			}
		}
		vis[i]=1;
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(k!=i)
				{
					mp[j][k]=min(mp[j][k],mp[j][i]+mp[i][k]);
					mp[k][j]=mp[j][k];
				}
			}
		}
	}
	for(int k=1;k<=qq;k++)
	{
		int x,y;
		cin>>x>>y;
		int ans=1000000000;
		for(int i=0;i<st[x].size();i++)
		{
			for(int j=0;j<st[y].size();i++)
			{
				ans=min(ans,a[st[x][i].num][st[y][j].num].minn+st[x][i].t+st[y][j].t);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
