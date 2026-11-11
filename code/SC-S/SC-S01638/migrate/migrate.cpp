#include<cstdio>
#include<algorithm>
using namespace std;
int c=1000001;
int a[10001];
int x=1;
int sum[10001];
void f1(int u,int v,int d)
{
	int p=0,ans=0;
	for(int i=u;i<=v-1;++i)
	{
		ans=a[i+1]-a[i];
	    p+=ans*i;
        if(p>d)
        {
        	sum[x]++;
            p=0;
            u=i-1;
		}
	}
//	printf("%d",sum);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	for(int i=1;i<=t;++i)
	{
		int n,d;
		scanf("%d %d",&n,&d);
	    for(int i=1;i<=n;++i)
	    {
	    	scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				f1(i,j,d);
				x++;
			}
		}
	}
	for(int i=1;i<=t;++i)
	{
		printf("%d\n",sum[i]);
	}
	return 0;
}