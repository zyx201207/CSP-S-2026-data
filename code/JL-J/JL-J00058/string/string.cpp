#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long lcnt=0,rcnt=0,ans=0,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&c[i]);
		sum+=a[i];
	}
	int i=0,j=n+1;
	while(lcnt+rcnt!=sum)
	{
		while(lcnt<=rcnt)
		{
			i++;
			if(lcnt+a[i]<=rcnt)
			{
				if(c[i]!=c[j])
					ans+=a[i];
			}
			else
			{
				if(c[i]!=c[j])
					ans+=rcnt-lcnt;
			}
			lcnt+=a[i];
			if(lcnt+rcnt==sum)
				break;
		}
		if(lcnt+rcnt==sum)
			break;
		while(rcnt<=lcnt)
		{
			j--;
			if(rcnt+a[j]<=lcnt)
			{
				if(c[i]!=c[j])
					ans+=a[j];
			}
			else
			{
				if(c[i]!=c[j])
					ans+=lcnt-rcnt;
			}
			rcnt+=a[j];
			if(lcnt+rcnt==sum)
				break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}