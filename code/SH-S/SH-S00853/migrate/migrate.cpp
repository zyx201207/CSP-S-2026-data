#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long arr[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int i,c,t,n;
	unsigned long long D;
	long long d,jp;
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%d %ull",&n,&D);
		for(i=1;i<=n;++i)
		{
			scanf("%lld",&arr[i]);
		}
		d=arr[3]-arr[2];
		jp=D/d;
		printf("%lld\n",n-jp*2+1);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
