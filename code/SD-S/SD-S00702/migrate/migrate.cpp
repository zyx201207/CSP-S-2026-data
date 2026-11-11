#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
const ll hare=2000006;
ll a[hare];
ll ans=0;
ll prev;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	if(c==11||c==12)
	{
		while(t--)
		{
			scanf("%lld%lld",&n,&d);
			for(ll i=1;i<=n;i++)
			  scanf("%lld",&a[i]);
			ll cha=d/(a[2]-a[1]);
			if(cha<2||n==1||n-(2ll*cha-1ll)<0) 
			{
				printf("0\n");
			}
			else printf("%lld\n",n-(2ll*cha-1ll));
		}
	}
	else
	{
		bool b=0;
		while(t--)
		{
			scanf("%lld%lld",&n,&d);
			for(ll i=1;i<=n;i++)  
			{
				scanf("%lld",&a[i]);
			}
			ans=0;
			for(ll i=1;i<=n;i++)
			{
				for(ll j=i+3;j<=n;j++)
				{
					if(a[j]-a[i]<=d) continue;
					for(ll k=i+2;k<j;k++)
					{
						if(a[k]-a[i]>d) break;
						if(a[j]-a[k]<=d&&a[j]-a[k-1]<=d&&a[k]-a[i]<=d&&a[k-1]-a[i]<=d)
						{
							if(b==0)
							{
								b=1;
								ans++;
								prev=k-1;
							}
							else
							{
								b=0;
								ans--;
								prev=0;
								break;
							}
						}
					}
					if(b==1)
					{
						b=0;
						for(int z=prev;z>=2;z--)
						{
							if(a[z]-a[z-2]>d&&a[z-1]-a[z-2]<=d) ans++;
							else break;
						}
						prev=0;
					}	
				}
			}
		    printf("%lld\n",ans);	
		}
	}
	return 0;
}

