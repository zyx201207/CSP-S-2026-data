#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C,T,n,d,a[2000010],minn,ans,s;
vector <ll> v[2000010];
bool flag[2000010],fs;
void dfs1(ll x,ll k,ll step)
{
	if(x==k)
	{
		minn=min(minn,step);
		return;
	}
	for(ll i=0;i<v[x].size();i++)
	{
		ll y=v[x][i];
		if(flag[y]==1) continue;
		flag[y]=1;
		dfs1(y,k,step+1);
		flag[y]=0;
	}
}
void dfs2(ll x,ll k,ll step)
{
	if(fs) return;
	if(x==k)
	{
		if(step==minn) s++;
		if(s>2) fs=1;
		return;
	}
	for(ll i=0;i<v[x].size();i++)
	{
		ll y=v[x][i];
		if(flag[y]==1) continue;
		flag[y]=1;
		dfs2(y,k,step+1);
		if(fs) return;
		flag[y]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(ll i=1;i<=n;i++)
		{
			cin>>a[i];
			v[i].clear();
		}
		for(ll i=1;i<=n;i++)
		{
			ll j=i-1;
			while(j>=1 && abs(a[j]-a[i])<=d) v[i].push_back(j--);
			j=i+1;
			while(j<=n && abs(a[j]-a[i])<=d) v[i].push_back(j++);
		}
		ans=0;
		for(ll i=1;i<n;i++)
		{
			for(ll j=i+1;j<=n;j++)
			{
				minn=2000010;
				memset(flag,0,sizeof(flag));
				flag[i]=1;
				dfs1(i,j,0);
				s=0;
				fs=0;
				memset(flag,0,sizeof(flag));
				flag[i]=1;
				dfs2(i,j,0);
				if(s==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
