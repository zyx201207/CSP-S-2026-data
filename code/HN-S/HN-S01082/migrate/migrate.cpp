#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,d,n,t;
int x[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;++i)
			scanf("%lld",&x[i]);
		int l=d/(x[2]-x[1]);
		if(l<=1)
			printf("0\n");
		else if(n<2*l-1)
			printf("0\n");
		else
			printf("%lld\n",n-2*l+1);
	}
	return 0;
}
