#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m,n,a[N],vis[N],ans=-1;
void dfs(int x,int y,int u)
{
	if(x>m)
	{
		ans=max(ans,u);
		return ;
	}
	if(y>n)
	return ;
	for(int i=y;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(x+1,i+1,u&a[i]);
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dfs(2,i+1,a[i]);
		vis[i]=0;
	}
	printf("%d",ans);
	return 0;
}
