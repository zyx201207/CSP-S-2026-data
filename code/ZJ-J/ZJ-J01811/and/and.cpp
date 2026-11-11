#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],ans=-1;
bool b[200010];
void dfs(ll t,ll sum)
{
	if(t==m)
	{
		ans=max(ans,sum);
		return;
	}
	if(sum<=ans)return;
	if(t==0)
	{
		for(ll i=1;i<=n;i++)
		{
			b[i]=1;
			dfs(1,a[i]);
		}
	}
	else
	{
		for(ll i=1;i<=n;i++)
		{
			if(b[i])continue;
			b[i]=1;
			dfs(t+1,a[i]&sum);
			b[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];	
	sort(a+1,a+n+1,greater<ll>());	
	dfs(0,0);
	cout<<ans<<'\n';
	return 0;
}
//#include<bits/stdc++.h>
//#define ll long long
//using namespace std;
//ll n,m,a[200010];
//int main()
//{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	cin>>n>>m;
//	for(ll i=1;i<=n;i++)cin>>a[i];	
//	sort(a+1,a+n+1,greater<ll>());	
//	ll ans=a[1];
//	for(ll i=2;i<=m;i++)ans&=a[i];
//	cout<<ans<<'\n';
//	return 0;
//}

