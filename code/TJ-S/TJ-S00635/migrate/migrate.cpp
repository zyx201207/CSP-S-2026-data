#include <bits/stdc++.h>
using namespace std;
int c,t;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==11 || c==12)
	{
		while(t--)
		{
			int n;
			long long d,a[2000010];
			scanf("%d%lld",&n,&d);
			for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
			if(a[3]-a[1]>d) {
				printf("0\n");
				continue;
			}
			int i=3;
			while(a[i]-a[1]<=d) i++;
			printf("%d\n",max(0,n-2*(i-2)-1));
		}
	}
	return 0;
}
