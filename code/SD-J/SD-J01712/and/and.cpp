#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,ans;
int a[N],vis[N];
void dfs(int k,int num)
{
	if(k>m)
	{
		ans=max(ans,num);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])	continue;
		vis[i]=1;
		int res=num&a[i];
		dfs(k+1,res);
		vis[i]=0;
	}
	return ;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		int cnt=a[1];
		for(int i=2;i<=n;i++)
			cnt=cnt&a[i];
		cout<<cnt;
		return 0;
	}
	if(n>=2000)
	{
		sort(a+1,a+n+1);
		cout<<a[m];
		return 0;
	}
	int p=pow(2,31);
	ans=-1;
	dfs(1,p-1);
	cout<<ans;
	return 0;
}

