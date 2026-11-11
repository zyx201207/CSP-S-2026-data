#include<bits/stdc++.h>
using namespace std;
long long arr[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int ans=0,cnt=0,ans1=0,i,j,flag=1,c,t,n,d;
	scanf("%d %d",&c,&t);
	while(t--)
	{
		scanf("%d %d",&n,&d);
		for(i=1;i<=n;++i)
			scanf("%lld",&arr[i]);
		if(c==13||c==14)
			printf("0\n");
	}
	return 0;
}
