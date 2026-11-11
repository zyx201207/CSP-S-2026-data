#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m;
/*struct tree{
	int l,r,val;
}tr[N*4];
priority_queue<int>pq;
void build(int node,int l,int r)
{
	tr[node].l=l,tr[node].r=r;
	if(l==r) tr[node]=a[l];
	int mid=l+r>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	//
}
*/
int MAX=-1;
bool check(int x)
{
	/*int y=m;
	for(int i=1;i<=x;i++)
	{
		if(a[x]-a[i]>y) return 0;
		y-=(a[x]-a[i]);
	}
	return 1;*/
	int y=m;
	int ans=0;
	for(int l=1,r=1;l<=n&&r<=n;r++)
	{
		ans+=a[r];
		if(r-l+1>=x) return 1;
		while(a[r]*(r-l+1)-ans>m) ans-=a[l],l++;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r)
	{
		//cout<<l<<' '<<r<<'\n';
		int mid=((l+r-1)>>1)+1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l-1);
	return 0;
}
/*
Ï£ÍûÄÜ100 
*/
