#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m;
ll a[N];
int ans;
ll f[N];
void dfs(int cnt,int pos)
{
	if (pos==n+1)
	{
		if (cnt==m)
		{
			int sum=f[1];
			for (int i=2;i<=m;i++)
				sum=(sum&f[i]);
			ans=max(ans,sum);
			return;
		}
		return;
	}
	dfs(cnt,pos+1);
	f[cnt+1]=a[pos];
	dfs(cnt+1,pos+1);
	f[cnt+1]=0;
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if (n>20)
	{
		ll ans=a[n];
		for (int i=n-1;i>=n-m+1;i--)
			ans=(ans & a[i]);
		cout<<ans;
	}
	else
	{
		dfs(0,1);
		cout<<ans;
	}
	return 0;
}
//Trick||Treat!
