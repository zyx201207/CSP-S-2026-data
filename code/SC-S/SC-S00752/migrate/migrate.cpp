#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		int i=1;
		for(;i<=n-1;i++) if(a[1]+d>=a[i]&&a[1]+d<a[i+1]) break;
		//cout<<i<<" ";
		int tp=a[i-2]+d;
		int sum=a[i-1]+d;
		for(;i<=n-1;i++) 
		{
			if(sum>=a[i]&&sum<a[i+1]) break;
			//else cout<<a[i]<<" ";
		}
		//cout<<sum<<" ";
		if(tp<a[i])
			printf("%d\n",n-i+1);
		else printf("0\n");
	}
	return 0;
} 