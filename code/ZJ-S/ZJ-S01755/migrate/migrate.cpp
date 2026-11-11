#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k;
ll const N=2e6+5;
ll a[N],s[N];
ll minst=LLONG_MAX;
ll ans;
void dfs(ll x,ll r,ll st)
{
	if(st>minst)
	{
		return ;
	}
	if(x==r)
	{
		s[st]++;
		minst=min(st,minst);
		return ;
	}
	for(ll i=x+1;i<=r;i++)
	{
		if(abs(a[i]-a[x])<=k)
			dfs(i,r,st+1);
	}
}
void solve()
{
	cin>>n>>k;
	ll d=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	d=a[2]-a[1];
	if(n>5e3)
	{
		cout<<n-2*min(k,a[n]-a[1])/d+1;
		return ;
	}
	ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			minst=LLONG_MAX;
			memset(s,0,sizeof(s));
			dfs(l,r,0);
			if(s[minst]==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
999999999999999994 999999999999999996 999999999999999997 999999999999999998 1000000000000000000
*/