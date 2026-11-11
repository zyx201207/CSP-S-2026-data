#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e9;
ll c,t,n,d;
ll x[2000010];
ll f[2000010]; 
ll b[2000010];
ll g[2000010];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
				f[j]=inf,b[j]=inf,g[j]=0;
			f[i]=0;
			ll p=i;
			for(int j=i+1;j<=n;j++)
			{
				while(p<=j&&x[j]-x[p]>d)
					p++;
				f[j]=f[p]+1;
				b[j]=p;
			}
			g[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				for(int k=b[j];k<=j;k++)
				{
					if(f[k]!=f[b[j]])
						break;
					g[j]+=g[k];
				}
			}
			for(int j=i;j<=n;j++)
				ans+=(g[j]==2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
