#include<bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
const ll N=2e6+1010;
using namespace std;
ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
ll n,t,c,d,a[N],r[N],sum[N],ans,l[N],rs;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--) 
	{
		n=read();d=read();
		for(ll i=1;i<=n;i++) a[i]=read();
		ll p=0;
		for(ll i=1;i<=n;i++)
		{
			while(p<n&&a[p+1]-a[i]<=d) p++;
			r[i]=p;
		}
		if(c==11||c==12)
		{
			if(r[1]<3) cout<<0<<"\n";
			else cout<<max(0ll,n-1-(r[1]-2)*2)<<"\n";
		}
		else
		{
			if(c==13||c==14)
			{
				cout<<"0\n";
				continue;
			}
			p=1;
			for(ll i=1;i<=n;i++)
			{
				while(a[i]-a[p]>d&&p<=i) p++;
				l[i]=p;
			}
			ans=0;
			for(ll i=1;i<=n;i++)
			{
				rs=i;
				sum[i]=1;
				sum[i-1]=0;
				ll j=rs+1;
				while(r[rs]!=rs)
				{
					for(ll k=j;k<=r[rs];k++)
					{
						sum[k]=sum[k-1]+(sum[rs]-sum[max(i-1,l[k]-1)]);
						if(sum[rs]-sum[max(i-1,l[k]-1)]==2) ans++;
					}
					j=r[rs]+1;
					rs=r[rs];
				}
			}
			cout<<ans<<"\n";
		}	
	}
	return 0;
}