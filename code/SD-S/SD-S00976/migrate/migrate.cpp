#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll N=2e6+5;
ll n,d,a[N];
ll f[N<<2],g[N<<2];
void pushdown(ll p){
	if(f[p]<f[p<<1]){
		f[p<<1]=f[p];
		g[p<<1]=g[p];
	}else if(f[p]==f[p<<1])
		g[p<<1]+=g[p];
	if(f[p]<f[p<<1|1]){
		f[p<<1|1]=f[p];
		g[p<<1|1]=g[p];
	}else if(f[p]==f[p<<1|1])
		g[p<<1|1]+=g[p];
	f[p]=inf,g[p]=0;
}
void build(ll p,ll l,ll r){
	f[p]=inf,g[p]=0;
	if(l==r)return;
	ll mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
void update(ll p,ll l,ll r,ll x,ll y,ll k,ll t){
	if(x<=l&&r<=y){
		if(k<f[p])f[p]=k,g[p]=t;
		else if(f[p]==k)g[p]+=t;
		return;
	}
	pushdown(p);
	ll mid=(l+r)>>1;
	if(x<=mid)update(p<<1,l,mid,x,y,k,t);
	if(mid<y)update(p<<1|1,mid+1,r,x,y,k,t);
}
ll query1(ll p,ll l,ll r,ll x){
	if(l==x&&x==r)
		return f[p];
	pushdown(p);
	ll mid=(l+r)>>1;
	if(x<=mid)return query1(p<<1,l,mid,x);
	return query1(p<<1|1,mid+1,r,x);
}
ll query2(ll p,ll l,ll r,ll x){
	if(l==x&&x==r)
		return g[p];
	pushdown(p);
	ll mid=(l+r)>>1;
	if(x<=mid)return query2(p<<1,l,mid,x);
	return query2(p<<1|1,mid+1,r,x);
}
void solve(){
	ll ans=0;
	cin>>n>>d;
	for(ll i=1;i<=n;++i)
		cin>>a[i];
	for(ll s=1;s<n;++s){
//		cerr<<"s="<<s<<"\n";
		build(1,s,n);
		update(1,s,n,s,s,0,1);
		for(ll u=s;u<n;++u){
			ll w=query1(1,s,n,u),p=query2(1,s,n,u);
			ll v=upper_bound(a+u+1,a+n+1,a[u]+d)-a-1;
//			cerr<<a[u]<<" "<<d<<" "<<a[u]+d<<"\n";
//			cerr<<u<<"->"<<v<<"\n";
			if(u==v)continue;
			update(1,s,n,u+1,v,w+1,p);
		}
		for(ll i=s+1;i<=n;++i){
//			fprintf(stderr,"(%lld,%lld)=%lld,%lld\n",s,i,query1(1,s,n,i),query2(1,s,n,i));
			ans+=(query2(1,s,n,i)==2);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--)solve(); 
	return 0;
}

