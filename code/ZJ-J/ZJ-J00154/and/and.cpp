#include<bits/stdc++.h>
using namespace std;
using uni = unsigned int;
const uni N=2e5+7;
uni n,ans,a[N],m;
bool vis[N];
void dfs(uni k,uni o)
{
	if(k==m)
	{
		ans=max(ans,o);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			dfs(k+1,o&a[i]);
			vis[i]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int u=1;
	u<<=30;
	u-=1;
	dfs(0,u);
	cout<<ans;
 	return 0;
}
