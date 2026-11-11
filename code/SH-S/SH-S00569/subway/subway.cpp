#include<bits/stdc++.h>

using namespace std;

int c,n,m,d,q,dt[505][50005],k[505],to[50005][505],t[50005],s[505],ton[505][50005];

bool vis[505][50005],vist[505];

void bfs(int x,int y)
{
	memset(vis,0,sizeof(vis));
	queue<int> qu;
	queue<int> a;
	queue<int> b;
	for(int i=1;i<=t[x];i++)
	{
		qu.push(x);
		a.push(0);
		b.push(to[x][i]);
	}
	for(int i=1;i<=505;i++)
	{
		vis[i][x]=1;
	}
	while(qu.empty())
	{
		int o=qu.front();
		int oo=a.front();
		int ooo=b.front();
		a.pop();
		b.pop();
		qu.pop();
		for(int i=1;i<=t[o];i++)
		{
			if(vist[i])
			{
				continue;
			}
			for(int j=1;j<=s[to[o][i]];j++)
			{
				if(vis[to[o][i]][ton[to[o][i]][j]])
				{
					continue;
				}
				if(ton[to[o][i]][j]==y)
				{
					cout<<oo+dt[to[o][i]][ton[to[o][i]][j]]<<'\n';
					return ;
				}
				else
				{
					vis[to[o][i]][ton[to[o][i]][j]]=1;
					qu.push(ton[to[o][i]][j]);
					a.push(oo);
					b.push(to[o][i]);
					for(int p=1;p<=t[ton[to[o][i]][j]];p++)
					{
						if(!vis[to[ton[to[o][i]][j]][p]])
						{
							qu.push(ton[to[o][i]][j]);
							a.push(oo+dt[to[o][i]][ton[to[o][i]][j]]+dt[to[o][j]][ton[to[o][i]][j]]);
							b.push(to[ton[to[o][i]][j]][p]);
						}
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
	while(cin>>c>>n>>m>>d>>q)
	{
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			s[i]=x;
			for(int j=1;j<=x;j++)
			{
				int r;
				cin>>r>>dt[i][j];
				to[r][t[r]]=i;
				ton[i][j]=r;
				t[r]++;
			}
		}
		for(int i=1;i<=q;i++)
		{
			int x,y;
			bfs(x,y);
		}
	}
	return 0;
}
