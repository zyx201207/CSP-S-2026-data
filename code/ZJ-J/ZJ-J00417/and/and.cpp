#include <bits/stdc++.h>
using namespace std;
long long a[200010];
long long ma=-2e9,n,m;
void dfs(long long l,long long x,long long ans)
{
	if(l==m)
	{
		ma=max(ma,ans);
		return ;
	}
	for(long long j=x+1;j<=n;j++)
	{
		long long t=a[j] & ans;
		dfs(l+1,j,t);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++) dfs(1,i,a[i]);
	cout<<ma;
	return 0;
}
