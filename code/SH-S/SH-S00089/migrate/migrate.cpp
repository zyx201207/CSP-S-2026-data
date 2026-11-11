#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C,T,n,m,k,flag,ans;
ll a[2000005];
ll f[2000005];
ll l[2000005];
ll r[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	for(ll I=1;I<=T;I++)
	{
		scanf("%lld%lld",&n,&m);
		for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
		ans=0;k=1;
		for(ll i=1;i<=n;i++)
		{
			r[i]=r[i-1];
			for(;;k++)
			{
				if(a[k]-a[i]<=m)r[i]=k;
				else break;
				if(k==n)break;
			}
		}
		k=n;
		for(ll i=n;i>=1;i--)
		{
			l[i]=l[i+1];
			for(;;k--)
			{
				if(a[i]-a[k]<=m)l[i]=k;
				else break;
				if(k==1)break;
			}
		}
		for(ll i=1;i<=n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				f[1]=i;flag=0;
				for(k=2;;k++)
				{
					if(r[f[k-1]]<j)f[k]=r[f[k-1]];
					else {f[k]=j;break;}
					if(f[k]==f[k-1]){flag=2;break;}
				}
				for(int i=2;i<k;i++)
				{
					if(flag>=2)break;
					flag+=f[i]-l[f[i+1]];
				}
				if(flag==1)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
