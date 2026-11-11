#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 2*1e6+5;
int c,t;
int n,d;
ll de,sum[N],a[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		for(int i= 1; i <=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		de=a[2]-a[1];
		bool ok=1;
		for(int i =3; i <=n;i++)
		{
			if(de!=a[i]-a[i-1])
			{
				ok = 0;
				break;
			}
		}
		int cnt = 0;
		if(ok)
		{
			if(d<2*de)
			{
				printf("%d",cnt);
				return 0;
			}
			int j = 1;
			if(d>=2*de)
			{
				if(n>=4)cnt += (n-4+1);
				if(n>=6)cnt += (n-6+1);
			}
			else if(d >=3*de)
			{
				if(n>=5)cnt+= n-5+1;
			}
			printf("%d",cnt); 
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
