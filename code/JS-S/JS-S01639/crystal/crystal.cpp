#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool flagA=true,flagB=true;
	int n,ans=0;
	long long m,a[500005],pre[500005];
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(flagA&&a[i]!=i) flagA=false;
		if(i>=3&&flagB&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flagB=false;
	}
	if(flagA)
	{
		int i;
		for(i=n;i>=1;i--)
			if(i*(i-1)<=2*m)
				break;
		printf("%d\n",i);
	}
	else if(flagB)
	{
		long long cha=a[2]-a[1];
		int i;
		for(i=n;i>=1;i--)
			if(cha*i*(i-1)<=2*m)
				break;
		printf("%d\n",i);
	}
	else
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+a[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				if((i-j+1)*a[i]-pre[i]+pre[j-1]<=m)
				{
					ans=max(ans,i-j+1);
					break;
				}
		printf("%d\n",ans);
	}
	return 0;
}
