#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+9;
int a[N];
int vis[N];
int maxx=-1;
int n,m;
void dfs(int cnt,int ans)
{
	if(cnt==m)
	{
		maxx=max(maxx,ans);
//		cout<<ans<<" ";
		return;
	}
	for(int i=1;i <= n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			int x=ans&a[i];
			dfs(cnt+1,x);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n>2000&&m!=n-1)
	{
		for(int i=1;i <= n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	for(int i=1;i <= n;i++) cin >> a[i];
	for(int i=1;i <= n;i++)
	{
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<maxx;
	return 0;
}

