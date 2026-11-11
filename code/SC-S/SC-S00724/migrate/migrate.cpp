#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
const long long N=(2*1e6)+5;
long long n,d,c,t,x[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&d);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x[j]);	
			if(x[j]<=d)
	{
		printf("%d/n%d/n",1,2);
	}
		}
	}
	
	return 0;
}
