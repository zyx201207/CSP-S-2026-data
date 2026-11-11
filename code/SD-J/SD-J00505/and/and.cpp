#include <bits/stdc++.h>

using namespace std;

int n,m,ans;

bool visited[200010];

int a[200010];

void dfs(int d,int sum)
{
	if(d==m-1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
		{
			visited[i]=1;
			dfs(d+1,sum&a[i]);
			visited[i]=0;
		}
	}
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		visited[i]=1;
		dfs(0,a[i]);
		visited[i]=0;
	}
	cout<<ans<<'\n';
	return 0;
}
