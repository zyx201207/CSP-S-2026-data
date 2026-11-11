#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int b[200010];
int vis[200010];
int n,m;
int ans;
void dfs(int step)
{
	if(step>m)
	{
		int sum=b[1];
		for(int i=2;i<=m;i++)
		{
			sum=sum&b[i];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		b[step]=a[i];
		vis[i]=1;
		dfs(step+1);
		vis[i]=0;
	}
}
void solvedfs()
{
	dfs(1);
	cout<<ans<<endl;
	return;
}
void solvem1()
{
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]);
	}
	cout<<ans<<endl;
	return;
}
void solvem2()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int t=a[i]&a[j];
			ans=max(ans,t); 
		}
	}
	cout<<ans<<endl;
}
void solvemn()
{
	ans=a[1];
	for(int i=2;i<=n;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans<<endl;
	return;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		solvem1();
		return 0;
	}
	if(m==n)
	{
		solvemn();
		return 0;
	}
	if(m==2)
	{
		solvem2();
		return 0;
	}
	solvedfs();
	return 0; 
}
