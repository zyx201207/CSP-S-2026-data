#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e3+10;

ll c,t;
ll n,d;
ll x[N],cnt,ans;

ll get(ll l,ll r)
{
	ll a=lower_bound(x+1,x+n+1,l)-x,b=lower_bound(x+1,x+n+1,r)-x-1;
	return max(0,(lower_bound(x+1,x+n+1,r)-x) - (lower_bound(x+1,x+n+1,l)-x));
}

void dfs(ll u,ll v,ll dep,ll k)
{
	if(dep>k) return ;
	if(u==v)
	{
		cnt++;
		return ;
	}
	for(int i=u+1;i<=v;i++)
	{
		if(x[i]-x[u]<=d)
		{
			dfs(i,v,dep+1,k);
		}
	}
}

void solve()
{
	ans=0;
	cin >> n >> d;
	for(int i=1;i<=n;i++)
	{
		cin >> x[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(i>1 && x[i]-x[i-1]>d)
		{
			cout << "0\n";
			return ;
		}
	}
	ll k,y;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			k=0,y=i;
			while(y<j)
			{
				y=upper_bound(x+1,x+n+1,x[y]+d)-x-1;
				k++;
			}
			cnt=0;
			dfs(i,j,0,k);
			ans+=(cnt==2);
		}
	}
	cout << ans << "\n";
}

int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}