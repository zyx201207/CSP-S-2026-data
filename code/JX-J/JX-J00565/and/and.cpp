#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,m,a[N],ans,mx=-1;
bool vis[N];
void dfs(ll pos,ll l,ll now)
{
	if(pos==m+1)
	{
		ans=max(ans,now);
		return;
	}
	for(int i=l;i<=n;i++)
	{
		if(vis[i]) continue;
		ll x=now;
		vis[i]=true;
		dfs(pos+1,i,now&a[i]);
		vis[i]=false;
		now=x;
	}
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		ll cnt=a[1];
		for(int i=2;i<=n;i++)
		{
			cnt=cnt&a[i];
		}
		cout<<cnt;
		return 0;
	}
	if(m==n-1)
	{
		ll anss=a[2];
		for(int i=3;i<=n;i++)
		{
			anss=anss&a[i];
		}
		cout<<anss;
		return 0;
	}
	if(mx<4)
	{
		ll cntt[4]={},sum=0,rec;
		for(int i=1;i<=n;i++) cntt[a[i]]++;
		sort(a+1,a+n+1,cmp);
		rec=a[1];
		sum++;
		if(sum==m)
		{
			cout<<rec;
			return 0;
		}
		for(int i=2;i<=n;i++)
		{
			rec=rec&a[i];
			sum++;
			if(sum==m) break;
		}
		cout<<rec;
		return 0;
	}
	ll st=1,sum=1;
	for(int i=1;i<=31;i++)
	{
		st*=2;
		sum+=st;
	}
	dfs(1,1,sum);
	cout<<ans;
	return 0;
}
