#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,s[200005],maxn,k,sum;
void dfs(int s,int q,int l)
{
	if(s<maxn)return;
	if(q==k)
	{
		maxn=s;
		return;
	}
	for(int i=l+1;i<=n;i++)
		dfs(s&a[i],q+1,i);
	return;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);sum&=a[i];
	}
	if(n==k)
	{
		printf("%d",sum);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(a[i],1,i);
	}
	printf("%d",maxn);
	return 0;
}
