#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[200005];
void dfs(int x,int y,int z)
{
	if(y==m)
	{
		ans=max(ans,z);
		return;
	}
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,y+1,z&a[i]);
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1)
		ans=a[n];
	else if(m==n)
	{
		for(int i=2;i<=n;i++)
			a[i]&=a[i-1];
		ans=a[n];
	}
	else
	{
		dfs(0,0,(1<<30)-1);
	}
	
	cout<<ans;
}
