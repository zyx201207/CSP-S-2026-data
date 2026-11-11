#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,T,n,k,p[1000010],minn,mkt,mt;
vector <ll> v[1000010];
bool flag[1000010];
void dfs2(ll x,ll s)
{
	for(ll i=0;i<v[x].size();i++)
	{
		ll y=v[x][i];
		if(p[lower_bound(p+1,p+s+1,y)-p]!=y) continue;
		if(flag[y]==1) continue;
		flag[y]=1;
		dfs2(y,s);
	}
}
bool check(ll s)
{
	ll ans=0;
	memset(flag,0,sizeof(flag));
	for(ll i=1;i<=s;i++)
	{
		if(flag[p[i]]==0)
		{
			ans++;
			flag[p[i]]=1;
			dfs2(p[i],s);
			if(ans>2) return true;
		}
	}
	return false;
}
void dfs3(ll x,ll k,ll step)
{
	if(x==k)
	{
		mt=min(mt,step);
		return;
	}
	for(ll i=0;i<v[x].size();i++)
	{
		ll y=v[x][i];
		if(flag[y]==1) continue;
		flag[y]=1;
		dfs3(y,k,step+1);
		flag[y]=0;
	}
}
void dfs1(ll x,ll s)
{
	if(s==k)
	{
		if(check(s)) return;
		ll ans=0;
		for(ll i=1;i<=n;i++)
		{
			if(p[lower_bound(p+1,p+s+1,i)-p]==i) continue;
			mkt=1000000;
			for(ll j=1;j<=s;j++)
			{
				mt=1000000;
				memset(flag,0,sizeof(flag));
				flag[i]=1;
				dfs3(i,p[j],0);
				mkt=min(mkt,mt);
			}
			ans=max(ans,mkt);
		}
		minn=min(minn,ans);
		return;
	}
	if(x>n) return;
	p[s+1]=x;
	dfs1(x+1,s+1);
	dfs1(x+1,s);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(ll i=1;i<=n;i++) v[i].clear();
		for(ll i=1;i<n;i++)
		{
			ll x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		minn=1000000;
		memset(p,0,sizeof(p));
		dfs1(1,0);
		cout<<minn<<endl;
	}
	return 0;
}
