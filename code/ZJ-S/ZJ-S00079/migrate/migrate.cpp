#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	ll k=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return k*f;
}
const int N=2e6+10;
ll c,t,n,d,a[N];
int vis[N],b[N],s[N],q[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read();t=read();
	while(t--)
	{
		n=read();d=read();
		for(int i=1; i<=n; ++i)
			a[i]=read();
		ll ans=0;
		for(int l=1; l<=n; ++l)
		{
			for(int r=l+1; r<=n; ++r)
			{
				for(int i=l; i<=r; ++i)
					vis[i]=0;
				bool f=1;
				for(int i=l+1; i<=r; ++i)
				{
					if(a[i]-a[i-1]>d)
						f=0;
				}
				if(f==0)continue;
				int now=l,dis=1;
				while(now<r)
				{
					int tmp=now;
					while(now<r&&a[now+1]<=a[tmp]+d)
						now++;
					dis++;
				}
				int sum=0;
				for(int i=0; i<(1<<(r-l-1)); ++i)
				{
					int num=1;
					b[1]=l;
					for(int j=0; j<r-l-1; ++j)
					{
						if((i>>j)&1)
							b[++num]=l+j+1;
					}
					b[++num]=r;
					if(num!=dis)continue;
					bool f=1;
					for(int j=2; j<=num; ++j)
						if(b[j]-b[j-1]>d)
							f=0;
					sum+=f;
				}
				if(sum==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
