#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(ll &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*=f;
}

const int N=2e6+10;
int n;
ll d,a[N],L[N],R[N],pre[N],suf[N],sum[N];
void solve()
{
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) pre[i]=suf[i]=L[i]=R[i]=sum[i]=0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,j=1;i<=n;L[i++]=j)
		while(j<i&&a[i]-a[j]>d) j++;
	for(int i=n,j=n;i>=1;R[i--]=j)
		while(j>i&&a[j]-a[i]>d) j--;
	for(int i=1;i<=n;i++)
	{
		if(L[i]==i) continue;
		int l=L[i],r=L[i+1];
		if(i==n) r=i;
		if(r>l) pre[i]=pre[l]+r-l;
	}
	for(int i=n;i>=1;i--)
	{
		if(R[i]==i) continue;
		int l=R[i-1],r=R[i];
		if(i==1) l=i;
		if(r>l) suf[i]=suf[r]+r-l;
	}
	for(int i=1;i<=n;i++)
		if(R[i]>=i+2) sum[R[i]]+=(R[i-1]<R[i]-1?pre[i]+1:1);
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(L[i]<=i-2) ans+=1LL*(L[i+1]>L[i]+1?suf[i]+1:1)*sum[L[i]+1];
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;scanf("%d%d",&c,&T);
	while(T--) solve();
	return 0;
}
