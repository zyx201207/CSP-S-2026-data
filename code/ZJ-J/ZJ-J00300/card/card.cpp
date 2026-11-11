#include<stdio.h>
#include<string.h>
#define MAXN 500005
using namespace std;
int a[MAXN],las[MAXN-200000];
int nowa[MAXN-200000];
int ans[MAXN-200000];
bool A=true;
int n,m;
void Spa()
{
	for(int i=1;i<=m;i++)
		printf("%d ",las[i]);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) A=false;
		if(a[i]!=a[i-1]) las[a[i-1]]=i-1;
	}
	las[a[n]]=n;
	if(A) Spa();
	else if(m==1) printf("%d",n);
	else if(m==2)
	{
		int ans1=0,ans2=0;
		if(a[n]==1)
		{
			ans1=n;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==2) ans2++;
			}
		}
		else
		{
			ans2=n;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans1++;
			}
		}
		printf("%d %d",ans1,ans2);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			memset(nowa,0,sizeof(nowa));
			for(int j=i;j<=n;j++)
			{
				if(nowa[a[j]]==0)
				{
					nowa[a[j]]=j;
				}
				else
				{
					for(int k=nowa[a[j]];k<j;k++)
					{
						nowa[a[k]]=0;
					}
					nowa[a[j]]=j;
				}
			}
			for(int j=1;j<=m;j++)
			{
				if(nowa[j]) ans[j]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
