#include<bits/stdc++.h>
using namespace std;
long long x[2000010],dd[2000010],n,d,ans,fi,minn[2000010];
bool vis[2000010];
void dfs(int cnt,int dis)
{ 
	for(int i=cnt+1;x[i]-x[cnt]<=d && i<=n;i++)
	{
		if(dis+1<minn[i])
		{
			minn[i]=dis+1;
			dd[i]=1;
			vis[i]=0;
		}
		else if(dis+1==minn[i] && cnt!=fi)
		{
			dd[i]++;
			if(dd[i]==2) vis[i]=1;
			if(dd[i]>2) vis[i]=0;
		}
		dfs(i,dis+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		memset(x,0,sizeof(x));
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n-3;i++)
		{
			memset(dd,0,sizeof(dd));
			memset(vis,0,sizeof(vis));
			memset(minn,0x3f,sizeof(minn));
			fi=i;
			dfs(i,1);
			for(int j=i+3;j<=n;j++) if(vis[j]) ans++;
		}
		cout<<ans<<endl;
	} 
	return 0;
}
