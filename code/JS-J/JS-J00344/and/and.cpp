#include<bits/stdc++.h>
using namespace std;
long long a[200010],mx=0;
int n,m,vis[200010];
void dfs(int x,long long ans)
{
	if(x==m)
		mx=max(ans,mx);
	if(ans<mx)
		return ;
	for(int i=1;i<=n;i++)
		if(vis[i]==0)
		{
			vis[i]=1;
			dfs(x+1,ans&a[i]);
			vis[i]=0;
		}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	long long ans=1;
	for(int i=1;i<=30;i++)
		ans*=2;
	dfs(0,ans-1);
	cout<<mx;
	return 0;
}
