#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005;
const ll INF=1e9;
ll c,T,n,d,a[N],cnt;
ll minn[N];
ll check(ll l,ll r)
{
	ll now_p=l,tr=0;
	while(now_p<r)
	{
		int cnt=0;
		if(a[now_p+1]-a[now_p]>d)
			return INF;
		while(a[now_p+cnt]-a[now_p]<=d)
			cnt++;
		now_p+=cnt,now_p--,tr++;
	}
	return tr;
}
void dfs(ll l,ll r,ll tr)
{
	if(tr==0&&r!=l)
		return;
	if(tr>r-l+1)
		return;
	if(l==r)
	{
		cnt++;
		return;
	}
	for(ll i=l+1;a[i]-a[l]<=d;i++)
		dfs(i,r,tr-1);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		ll ans=0;
		memset(minn,0,sizeof minn);
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(ll i=2;i<=n;i++)
			for(ll j=1;j<i;j++)
			{
				cnt=0,dfs(j,i,check(j,i));
				if(cnt==2)
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}

