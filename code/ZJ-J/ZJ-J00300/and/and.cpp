#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAXN 200005
#define MAXH pow(2,30)-1
using namespace std;
int a[MAXN];
int las[35][MAXN];
int q[35];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	long long ans=MAXH;
	for(int i=1;i<=n;i++)
	{
		int p=a[i];
		int lg=log2(p);
		while(p!=0)
		{
			int k=pow(2,lg);
			if(p>=k)
			{
				p-=k;
				q[lg]++;
				las[lg][q[lg]]=a[i];
				if(q[lg]==m)
				{
					for(int j=1;j<=m;j++)
					{
						ans=ans&las[lg][j];
					}
					printf("%lld",ans);
					return 0;
				}
			}
			lg--;
		}
	}
	printf("0");
	return 0;
}
