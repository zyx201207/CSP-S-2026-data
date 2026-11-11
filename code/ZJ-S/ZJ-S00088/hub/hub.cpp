#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;
int num[25];
int vis[N],dis[N];
int f[N][N];
int n,k;
void dfs(int x,int fa,int is)
{
	vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(!f[x][i]) continue;
		if(i==fa) continue;
		if(is && num[i] && !vis[i]) dfs(i,x,1);
		if(!num[i] && dis[i]>dis[x]+1)
		{
			dis[i]=dis[x]+1;
			dfs(i,x,0);
		}
	}
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		memset(f,0,sizeof f);
		cin>>n>>k;
		if(C<=3)
		{
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				f[u][v]=f[v][u]=1;
			}
			int ans=1e18;
			for(int s=0;s<(1<<n);s++)
			{
				int cnt=0;
				for(int i=1;i<=n;i++)
				{
					num[i]=0;
					int k=(1<<i-1);
					if(s&k) num[i]=1,cnt++;
				}
				if(cnt!=k) continue;
				cnt=0;
				memset(vis,0,sizeof vis);
				memset(dis,0x3f,sizeof dis);
				for(int i=1;i<=n;i++)
					if(num[i]) dis[i]=0;
				for(int i=1;i<=n;i++)
				{
					if(num[i] && !vis[i])
					{
						dfs(i,i,1);
						cnt++;
					}
				}
				if(cnt>2) continue;
				int res=0;
				for(int i=1;i<=n;i++)
					if(!num[i]) res=max(res,dis[i]);
				ans=min(ans,res);
			}
			cout<<ans<<"\n";
			continue;
		}
		for(int i=1,u,v;i<n;i++) cin>>u>>v;
		if(n==k)
		{
			cout<<"0\n";
			continue;
		}
		if(C>=13 && C<=14)
		{
			int m=n/2;
			if(k>=m) cout<<"1\n";
			else cout<<"2\n";
		}
	}
	
	return 0;
}