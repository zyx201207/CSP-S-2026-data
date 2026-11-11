#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[200005];
long long maxn=-1;
int used[200005];
void dfs(int pos)
{
	if(pos==m+1)
	{
		long long ans=a[1];
		for(int i=2;i<=m;i++)
		{
			ans=ans&a[i];
		}
		maxn=max(ans,maxn);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			a[pos]=b[i];
			dfs(pos+1);
			used[i]=0;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	dfs(1);
	printf("%lld",maxn);
	return 0;
}
