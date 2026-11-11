#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define MAXN 1000005
#define MAXX pow(10,18)
using namespace std;
long long x[MAXN];
void Spa(long long d,long long f,long long n)
{
	long long cnt=d/f;
	if(cnt<2) printf("0\n");
	else
	{
		long long k=2*cnt-1,p=0;
		printf("%lld\n",max(p,n-k));
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	for(int _=0;_<t;_++)
	{
		long long n,d,f;
		long long maxx=MAXX,minx=-MAXX;
		memset(x,0,sizeof(x));
		bool A=true;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
			if(i==2) f=x[i]-x[i-1];
			else if(i>2)
			{
				if(f!=x[i]-x[i-1])
					A=false;
			}
		}
		if(n<=3)
		{
			printf("0\n");
			continue;
		}
		if(A)
		{
			Spa(min(d,maxx-minx),f,n);
			continue;
		}
		
	}
	return 0;
}
