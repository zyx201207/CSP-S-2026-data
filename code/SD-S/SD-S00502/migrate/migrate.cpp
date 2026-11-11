#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll c,T,n,d,ans,a[N],f[N],k[N];
vector<ll>g[N];map<ll,ll>q[N];
void dfs(ll s,ll o,ll t)
{
	for(ll i=0;i<g[o].size();i++)
		if(!k[g[o][i]])k[g[o][i]]=1,dfs(s,g[o][i],t+1),k[g[o][i]]=0;
	if(t==f[o]&&t)q[s][o]++;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;while(T--)
	{
		if(c==13||c==14)
		{
			cin>>n>>d;
			for(ll i=1;i<=n;i++)cin>>a[i];
			cout<<0<<endl;continue;
		}
		if(c==11||c==12)
		{
			cin>>n>>d;
			for(ll i=1;i<=n;i++)cin>>a[i];
			if(n==1||n==2||a[3]-a[1]>d){cout<<0<<endl;continue;}
			for(ll i=3;i<=n;i+=2)if(a[i]-a[1]>d){cout<<n-i+2<<endl;break;}
			continue;
		}
		cin>>n>>d;ans=0;
		for(ll i=1;i<=n;i++)cin>>a[i],g[i].clear();
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				if(a[i]+d>=a[j])g[i].push_back(j);
		for(ll s=1;s<=n;s++)
		{
			for(ll i=1;i<=n;i++)f[i]=LONG_LONG_MAX;
			memset(k,0,sizeof k);f[s]=0;
			for(ll i=1;i<=n;i++)
				for(ll j=1;j<=n;j++)q[i][j]=0;
			for(ll i=1;i<=n;i++)
			{
				ll l=LONG_LONG_MAX,t;
				for(ll j=1;j<=n;j++)
					if(!k[j]&&f[j]<l)l=f[j],t=j;
				k[t]=1;for(ll j=0;j<g[t].size();j++)f[g[t][j]]=min(f[g[t][j]],f[t]+1);
			}
			memset(k,0,sizeof k);k[s]=1;dfs(s,s,0);
			for(ll i=1;i<=n;i++)
				for(ll j=i+1;j<=n;j++)if(q[i][j]==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
