#include <bits/stdc++.h>
using namespace std;
long long ans,n,a[200005],m,vis[200005];
void dfs(long long b,long long ans_lin)
{
	if(b>m)
	{
		ans=max(ans,ans_lin);
		ans_lin=1023;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]!=1)
		{
			vis[i]++;
			ans_lin=ans_lin&a[i];
			cout<<ans_lin<<" ";
			dfs(b+1,ans_lin);
			vis[i]--;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,1023);
	cout<<ans;
	return 0;
}
