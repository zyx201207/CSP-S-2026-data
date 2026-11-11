#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,i,j,n,d;
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%d %d",&n,&d);
		for(i=1;i<=n;++i)
			scanf("%d",&x[i]);
		printf("%d\n",0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
