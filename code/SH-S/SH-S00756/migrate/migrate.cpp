#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e6+5;
int c,t,n,d,x[M];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12)while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(n==1)printf("0\n");
		else if(d<2*(x[2]-x[1]))printf("0\n");
		else printf("%lld\n",max(0ll,n-d/(x[2]-x[1])*2+1));
	}
	return 0;
}
