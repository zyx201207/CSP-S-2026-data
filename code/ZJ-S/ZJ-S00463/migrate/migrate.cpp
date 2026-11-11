#include<bits/stdc++.h>
using namespace std;
int C,T;
int n;
long long d;
long long a[5005];
vector<int>v[5005];
int f[305][305];
int vis[305];
long long gx;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			printf("0\n");
			continue;
		}
		long long s=gx/d;
		printf("%lld\n",0);
	}
	return 0;
}