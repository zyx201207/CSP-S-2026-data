#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int l,r,st,ly;
}f[2000009];
int n,m,a[1000009];
void pushdown(int rt)
{
	f[rt<<1].st+=f[rt].ly*(f[rt<<1].r-f[rt<<1].l+1);
	f[rt<<1].ly+=f[rt].ly;
	f[rt<<1 |1].st+=f[rt].ly*(f[rt<<1 |1].r-f[rt<<1 |1].l+1);
	f[rt<<1 |1].ly+=f[rt].ly;
	f[rt].ly=0;
	return ;
}
void pushup(int rt)
{
	f[rt].st=f[rt<<1].st+f[rt<<1 |1].st;
	return  ;
}
void build(int l,int r,int rt)
{
	f[rt]={l,r,0,0};
	if(l==r)
	{
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1 |1);
	pushup(rt);
	return ;
}
void memory(int l,int r,int k,int rt)
{
	if(l<=f[rt].l&&f[rt].r<=r)
	{
		f[rt].st+=k*(f[rt].r-f[rt].l+1),f[rt].ly+=k;
		return ;
	}
	pushdown(rt);
	int mid=(f[rt].l+f[rt].r)>>1;
	if(l<=mid)
	{
		memory(l,r,k,rt<<1);
	}
	if(r>mid)
	{
		memory(l,r,k,rt<<1 |1);
	}
	pushup(rt);
	return ;
}
int query(int k,int rt)
{
	if(f[rt].l==f[rt].r)
	{
		return f[rt].l;
	}
	pushdown(rt);
	if(f[rt<<1 |1].st>k)
	{
		return query(k,rt<<1 |1);
	}
	return query(k-f[rt<<1 |1].st,rt<<1);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	build(0,n,1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			memory(1,i-1,a[i]-a[i-1],1);
		}
		int tmp=(f[1].st<=m ? 0 : query(m,1));
		ans=max(ans,i-tmp);
	}
	cout<<ans<<'\n';
	return 0;
}
