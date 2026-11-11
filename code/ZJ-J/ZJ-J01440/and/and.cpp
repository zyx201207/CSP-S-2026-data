#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200002];
long long ans;
void dfs(int cur,int cnt,long long sum)
{
	if(n-cur+1<m-cnt)return ;
	if(cnt==m)
	{
		ans=max(ans,sum);
		return ;
	}
	if(sum!=0)
	{
		dfs(cur+1,cnt+1,sum&a[cur]);
	}
	else
	{
		dfs(cur+1,cnt+1,a[cur]);
	}
	dfs(cur+1,cnt,sum);
	return ;
}   
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];          
	dfs(1,0,0LL);
	cout<<ans;
	return 0;
}