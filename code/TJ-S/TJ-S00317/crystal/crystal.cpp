#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll x,ll y)
{
	return x>y;
}
ll n,m;
ll a[500010];
ll d[500010];
ll tr[2000010];
ll tag[2000010];
void build(int u,int l,int r)
{
	if(l==r)
	{
		tr[u]=d[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	tr[u]=tr[u<<1]+tr[u<<1|1];
}
void pushdown(int u,int l,int r)
{
	int mid=(l+r)>>1;
	tr[u<<1]+=tag[u]*(mid-l+1);
	tr[u<<1|1]+=tag[u]*(r-mid);
	tag[u<<1]+=tag[u];
	tag[u<<1|1]+=tag[u];
	tag[u]=0;
}
void update(int u,int l,int r,int L,int R,ll x)
{
	if(L<=l&&r<=R)
	{
		tr[u]+=x*(r-l+1);
		tag[u]+=x;
		return ;
	}
	pushdown(u,l,r);
	int mid=(l+r)>>1;
	if(mid>=L)update(u<<1,l,mid,L,R,x);
	if(mid<R)update(u<<1|1,mid+1,r,L,R,x);
	tr[u]=tr[u<<1]+tr[u<<1|1];
}
ll query(int u,int l,int r,int L,int R)
{
	if(L<=l&&r<=R)return tr[u];
	pushdown(u,l,r);
	int mid=(l+r)>>1;
	ll res=0;
	if(mid>=L)res+=query(u<<1,l,mid,L,R);
	if(mid<R)res+=query(u<<1|1,mid+1,r,L,R);
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)d[i]=a[1]-a[i];
	build(1,1,n);
	ll ans=0;
	int last=1;
	for(int i=1;i<=n;i++)
	{
		int k=query(1,1,n,i,i);
		update(1,1,n,i,n,-k);
		int l=last,r=n;
		if(query(1,1,n,i,n)<=m)
		{
			ans=max(ans,n-i+1);
			break;
		}
		int idx=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(query(1,1,n,i,mid)>m)
			{
				r=mid-1;
			}
			else
			{
				idx=mid;
				l=mid+1;
			}
		}
		ans=max(ans,idx+1ll-i*1ll);
		last=idx;
	}
	cout<<ans;
	return 0;
}
//O(n log^2 n)qwq
