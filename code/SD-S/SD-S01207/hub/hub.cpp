#include<bits/stdc++.h>
#define int long long
#define endl '\n'
//#define p(x) cerr<<"debug:"<<__LINE__<<" "<<#x<<"="<<x<<endl;
using namespace std;
/*====================*/
const int N=1e6+10;
const int INF=1e18;
/*====================*/
int n,k,ans=INF;
vector<int>e[N];
int f[N],fa[N],dep[N];
int chos[N];
bool vis[N];
int dis[N],is_chos[N];
/*====================*/
void init()
{
	for(int i=1;i<=n;i++)f[i]=i,e[i].clear();
	ans=INF;
	fa[1]=0;
	dep[0]=0;
}
void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;
	for(auto idx:e[x])
	{
		if(idx==fa[x])continue;
		fa[idx]=x;
		dfs(idx);
	}
}
void dfs2(int x)
{
	for(auto idx:e[x])
	{
		if(vis[idx]||is_chos[idx]==0)continue;
		vis[idx]=1;
		dfs2(idx);
	}
}
void dfs1(int step,int tot)
{
//	p(step);
//	p(tot);
	if(step==n+1||tot==k)
	{
		if(tot<k)return;
		int sum=0;
		queue<int>q;
		for(int i=1;i<=n;i++)dis[i]=INF;
		for(int i=1;i<=k;i++)vis[chos[i]]=0,dis[chos[i]]=0;
		vis[chos[1]]=1;
		dfs2(chos[1]);
		for(int i=1;i<=k;i++)
		{
			if(!vis[chos[i]])
			{
				vis[chos[i]]=1;
				dfs2(i);
				break;
			}
		}
		bool flag=1;
		for(int i=1;i<=k;i++)
		{
			q.push(chos[i]); 
			if(!vis[chos[i]])
			{
				flag=0;
				break;
			}
		}
		if(!flag)return;
//		for(int i=1;i<=n;i++)
//		{
//			p(i);
//			p(dis[i]);
//		}
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=0;
			for(auto idx:e[x])
			{
				if(dis[idx]>dis[x]+1)
				{
					dis[idx]=dis[x]+1;
					if(!vis[idx])q.push(idx);
					vis[idx]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)sum=max(sum,dis[i]);
		ans=min(ans,sum);
	}
	for(int i=step;i<=n;i++)
	{
		is_chos[i]=1;
		chos[tot+1]=i;
		dfs1(i+1,tot+1);
		is_chos[i]=0;
	}
}
/*====================*/
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c,t;
	cin>>c>>t;
	while(t--) 
	{
		cin>>n>>k;
		init();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		dfs1(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

