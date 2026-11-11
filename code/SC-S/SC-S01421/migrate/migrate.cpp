#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000050],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
		}
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if(a[mid]-a[1]<=d)
			{
				l=mid;
			}
			else
			{
				r=mid-1;
			}
		}
		if(l<=2)
		{
			ans=0;
		}
		else
		{
			ans=n-(l-2)*2-1;
		}
		if(ans<0)
		{
			ans=0;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}