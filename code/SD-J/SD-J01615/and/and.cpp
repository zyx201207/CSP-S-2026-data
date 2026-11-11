#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[500086];
void dfs(int i,int cnt,int sum)
{
	if(cnt>m||i>n) return ;
	else if(cnt==m)
	{
		ans=max(ans,sum&a[i]);
	}
	else
	{
		dfs(i+1,cnt+1,sum&a[i]);
		dfs(i+1,cnt,sum);
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		for(int i=1; i<=n; i++)
		{
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==n)
	{
		ans=a[1];
		for(int i=1; i<=n; i++)
		{
			ans=a[i]&ans;
		}
		cout<<ans;
		return 0;
	}
	else
	{

		dfs(1,1,INT_MAX);
		cout<<ans;
		return 0;
	}
	return 0;
}
