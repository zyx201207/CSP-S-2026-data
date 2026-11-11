#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const lint M1=3e5+1000,M2=1e3+100;
lint n,m;
lint a[M1],b[M1];
bool f[M1];
lint st[M1],sh;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(lint i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n<=10000)
	{
		for(lint i=1;i<=n;i++)
		{
			for(lint j=1;j<=m;j++) f[j]=0;
			for(lint j=i;j<=n;j++)
			{
				if(f[a[j]])
				{
					while(a[st[sh]]!=a[j]&&sh!=0)
					{
						f[a[st[sh]]]=0;
						sh--;
					}
				}
				else
				{
					st[++sh]=j;
					f[a[j]]=1;	
				}
			}
			for(lint j=1;j<=m;j++)
			{
				if(f[j]) b[j]++;
			}
		}
		for(lint i=1;i<=m;i++) printf("%lld ",b[i]);
	}
	else
	{
		for(lint i=1;i<=m;i++) printf("%lld ",i);
	}
	return 0;
}
