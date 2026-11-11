/*
这毕竟是T4，我没有耐心也没有信心了，打个暴力走人吧
怎么打?
暴力枚举，时间复杂度O(t*c(k,n)*n^3)，期望得分5(1)+10(2,3)=15
枚举所有方案，计算是否合法 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
bool chosed[1008617];
int n,k;
vector<int> g[1008617];
bool vis[1008617];
int ans=1e18;
void ddfs(int u,int fa)
{
	vis[u]=true;
	for(int v:g[u])	
	{
		if(v==fa)continue;
		if(vis[v])continue;
		if(chosed[v]==0)continue;
		ddfs(v,u);
	}
}
bool check()
{
	int ans=0;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&chosed[i]==1)
		{
			ans++;
			ddfs(i,-1);
		}
	}
	return ans<=2;
}
int dis[5005][5005],dis2[5005][5005];
void flyed()
{
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=dis2[i][j];
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		if(i==j||k==i||k==j)continue;
		//cout<<i<<' '<<j<<' '<<k<<' '<<dis[i][k]+dis[j][k]<<'\n';
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]);
	}
}
void dfs(int i,int used)
{
	if(i==n+1)
	{
		if(used!=k||!check())
		{
			return;
		}
		//cerr<<1111<<'\n';
		int res=0;
		for(int i=1;i<=n;i++)
		{
			//if(chosed[i]!=1)continue;
			int resi=1e18;
			if(chosed[i]==1)resi=0;
			for(int j=1;j<=n;j++)
			{
				if(chosed[j]==1&&i!=j)resi=min(resi,dis[i][j]);
			}
			res=max(res,resi);
		}
		ans=min(ans,res);
	}
	if(n-i+1<k-used)return;
	if(used>k)return;
	chosed[i]=1;
	dfs(i+1,used+1);
	chosed[i]=0;
	dfs(i+1,used);
}
signed main()
{
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
//	int sum1=1,sum2=1;
//	for(int x=1;x<=10;x++)
//	{
//		for(int y=1;y<=x&&y<=10;y++)
//		{
//			sum1=1,sum2=1;
//			for(int i=x;i>=x-y+1;i--)sum1*=i;
//			for(int i=1;i<=y;i++)sum2*=i;
//			if(sum2==0)continue;
//			cout<<sum1/sum2*100*3<<'\n';
//		}
//	}
//that's something I used to check my 时间复杂度 
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		ans=1e18;
		cin>>n>>k;
		//cerr<<n<<'\n';
		for(int i=1;i<=n;i++)g[i].clear();
		memset(dis2,0x3f3f3f3f,sizeof(dis2));
		memset(chosed,0,sizeof(chosed));
		for(int i=1;i<=n;i++)dis2[i][i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			dis2[u][v]=1;
			dis2[v][u]=1;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		flyed();
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
unaccepted 18:10 15pts total:231~239
*/
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/