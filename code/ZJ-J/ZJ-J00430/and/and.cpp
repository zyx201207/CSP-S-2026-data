#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],vis[200005],maxn,f[200005];
void dfs(int step)
{
	if(step>m)
	{
		long long ans=vis[1];
			for(int i=1;i<=m;i++)
				ans=ans&vis[i];
			maxn=max(maxn,ans);
	}
	for(int i=1;i<=n;i++)
		if(f[i]==0)
			{
				f[i]=1;
				vis[step]=a[i];
				dfs(step+1);
				f[i]=0;
			}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=20)
		dfs(1);
		cout<<maxn;
	return 0;
}
