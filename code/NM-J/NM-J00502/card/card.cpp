#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],f[300010],t[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int j=0;
		for(int k=i;k<=n;k++)
		{
			int b=0;
			for(int l=1;l<=j;l++)
			{
				if(f[l]==a[k])
				{
					j=l;
					b=1;
					break;
				}
			}
			if(!b)f[++j]=a[k];
		}
		for(int k=1;k<=j;k++)t[f[k]]++;
	}
	for(int i=1;i<=m;i++)printf("%lld ",t[i]);
	printf("\n");
	return 0;
}