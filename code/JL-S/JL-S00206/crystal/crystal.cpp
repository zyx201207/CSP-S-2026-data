#include<bits/stdc++.h>
#define lson(p) (p<<1)
#define rson(p) (p<<1|1)
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans;
ll m,a[N],sum[N],mx[N<<2];
void build(int L,int R,int p)
{
	if(L==R)
	{
		mx[p]=a[L];
		return;
	}
	int mid=(L+R)>>1;
	build(L,mid,lson(p));
	build(mid+1,R,rson(p));
	mx[p]=max(mx[lson(p)],mx[rson(p)]);
}
ll query(int L,int R,int p,int x,int y)
{
	if(x<=L&&R<=y)return mx[p];
	int mid=(L+R)>>1;
	ll res=-1e18-5;
	if(x<=mid) res=max(res,query(L,mid,lson(p),x,y));
	if(y>mid) res=max(res,query(mid+1,R,rson(p),x,y));
	return res;
}
bool check(int mid)
{
	ll res=1e18+5;
	for(int i=1;i<=n-mid+1;i++)
	{
		res=min(res,mid*query(1,n,1,i,i+mid-1)-(sum[i+mid-1]-sum[i-1]));
		// cout<<query(1,n,1,i,i+mid-1)<<" "<<(sum[i+mid-1]-sum[i-1])<<"\n";
	}
	return res<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	build(1,n,1);
	int l=1,r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	cout<<l-1;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/