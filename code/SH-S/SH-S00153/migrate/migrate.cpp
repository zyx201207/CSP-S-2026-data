#include<bits/stdc++.h>
using namespace std;
long long X[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c,n,i;
	long long d,dif;
	scanf("%d %d",&c,&T);
	while(T--)
	{
		scanf("%d %lld",&n,&d);
		for(i=1;i<=n;++i)
			scanf("%lld",&X[i]);
		dif=X[2]-X[1];
		if(!c||c==11||c==12)
		{
			if(d>=dif*2&&d<=dif*(n-2))
				printf("%d\n",n-d/dif*2+1);
			else
				printf("0\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
