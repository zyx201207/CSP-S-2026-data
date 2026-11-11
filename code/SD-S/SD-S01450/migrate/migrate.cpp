#include<bits/stdc++.h>
#define int long long 
using namespace std;
int c,t;
const int N=2e6+10;
int a[N],dis[5005][5005];
int vis[5005][5005];
int n,d;
void dfs(int fi,int x,int tot)
{
	if(tot==dis[fi][x]) 
	{
		vis[fi][x]++;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(a[x]+d>=a[i])
		{
			dfs(fi,i,tot+1);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++)
			{
				int now=a[i],cnt=0,lst=i+1;
				while(now<a[n])
				{
					now+=d,cnt++;
					if(now<a[lst]) break;
					for(int j=lst;j<=n;j++)
					{
						if(now>=a[j]) dis[i][j]=cnt;
						else 
						{
							now=a[j-1];
							lst=j;
							break;
						}
					}
				}
			}
			for(int i=1;i<=n;i++) dfs(i,i,0);
			for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(vis[i][j]==2) ans++;
			for(int i=1;i<=n;i++) a[i]=0;
			for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0,vis[i][j]=0;
			cout<<ans<<'\n';
		}
	}
	return 0;
}

