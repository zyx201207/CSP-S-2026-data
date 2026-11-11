#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
bool vis[200010];
int ans=-2e9;
int c[200010];
void dfs(int pos,int sum)
{
	if(pos==m)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(pos==0)
		{
			vis[i]=true;
			c[pos]=a[i];
			dfs(1,a[i]);
			vis[i]=false;
		}
		else 
		{
			if(vis[i])continue;
			vis[i]=true;
			c[pos]=a[i];
			dfs(pos+1,sum&a[i]);
			vis[i]=false;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	memset(vis,0,sizeof(vis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==n+1)
	{
		int sum=-1;
		for(int j=1;j<=n;j++)
		{
			if(sum==-1)sum=a[j];
			else sum=sum&a[j];
		}
		int anss=-2e9;
		int cur;
		for(int i=1;i<=n;i++)
		{
			cur=sum%a[i];
			anss=max(anss,cur);
		}
		printf("%d",anss);
		return 0;
	}
	dfs(0,0);
	printf("%d",ans);
	return 0;
}