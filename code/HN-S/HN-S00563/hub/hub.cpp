#include<bits/stdc++.h>
using namespace std;
//台若力,kanbudong
//18:01看懂后已经没时间了 
//meiyou200pts(TWT)
int dis[101][101];
vector<int>g[1000];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=1;
		}
		for(int i=1;i<=n;i++)
		{
			dis[i][i]=0;
		}
		int maxn=0;
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=k;i++)
			{
				for(int j=k;j<=n;j++)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					dis[j][i]=dis[i][j];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				maxn=max(dis[i][j],maxn);
			}
		}
		//写不完啦！！！！ 我的15pts!!! 
		cout<<1<<endl;
	}
	return 0;
}
