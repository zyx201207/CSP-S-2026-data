#include<bits/stdc++.h>
using namespace std;
long long arr[2000004];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C,T,n,i,u,v;
	long long d,t,t1;
	scanf("%d %d",&C,&T);
	while(T--)
	{
		scanf("%d %lld",&n,&d);
		for(i=1;i<=n;++i)
			scanf("%lld",&arr[i]);
		if(C==13||C==14||2*d>=arr[n]-arr[1]+1)
		{
			if(2*d>arr[n]-arr[1]+1)
				printf("0\n");
			else if(2*d==arr[n]-arr[1]+1)
				printf("1\n");
			else if(2*d<arr[n]-arr[1]+1)
				printf("2\n");
		}
		else if(C==11||C==12||C==0)
		{
			t=arr[2]-arr[1];
			t1=d/t;
			printf("%lld\n",n-2*t1+1);
		}
		else
			printf("1\n");
	}
	fclose(stdin);
	fclose(stdout);
}
