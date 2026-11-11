#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
ll maxx=0;
int n,m;
void dfs(ll x,ll s,ll sd)
{
	if(x==m)
	{
		maxx=max(maxx,s);
		return;
	}
	for(int i=sd;i<=n;i++)
	{
		dfs(x+1,s&a[i],i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m)
	{
		ll ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++)
	{
		dfs(1,a[i],i+1);
	}
	cout<<maxx;
	return 0;
}