#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,a[N],num=1;
bool vis[N];
int dfs(int step,int ans)
{
	if(step==m) return ans;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) continue;
		vis[i]=1;
		dfs(step+1,ans&a[i]);
		vis[i]=0;
	}
}
bool ok(int n)
{
	int t=num;
	while(t>0)
	{
		if(t>n) t/=2;
		else 
		{
			if(t==n) return 1;
			return 0;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=30;i++) num*=2;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1) cout<<a[n];
	else if(m==n)
	{	
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}
	else
	{
		int ans=num-1;bool f=1;
		for(int i=n,j=1;j<=m;i--,j++)
		{
			ans&=a[i];
			if(!ok[a[i]]) f=0;
		}
		if(f) cout<<ans; 
		else cout<<max(ans,dfs(0,0));
	}
	return 0;
}