#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
using namespace std;
const int N=2e6+100;
ll rd()
{
	ll x=0,y=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')y=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x*y;
}
struct node
{
	int cmin,cs;
	node(){cmin=1e9,cs=0;}
	friend node operator+(const node &ft,const node &lt)
	{
		node res;
		if(ft.cmin<lt.cmin)res.cs=ft.cs;
		else if(ft.cmin==lt.cmin)res.cs=ft.cs+lt.cs;
		else res.cs=lt.cs; 
		res.cmin=min(ft.cmin,lt.cmin);
		return res;
	}
}tr[N<<2];
int n,lt[N],rt[N];
ll d,a[N];
void mdf(int k,int l,int r,int x,int y,int z)
{
	if(l==r){tr[k].cmin=y;tr[k].cs=z;return;}
	int mid=l+r>>1;
	if(x<=mid)mdf(k<<1,l,mid,x,y,z);
	else mdf(k<<1|1,mid+1,r,x,y,z);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
node qry(int k,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)return tr[k];
	int mid=l+r>>1;node res;
	if(x<=mid)res=res+qry(k<<1,l,mid,x,y);
	if(y>mid)res=res+qry(k<<1|1,mid+1,r,x,y);
	return res;
}
void bld(int k,int l,int r)
{
	if(l==r){tr[k].cmin=1e9;tr[k].cs=0;return;}
	int mid=l+r>>1;
	bld(k<<1,l,mid);bld(k<<1|1,mid+1,r);
	tr[k]=tr[k<<1]+tr[k<<1|1];
}
void mian()
{
	n=rd();d=rd();
	rep(i,1,n)a[i]=rd();
	for(int i=1,j=1;i<=n;++i)
	{
		while(j<=i&&a[i]-a[j]>d)++j;
		lt[i]=j;
	}
	for(int i=n,j=n;i>=1;--i)
	{
		while(j>=i&&a[j]-a[i]>d)--j;
		rt[i]=j;
	}
	//rep(i,1,n)printf("%d %d %d\n",i,lt[i],rt[i]);
	ll ans=0;
	rep(i,1,n)
	{
		bld(1,1,n);mdf(1,1,n,i,0,1);
		per(j,i-1,1)
		{
			node p=qry(1,1,n,j+1,min(rt[j],i));
			mdf(1,1,n,j,p.cmin+1,p.cs);
			if(p.cs==2)++ans;
		}
		rep(j,i+1,n)
		{
			node p=qry(1,1,n,max(lt[j],i),j-1);
			mdf(1,1,n,j,p.cmin+1,p.cs);
		//	printf("%d %d %d\n",j,p.cmin,p.cs);
			if(p.cs==2)++ans;
		}
	}
	printf("%lld\n",ans/2);
}
void mian2()
{
	n=rd();d=rd();
	rep(i,1,n)a[i]=rd();
	if(n==1){printf("0\n");return ;}
	ll c=a[2]-a[1];
	ll p=d/c;
	if(p==1){printf("0\n");}
	else if(!p)printf("0\n");
	else 
	{
		ll ans=0;
		for(int i=1;i<=n;++i)
		{
			if(i-2*p+1>=1)++ans;
			if(i+2*p-1<=n)++ans;
		}
		printf("%lld\n",ans/2);
	}
}
void mian3()
{
	n=rd();d=rd();
	rep(i,1,n)a[i]=rd();
	ll ans=0;
	rep(i,1,n)
	{
		if(i-2>=1)++ans;
		if(i+2<=n)++ans;
		if(i+3<=n&&a[i+3]-a[i+1]>d)++ans;
		if(i-3>=1&&a[i-1]-a[i-3]>d)++ans;
	}
	printf("%lld",ans/2);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=rd(),T=rd();
	if(c==11||c==12)while(T--)mian2();
	else if(c==13||c==14)while(T--)mian3(); 
	else while(T--)mian();
	
	return 0;
}

