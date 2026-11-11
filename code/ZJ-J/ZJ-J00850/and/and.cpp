#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[201010];
int ans=-1;
bool vis[201010];
void dfs(int res,int x)
{
	if(x==m)
	{
		ans=max(ans,res);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(res&a[i],x+1);
			vis[i]=0;
		}
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		int sum=(1<<31)-1;
		for(int i=1;i<=n;i++)
		{
			sum=sum&a[i];
		}
		cout<<sum;
	}
	else
	{
		dfs((1<<31)-1,0);
		cout<<ans;
	}
	return 0;
}