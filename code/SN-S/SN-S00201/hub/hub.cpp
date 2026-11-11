#include<bits/stdc++.h>
using namespace std;
int c,T;
const int N=105;
vector<int> e[N];
bool vis[N],used[N],dk[N];
int dis[N][N];
int n,k;
int ans=INT_MAX;
vector<int> ee;
//int dfs_lu(int u,int dd,int step)
//{
//	if(u==dd)return step;
//	for(int i=0;i<e[u].size();i++)
//	{
//		int v=e[u][i];
//		if(used[v])continue;
//		used[v]=1;
//		dfs_lu(v,dd,step+1);
//	}
//}
void solve()
{
	int Max=-1;	
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		int now=INT_MAX;
		for(auto j : ee)
		{
			memset(used,0,sizeof(used));
			used[i]=true;
//			int dis=dfs_lu(i,j,0);
//			cout<<i<<' '<<j<<' '<<dis<<'\n';
			now=min(now,dis[i][j]);
		}
//		cout<<'\n';
		Max=max(Max,now);
	}
	ans=min(ans,Max);
}
void dfs_check(int u)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(used[v])continue;
		used[v]=1;
		if(vis[v])
		{
			dk[v]=1;
			dfs_check(v);
		}
	}
}
bool check1()
{
//	cout<<"***";
	int dd=0;
	memset(dk,0,sizeof(dk));
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]||dk[i])continue;
		memset(used,0,sizeof(used));
		dd++,dk[i]=1,used[i]=1;
		dfs_check(i);
	}
	if(dd>2)return false;
	return true;
}
void dfs(int step,int cnt)
{
//	cout<<step<<' '<<cnt<<'\n';
	if(cnt>k)return;
	if(step==n+1&&cnt==k)
	{
//		for(auto i : ee)cout<<i<<' ';
//		cout<<'\n';
		if(!check1())return;
//		for(auto i : ee)cout<<i<<' ';
//		cout<<'\n';
		solve();
		return;
	}
	if(step==n+1)return;
	vis[step]=1;
	ee.push_back(step);
	if(cnt+1<=k)dfs(step+1,cnt+1);
	ee.pop_back();
	vis[step]=0;
	dfs(step+1,cnt);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>k;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)e[i].clear();
		ee.clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j&&j!=k&&k!=i)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		ans=INT_MAX;
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
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
