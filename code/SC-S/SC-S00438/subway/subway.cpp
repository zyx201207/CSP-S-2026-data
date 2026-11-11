#include<bits/stdc++.h>
#define int long long
#define ex exit(0)
#define sinzo return
#define code 0
using namespace std;
const int N=2e6+10;
int a[N],b[N][25],bb[N][25],c[N];
int sz[510][510];
int n,m,k,ans,cnt,sum,mx=-1e18,mn=1e18;
void Fluoyide()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(sz[i][k]+sz[k][j]<sz[i][j])
				{
					sz[i][j]=sz[i][k]+sz[k][j];
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<sz[i][j]<<' ';
//		}
//		cout<<endl;
//	}
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T,Q,d;
	cin>>T>>n>>m>>d>>Q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sz[i][j]=1e16;
		}
		sz[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		
		while(x--)
		{
			int u,l;
			cin>>u>>l;
			for(int j=1;j<=c[u];j++)
			{
				sz[i][b[u][j]]=sz[b[u][j]][i]=min(sz[b[u][j]][i],l+bb[u][j]);
			}
			c[u]++;
			b[u][c[u]]=i;
			bb[u][c[u]]=l;
			
		}
	}
	Fluoyide();
//	ex;
	while(Q--)
	{
		int u,v;
		cin>>u>>v;
		ans=1e18;
		
		for(int i=1;i<=c[u];i++)
		{
			for(int j=1;j<=c[v];j++)
			{
				ans=min(ans,sz[b[u][i]][b[v][j]]+bb[u][i]+bb[v][j]);
			}
		}
		ans+=a[u]+a[v];
		cout<<ans<<endl;
	}
	sinzo code;
}
/*

道爷，我成啦！！！！！！
爷，我成啦！！！！！！道
，我成啦！！！！！！道爷
我成啦！！！！！！道爷，
成啦！！！！！！道爷，我
啦！！！！！！道爷，我成
！！！！！！道爷我 成啦!
！！！！！道爷我 成啦！!
！！！！道爷我 成啦！！!
！！！道爷我 成啦！！！!
！！道爷我 成啦！！！！!
！道，我 成啦！！！！！!

luogu 873466

sinzo才是对的，赞美伟大的sinzo之神！！！



*/