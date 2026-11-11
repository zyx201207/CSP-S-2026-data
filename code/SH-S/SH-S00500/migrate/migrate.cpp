#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,ans,a[2000005],lst[2000005],nxt[2000005];
ll cnt[2000005][2],f[2000005][2];
ll s[2000005];
void initszsz(){for(ll i=0;i<=n;i++) s[i]=0;}
ll lowbit(ll x){return x&-x;}
void pls(ll x,ll k){for(ll i=x;i<=n;i+=lowbit(i)) s[i]+=k;}
ll getsum(ll x)
{
	ll res=0;
	for(ll i=x;i;i-=lowbit(i)) res+=s[i];
	return res;
}
void szzakioi()
{
	ans=0;
	scanf("%lld%lld",&n,&d);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++)
	{
		cnt[i][0]=0;cnt[i][1]=0;
		f[i][0]=0;f[i][1]=0;
	}
	ll v=1;
	for(ll i=1;i<=n;i++)
	{
		while(v<n&&a[v+1]<=a[i]+d) v++;
		nxt[i]=v;
		if(nxt[i]>i+1) cnt[nxt[i]][0]++;
	}
	v=n;
	for(ll i=n;i>=1;i--)
	{
		while(v>1&&a[v-1]>=a[i]-d) v--;
		lst[i]=v;
		if(lst[i]<i-1) cnt[lst[i]][1]++;
	}
	initszsz();
	v=0;
	for(ll i=1;i<=n;i++)
	{
		if(lst[i]<i&&nxt[lst[i]]==i) f[i][0]+=f[lst[i]][0]+1;
		while(v<lst[i]){v++;pls(nxt[v],-1ll);}
		f[i][0]+=getsum(i);
		pls(nxt[i],1ll);
	}
	initszsz();
	v=n+1;
	for(ll i=n;i>=1;i--)
	{
		if(nxt[i]>i&&lst[nxt[i]]==i) f[i][1]+=f[nxt[i]][1]+1;
		while(v>nxt[i]){v--;pls(lst[v],-1ll);}
		f[i][1]+=getsum(i)-getsum(i-1);
		pls(lst[i],1ll);
	}
	for(ll i=1;i<n;i++) ans+=cnt[i][1]*cnt[i+1][0];
	for(ll i=1;i<n;i++)
		if(lst[i]<i&&nxt[lst[i]]==i+1) ans+=f[lst[i]][0]*cnt[i][1];
	for(ll i=1;i<n;i++)
		if(nxt[i+1]>i+1&&lst[nxt[i+1]]==i) ans+=f[nxt[i+1]][1]*cnt[i+1][0];
	for(ll i=1;i<n;i++)
		if(lst[i]<i&&nxt[lst[i]]==i+1&&nxt[i+1]>i+1&&lst[nxt[i+1]]==i) ans+=f[lst[i]][0]*f[nxt[i+1]][1];
	printf("%lld\n",ans);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--) szzakioi();
	return 0;
}
