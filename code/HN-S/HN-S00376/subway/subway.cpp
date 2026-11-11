#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[505][50005],b[505][50005],k[1000005],w[1000005],f[505][50005];
vector<int>v[1000005];
struct node
{
	int x,step;
};
int vis[1000005],dis[1000005];
int bfs(int s,int e)
{
	queue<node>q;
	q.push({s,0});
	dis[s]=0;
	while(q.size())
	{
		auto u=q.front();
		if(u.x==e)
		{
			return u.step;
		}
		if(vis[u.x])
		{
			continue;
		}
		dis[u.x]=u.step;
		vis[u.x]=1;
		for(int i:v[u.x])
		{
			for(int l=1;l<=k[i];l++)
			{
				int v=a[i][l];
				int w=b[i][u.x]+b[i][v];
				if(dis[v]>dis[u.x]+w)
				{
					dis[v]=dis[u.x]+w;
					q.push({v,dis[v]});
				}
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
  	freopen("subway.in","r",stdin);
   	freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>b[i][a[i][j]];
			v[a[i][j]].push_back(i);
		}
	}
	if(c<=8)
	{		
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j]=1e18;
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(auto j:v[i])
			{
				for(int l=1;l<=k[j];l++)
				{
					f[i][a[j][l]]=min(f[i][a[j][l]],b[j][i]+b[j][a[j][l]]);
					f[a[j][l]][i]=min(f[a[j][l]][i],b[j][i]+b[j][a[j][l]]);
				}
			}
			f[i][i]=0;
		}
		for(int k=1;k<=m;k++)
		{
			for(int i=1;i<=m;i++)
			{
				for(int j=1;j<=m;j++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				 } 
			}
		}
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			int ans=w[x]+w[y];
			cout<<ans+f[x][y]<<endl;
		}
	}
	if(c<=19&&c>=12)
	{
		while(q--)
		{
			int x,y;
			cin>>x>>y;
			int ans=w[x]+w[y];
			for(int i=1;i<=m;i++)
			{
				dis[i]=1e9;
				vis[i]=0;
			}
			cout<<ans+bfs(x,y)<<endl;
		 } 
	}
	return 0;
 }
 //17:07 想到32pts做法 floyd 
//17:36 32pts拿下
//17:42想到性质B bfs 
//17:47 深刻意识到n、d有问题但是没有时间思考，意识到bfs只能通过12~15,16分，有点不想写。
//18:00 还是来写bfs了。
//18:03 意识到dijkstra更好。 
//18:17不知道为什么超时了，没时间了，不管了；
// freopen(".in","r",stdin); 
// freopen(".out","w",stdout); 
//顺便诈骗一下。 
//long long 数组大小
//文件目录 
//输出格式
//多测清空 
//以上所有内容于18:26检查完毕，无误。 
//18:28 主文件夹所在目录打开，停止一切对代码、样例等的操作。 
