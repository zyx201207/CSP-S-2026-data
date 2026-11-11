#include<iostream>
#define int long long
using namespace std;
int n,m,ans,jjk;
int a[200010],dp[200010][5];
void dfs(int x,int cnt,int sum)
{
	if(jjk>=200000000)
	{
		cout<<ans;
		exit(0);
	}
	jjk++;
	if(cnt==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(x>=n)
	{
		return;
	}
	for(int i=x+1; i<=n; i++)
	{
		dfs(i,cnt,sum);
		dfs(i,cnt+1,sum&a[i]);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		dfs(i,1,a[i]);
	}
	cout<<ans;
	return 0;
} 
/*
4 2
3 15 12 12
*/
/*
5 3
31 3 1 15 7
*/
