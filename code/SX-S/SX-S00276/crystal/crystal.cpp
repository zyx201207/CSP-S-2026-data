#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+50;
ll T,n,m,k,ans,sum,num,cnt;
ll prime[N],vis[N],dis[N],a[N],c[N];
struct line_tree
{
	ll l,r,sum,lazy;
}t[N*4];
ll quick_pow(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res*=x;
        x*=x,n>>=1;
    }
    return res;
}
void prime_line(ll n)
{
	memset(vis,0,sizeof vis);
	memset(prime,0,sizeof prime);
	cnt=0;
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i]) prime[++cnt]=i;
        for(ll j=1;j<=cnt&&i*prime[j]<=n;++j)
        {
            vis[i*prime[j]]=1;
            if(!i%prime[j]) break;
        }
    }
}
bool cmp(ll a,ll b)
{
	return a<b;
}
//void build(ll k,ll l,ll r)
//{
//	if(l==r)
//	{
//		t[k].sum=a[l],t[k].lazy=0;
//		return;
//	}
//	t[k].l=k<<1,t[k].r=t[k].l+1,t[k].lazy=0;
//	t[k].sum=t[t[k].l].sum+t[t[k].r].sum;
//}
//void posh_down(ll k)
//{
//	if(!t[k].lazy) return;
//	t[t[k].l].lazy+=t[k].lazy,t[t[k].r].lazy+=t[k].lazy;
//	t[t[k].l].sum+=t[k].lazy*(t[t[k].l].r-t[t[k].l].l+1);
//	t[t[k].r].sum+=t[k].lazy*(t[t[k].r].r-t[t[k].r].l+1);
//	t[k].lazy=0;
//}
//void add(ll k,ll l,ll r,ll w)
//{
//	if(t[k].l>=l&&t[k].r>=r)
//}

//ll lowbit(ll i)
//{
//	return i&-i;
//}
//void add(ll v,ll w)
//{
//	while(v<=n) c[v]+=w,v+=lowbit(v);
//}
//ll ask(ll v)
//{
//	ll res=0;
//	while(v>0) res+=c[v],v-=lowbit(v);
//	return res;
//}

//试制贪心_二分答案_线段树求和比较_树状数组好像就够了_都多余了_大样例爆了还是要二分_

void work()
{
	cin>>n>>m;
	for(ll i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	c[0]=0;
	for(ll i=1;i<=n;++i) c[i]=c[i-1]+a[i];
//	for(ll i=1;i<=n;++i) cout<<i<<" "<<a[i]<<" "<<c[i]<<'\n';
	for(ll i=1;i<=n;++i)
	{
		ll l=i,r=n;
		while(l<=r)
		{
			if(l==r)
			{
				if(c[l]-c[i-1]+m>=a[l]*(l-i+1)) ans=max(ans,l-i+1);
				break;
			}
			ll mid=(l+r)/2;
			if(c[mid]-c[i-1]+m>=a[mid]*(mid-i+1)) ans=max(ans,mid-i+1),l=mid+1;
			else r=mid;
		}
	}
	if(!ans) ans=1;
	cout<<ans;
    return;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    T=1;
//    cin>>T;
    while(T--) work();
    return 0;
}
//差寒挥锋安盛世
//救苦度厄济苍生

//影中故我无暇，落灯花
//孑然立，难逃命煞
//明月映赤霞，大浪淘沙，人生本如画
//何如是，望云涯，四海无家
//昨日希望种下，护城厦
//箭在弦，蓄势待发
//功业仍未罢，一瞬光华，血仇心中扎
//诸般业，尽笑纳，血月正恰