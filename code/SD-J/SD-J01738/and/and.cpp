#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m;
ll dp[N];
vector<ll> a;
ll dfs(int x,ll sum,int w)
{
	if(w>m)
	{
		return 0;
	}
	if(x==n+1)
	{
		if(w==m)
		{
			return sum;
		}
		return 0;
	}
	ll maxx=0;
	for(int i=x;i<=n;i++)
	{
		maxx=max(maxx,dfs(i+1,(sum&a[x]),w+1));
	}
	maxx=max(maxx,dfs(x+1,sum,w));
	return maxx;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	if(m==1)
	{
		ll maxx=0;
		for(int i=1;i<=n;i++)
		{
			ll x;cin>>x;
			maxx=max(maxx,x);
		}
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		ll sum=-1LL;
		for(int i=1;i<=n;i++)
		{
			ll x;cin>>x;
			sum&=x;
		}
		cout<<sum;
		return 0;
	}
	a.push_back(0);
	for(int i=1;i<=n;i++)
	{
		ll x;cin>>x;
		a.push_back(x);
	}
	if(m==2)
	{
		ll maxx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	cout<<dfs(1,(1LL<<63)-1,0);
	return 0;
}
