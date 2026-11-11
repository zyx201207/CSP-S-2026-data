#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],n,m,ans;
void dfs(int step,int anss,int num)
{
	if(num==m)
	{
		ans=max(ans,anss);
		return;
	}
	if(step==n+1)return;
	dfs(step+1,anss&a[step],num+1);
	if(num+n-step>=m)dfs(step+1,anss,num);
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	dfs(1,2147483647,0);
	cout << ans;
	return 0;
}
