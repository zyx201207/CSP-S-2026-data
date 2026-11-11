#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mid (l+r)/2
int n,m,a[500005],b[500005],e[500005],ans,f[500005];
void g(int l,int r)
{
	if(l==r)
		return;
	g(l,mid),g(mid+1,r);
	int cnt=l,u=l,v=mid+1;
	while(u<=mid&&v<=r)
	{
		if(a[u]<=a[v])
			b[cnt++]=a[u++];
		else
			b[cnt++]=a[v++];
	}
	while(u<=mid)
		b[cnt++]=a[u++];
	while(v<=r)
		b[cnt++]=a[v++];
	for(int i=l;i<=r;i++)
		a[i]=b[i];
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	g(1,n);
	for(int i=2;i<=n;i++)
		e[i]=a[i]-a[i-1];
	int k=0,r=0;
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]+e[i];
	for(int i=1;i<=n;i++)
	{
		k=k-f[r]+f[i-1];
		while(r+1<=n&&k+e[r+1]*(r+1-i)<=m)
			k+=e[r+1]*(r-i+1),r++;
		ans=max(ans,r+1-i);
	}
	cout<<ans;
}
