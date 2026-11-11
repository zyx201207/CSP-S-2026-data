#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
const long long N=1e5+5;
int minn,x,y,z,ans=1;
long long a[N],b[N],ha,n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ha+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		y=(ha+m)/n;
	    if(a[i]>y)
	    {
	    	b[i]=a[i]-y;
		}
		else 
		{
			b[i]=y-a[i];
		}
		if(i>1)
		{
			if(b[i]<b[i-1])
			{
				minn=b[i];
				x=i;	
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[x])ans++;
		else
		{
			if(a[i]<a[x])
			{
				z=a[x]-a[i];
				m-=z;
				if(m<0)break;
				ans++;
				z=0;
				if(m==0)break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
