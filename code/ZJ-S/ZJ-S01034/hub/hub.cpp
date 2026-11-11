//- What do you want more than a happy ending? -
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1010;
int c,t;
int n,k;
vector<int>mp[N];
int dis[N][N];
int maxx[N];
int vis[N];
int minn=1e18;
int ans=1e18;
int qaq;
int awa[N];
void qwq(int x,int step,int size)
{
	if(step>=size)
	{
		memset(maxx,0,sizeof(maxx));
		qaq=0;
		for(int i=1;i<=n;i++)
		{
			if(vis[i])
			{
				continue;
			}
			for(int j=1;j<=size;j++)
			{
				maxx[i]=max(maxx[i],dis[i][awa[j]]);
			}
			qaq+=maxx[i];
//			max2=max(max2,maxx[i]);
//			cout<<maxx[i]<<' ';
		}
		minn=min(minn,qaq);
//		cout<<"\n";
		return;
	}
	for(auto it:mp[x])
	{
		if(vis[it]==0)
		{
			vis[it]=1;
			awa[step+1]=it;
			qwq(it,step+1,size);
			vis[it]=0;
		}
	}
}
void solve()
{
	ans=1e18;
	cin>>n>>k;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		mp[u].push_back(v);
		mp[v].push_back(u);
		dis[u][v]=dis[v][u]=1;
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		qaq=0;
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		minn=1e18;
		awa[1]=i;
		qwq(i,1,k);
//		minn=min(minn,qaq);
		ans=min(minn,ans);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				for(int l=1;l<k;l++)
				{
					qaq=0;
					memset(vis,0,sizeof(vis));
					vis[i]=1;
					vis[j]=1;
					awa[1]=i;
					minn=1e18;
					qwq(i,1,l);
					int qaqaq=minn;
					awa[1]=j;
					minn=1e18;
					qwq(j,1,k-l);
					ans=min(ans,qaqaq+minn);
//					minn=min(minn,qaq);
				}
			}
		}
	}
	cout<<minn<<"\n";
//	if(k==0)
//	{
//		cout<<tot<<"\n";
//	}
//	else if(k==1)
//	{
//		cout<<tot-max2<<"\n";
//	}
//	else
//	{
//		cout<<tot-maxx[n]-maxx[n-1]<<"\n";
//	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
//648647291436
//~~Maybe~~ Not a happy ending.
//Password: Oct31==Dec25?