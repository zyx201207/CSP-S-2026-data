#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxt=1;
ll f[500005],c[500005];
bool flag=0;
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&f[i]);
	sort(f+1,f+n+1);
	c[1]=f[2]-f[1];
    for(int i=2;i<n;i++)
    {
    	c[i]=f[i+1]-f[i];
    	if(c[i]!=c[1])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		int h=0;int g[500005];
		g[0]=0;
		for(int i=1;i<=n;i++)
		{
			ll ans=0;
			g[i]=g[i-1]+i;
			if(m<g[i]*c[1])
			{
	            printf("%lld",i);
	            return 0;
			}
		}
        printf("%lld",n);
        return 0;
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=n;j>=i;j--)
			{
				int h=m;bool ffff=0;
				for(ll k=i;k<=j;k++)
				{
					if(h<0)
					{
						ffff=1;
						break;
					}
					h-=(f[j]-f[k]);
				}
				if(ffff==0)maxt=max(maxt,j-i+1); 
			}
		}
	    printf("%d",maxt);
        return 0;
	}
	return 0;
} 
