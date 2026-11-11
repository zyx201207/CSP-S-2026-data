//SN-S00439 西安市铁一中 蒋雨曦 
#include<bits/stdc++.h>
#define ll long long 
#define maxn 2000005 
using namespace std;
ll c,T,n,d,a[maxn],f[maxn],g[maxn],sum[maxn],sum2[maxn],vis[maxn],vis2[maxn],val[maxn],val2[maxn];
ll dfs(ll x)
{
	if(!x||g[f[x]]^x) return 0;
	if(vis[x]) return val[x];
	vis[x]=1; val[x]=sum2[x]+dfs(f[x]);
	return val[x];
}
ll dfs2(ll x)
{
	if(!x||f[g[x]]^x) return 0;
	if(vis2[x]) return val2[x];
	vis2[x]=1; val2[x]=sum[x]+dfs2(g[x]);
	return val2[x];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("migrate.in","r",stdin); freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d; for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum2[i]=vis[i]=vis2[i]=val[i]=val2[i]=0;
		f[n+1]=g[n+1]=0;
		for(int i=1;i<=n;i++)
		{
			ll l=i+1,r=n; f[i]=0;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(a[mid]-a[i]<=d) f[i]=mid,l=mid+1;
				else r=mid-1;
			}
			sum[f[i]]++;
		}
		for(int i=n;i>=1;i--)
		{
			ll l=1,r=i-1; g[i]=0;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				if(a[i]-a[mid]<=d) g[i]=mid,r=mid-1;
				else l=mid+1;
			}
			sum2[g[i]]++;
		}
		ll ans=0;
		for(int i=1;i<n;i++)
		{
			ll num1=sum2[i]-(g[i+1]==i),num2=sum[i+1]-(f[i]==i+1);
			ll x=i+1;
			if(g[f[x]]==i)
			{
				x=f[x]; num1+=dfs(x);
			}
			x=i;
			if(f[g[x]]==i+1)
			{
				x=g[x]; num2+=dfs2(x);
			}
			ans+=num1*num2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
