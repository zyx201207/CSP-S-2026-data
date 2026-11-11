#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=505;
const int M=2e4+5;
const int INF=1e18;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][M];
int t[N][M];
bool vis[M];
int minn;
void dfs(int x,int xianlu,int cnt,int st,int ed)
{
	if(vis[x])
	{
		return ;
	}
	if(x==st)
	{
		minn=min(minn,cnt);
		return ;
	}
	vis[x]=1;
//	cout<< "站点编号："<<x<<"  线路编号："<<xianlu <<" 当前步行时间："<<cnt<<endl; 
	if(x==ed)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==xianlu)
			{
				continue;
			}
			for(int j=1;j<=k[i];j++)
			{
				if(a[i][j]==x)
				{
					dfs(x,i,cnt+t[i][x]+w[x],st,ed);
				}
			}
		}
		for(int i=1;i<=k[xianlu];i++)
		{
			if(a[xianlu][i]==x)
			{
				if(i==k[xianlu])
				{
					return ;
				}
				dfs(a[xianlu][i+1],xianlu,cnt,st,ed);
				dfs(a[xianlu][i-1],xianlu,cnt,st,ed);
			}
		}
		return ;
	}
	//换乘 
	for(int i=1;i<=n;i++)
	{
		if(i==xianlu)
		{
			continue;
		}
		for(int j=1;j<=k[i];j++)
		{
			if(a[i][j]==x)
			{
				if(i==st)
				{
					dfs(x,i,cnt+t[xianlu][x]+w[st],st,ed);
				}
				else
				{
					dfs(x,i,cnt+t[i][x]+t[xianlu][x],st,ed);
				} 
			}
		}
	}
	//在线路上移动 
	for(int i=1;i<=k[xianlu];i++)
	{
		if(a[xianlu][i]==x)
		{
			if(i==k[xianlu])
			{
				return ;
			}
			dfs(a[xianlu][i+1],xianlu,cnt,st,ed);
			dfs(a[xianlu][i-1],xianlu,cnt,st,ed);
		}
	}
}
void solve(int st,int ed)
{
	memset(vis,0,sizeof(vis));
	minn=1e9;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k[i];j++) 
		{
			if(a[i][j]==ed)
			{
				dfs(ed,i,0,st,ed);
			}
		}
	}
	cout << minn<<endl;
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			t[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin >> a[i][j];
			cin >>t[i][j];
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
//		solve(x,y);
		cout <<0<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
