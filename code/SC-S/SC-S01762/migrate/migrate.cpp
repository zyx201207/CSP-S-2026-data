#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
int c,t,n;
ll a[N],d,f[N],g[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		if(n>5000)
		{
			ll ans=0;
			ll c=a[2]-a[1];
			if(d/c<=1)
			{
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n-1;i++)
			{
				ll k=d/c;k=2*k-1;
				if(i+k-1<=n-1) ans++;
			}
			printf("%lld\n",ans);
			continue;
		}
		ll ans=0;
		for(int h=1;h<=n;h++)
		{
			int j=h;
			for(int i=0;i<=n;i++) f[i]=1e9,g[i]=0;
			f[h]=0;g[h]=1;
			for(int i=h+1;i<=n;i++)
			{
				while(a[i]-a[j]>d) j++;
				f[i]=f[j]+1;
				int c=g[j];
				if(j+1<i&&f[j]==f[j+1]) c+=g[j+1];
				if(j+2<i&&f[j]==f[j+2]) c+=g[j+2];
				g[i]=min(c,3);
				ans+=(g[i]==2);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}