#include<bits/stdc++.h>
using namespace std;
int n,m,k[500005],a[500005],ans=0,s[500005];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)
	{
		k[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		k[i]=k[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		int c=(k[i]+m)/i;
		if(c>=a[i])
		{
			ans=i;
			break;
		}
	}
	printf("%d",ans);
	return 0;
 } 
