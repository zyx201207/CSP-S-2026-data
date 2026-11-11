#include<bits/stdc++.h>
#define int long long
#define FUCKYOUCCF 0
using namespace std;
const int N=5e5+10;
int n,q=1,p=1,ans,m,a[N],sum[N];
struct point{
	int l,r,mx;
}tr[4*N];
int f(int l,int r)
{
	int x=a[r]*(r-l+1)+sum[l-1]-sum[r];
	return x;
}
void un(int l,int r,int p)
{
	tr[p]={l,r};
	if(l==r)
	{
		tr[p].mx=a[l];
		return;
	}
	int mid=(l+r)>>1;
	un(l,mid,p>>1);
	un(mid+1,r,p>>1&1);
	tr[p].mx=max(tr[p>>1].mx,tr[p>>1&1].mx);
}
int find(int l,int r,int p)
{
//	if(l<=tr[p].l&&tr[p].r<=r)
//	{
//		return tr[p].mx;
//	}
//	int ans=0;
//	if(l<=tr[p>>1].r)ans=find(l,r,p>>1);
//	if(tr[p>>1&1].l<=r)ans=max(ans,find(l,r,p>>1&1));
//	return ans;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	un(1,n,1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int q=1;q<=n;q++)
	{
		p=max(q,p);
		while(p<n&&(find(q,p+1,1)==a[p+1])&&f(q,p+1)<=m)p++;
		ans=max(ans,p-q+1);
	}
	cout<<ans;
	return FUCKYOUCCF;
}