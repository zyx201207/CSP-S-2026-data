#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[200011];
map<ll,ll> dp[200011];
bool flag=true;
bool flag2=true;
map<ll,ll> t;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][1]=a[i];
		if(a[i]>=4) flag=false;
		if(a[i]!=pow(2,log(a[i]))) flag2=false;
	}
	if(flag)
	{
		for(ll i=1;i<=n;i++)
		{
			t[a[i]]++;
		}
		if(t[3]>=m) cout<<3;
		else if(t[3]+t[2]>=m) cout<<2;
		else if(t[3]+t[1]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag2)
	{
		ll maxn=0;
		for(ll i=1;i<=n;i++)
		{
			t[a[i]]++;
			maxn=max(maxn,a[i]);
		}
		ll sum=t[maxn];
		ll loga=log(maxn);
		while(sum<m)
		{
			sum+=t[(maxn+1)/2-1];
			loga--;
		}
		cout<<pow(2,loga+1);
		return 0;
	}
	for(ll i=1;i<=n;i++)
	{
		for(ll j=1;j<=m;j++)
		{
			for(ll k=1;k<i;k++)
			{
				dp[i][j]=max(dp[i][j],a[i]&dp[k][j-1]);
			}
		}
	}
	ll ans;
	for(ll i=1;i<=n;i++)
	{
		ans=max(ans,dp[i][m]);
	}
	cout<<ans;
	return 0;
}
