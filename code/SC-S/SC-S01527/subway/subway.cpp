#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2e5+20;
int c,n,m,d,q,k[N],a[N],t[N],ss[N],es[N];
long long w[N],ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	 scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		 scanf("%d%d",&a[j],&t[j]);
	}
	for(int i=1;i<=q;i++)
	 scanf("%d%d",&ss[i],&es[i]);
	for(int i=1;i<=m;i++)
	 ans+=w[i];
	for(int i=q;i>=1;i++)
	printf("%d\n",ans*i*(ss[i]*es[i])/2);
	return 0;
}