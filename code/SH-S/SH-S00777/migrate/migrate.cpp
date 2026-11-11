#include<bits/stdc++.h>
#define N 2000005
#define Ns 3005
using namespace std;
typedef long long ll;
ll n,d,a[N],pl[N],pr[N],nE,hd[N],dl[N],ans[N],f[Ns][Ns],cnt[Ns][Ns],s[Ns],rl[Ns],rr[Ns];
struct Edge{
	ll t,nxt,c1,c2;
} es[N];
void add_edge(ll u,ll v,ll c1,ll c2){
	es[++nE]=(Edge){v,hd[u],c1,c2};
	hd[u]=nE;
}
void dfs(ll u,ll w){
	if(u==pl[u]) dl[u]=0;
	else if(w) dl[u]=dl[pl[u]]+w;
	else dl[u]=0;
	for(ll i=hd[u],v,c1;i;i=es[i].nxt){
		v=es[i].t; c1=es[i].c1;
		dfs(v,c1);
	}
}
void dfs_solve(ll u,ll w1,ll w2){
	ans[u]=w2;
	if(u!=pl[u]){
		if(w1==0&&w2) ans[u]+=dl[pl[u]];
		else if(w1>=2) ans[u]+=ans[pl[u]];
	}
	for(ll i=hd[u],v,c1,c2;i;i=es[i].nxt){
		v=es[i].t; c1=es[i].c1; c2=es[i].c2;
		dfs_solve(v,c1,c2);
	}
}
void input(){
	for(ll i=1;i<=n;i++) pl[i]=pr[i]=hd[i]=dl[i]=ans[i]=0;
	nE=0;
	scanf("%lld %lld",&n,&d);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
}
void solve(){
	sort(a+1,a+n+1);
	pl[1]=1; ll tot=1;
	for(ll i=2;i<=n;i++){
		while(a[i]-a[tot]>d) tot++;
		pl[i]=tot;
	}
	//range[i]=[pl[i],i-1]
	pr[n]=n; tot=n;
	for(ll i=n-1;i>=1;i--){
		while(a[tot]-a[i]>d) tot--;
		pr[i]=tot;
	}
	//x=range[pl[i]],[x+1,pr[x]] and range[i]==2/1 
	//pr[x]-pl[i]==1/0
	for(ll i=1;i<=n;i++){
		if(pl[i]==i) continue;
		ll x1=upper_bound(pr+pl[pl[i]],pr+pl[i],pl[i]+1)-pr-1;
		ll x0=upper_bound(pr+pl[pl[i]],pr+pl[i],pl[i])-pr-1;
		add_edge(pl[i],i,x0-pl[pl[i]]+1,x1-x0);
//		printf("%lld->%lld %lld %lld %lld %lld\n",pl[i],i,x0,x1,pl[pl[i]],pl[i]);
	}
	for(ll i=1;i<=n;i++)
		if(pl[i]==i) dfs(i,0);
	for(ll i=1;i<=n;i++)
		if(pl[i]==i) dfs_solve(i,0,0);
	ll res=0;
	for(ll i=1;i<=n;i++) res+=ans[i];
	printf("%lld\n",res);
}
void solveBF(){
	pl[1]=1; ll tot=1;
	for(ll i=2;i<=n;i++){
		while(a[i]-a[tot]>d) tot++;
		pl[i]=tot;
	}
	//range[i]=[pl[i],i-1]
	pr[n]=n; tot=n;
	for(ll i=n-1;i>=1;i--){
		while(a[tot]-a[i]>d) tot--;
		pr[i]=tot;
	}
	ll res=0;
	for(ll v=1;v<=n;v++){
		for(ll i=1;i<=n+1;i++) s[i]=rl[i]=rr[i]=0;
		f[v][v]=0; cnt[v][v]=1;
		s[v]=1; rr[v]=v;
		ll r=v;
		for(ll u=v-1;u>=0;u--){
			if(pr[u]>v) f[u][v]=cnt[u][v]=1;
			else{
				f[u][v]=f[pr[u]][v]+1;
				ll rrl=rl[pr[u]];
				rrl=max(rrl,u+1);
				cnt[u][v]=s[rrl]-s[pr[u]+1];
				if(cnt[u][v]==2) res++;
			}
			s[u]=s[u+1]+cnt[u][v];
			if(cnt[u][v]!=cnt[u+1][v]){
				for(ll i=u+1;i<=r;i++) rl[i]=u+1;
				r=u;
			}
		}
	}
	printf("%lld\n",res);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll T=1,C;
	scanf("%lld %lld",&C,&T);
	for(ll t=1;t<=T;t++){
		input();
		solve();
	}
	return 0;
}

