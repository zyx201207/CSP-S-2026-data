#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N],lst[N],ans[N],res[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i),lst[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			res[j]=0;
		for(int j=i;j<=n;j=lst[a[j]]+1)
			res[a[j]]=1;
		for(int j=1;j<=m;j++)
			ans[j]+=res[j];
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",ans[i]);
	return 0;
}
