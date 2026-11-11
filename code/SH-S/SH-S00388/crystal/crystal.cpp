#include<bits/stdc++.h>
using namespace std;
long long x[500010],ans,d[500010],n,m;
bool ok(int s,int e)
{
	if((long long)(e-s)*x[e]+d[s-1]-d[e-1]<=m) return true;
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int s;
	scanf("%lld%lld",&n,&m);
	s=n+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
		d[i]=d[i-1]+x[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i]*i-d[i]<=m)
		{
			ans=i;
		}
		else
		{
			s=i;
			break;
		}
	}
	for(int i=s+1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(ok(mid,i))
			{
				ans=max(ans,(long long)i-mid+1);
				r=mid-1;
			}
			else if(ok(mid+1,i))
			{
				ans=max(ans,(long long)i-mid);
				l=mid+2;
			}
			else l=mid+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
