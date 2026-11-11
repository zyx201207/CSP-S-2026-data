#include<bits/stdc++.h>
#define now_time ((int)(((double)clock()/CLOCKS_PER_SEC)*1000))
#define all_memory ((&St-&Ed)/1024.0/1024.0)
#define lca_min(x,y) ((dfn[x]<dfn[y])?(x):(y))

using namespace std;
using ll=long long;

namespace Usd{bool St;}

constexpr ll N=2e6,Imax=0x3f3f3f3f3f3f3f3f;

ll subtask,T;
ll n,k;
ll hd[N+5],eot,ans;
struct edge{
	ll to,nxt;
	void add(ll u,ll v){to=v,nxt=hd[u];hd[u]=eot;}
}e[2*N+5];
ll lg2[N+5];
ll st[N+5][25],dfn[N+5],dfnt,dep[N+5];
ll vis[N+5],tag[N+5],chooo[N+5];

void dfs(ll x,ll fa){
	dfn[x]=++dfnt;
	st[dfnt][0]=fa;
	dep[x]=dep[fa]+1;
	for(ll i=hd[x];i;i=e[i].nxt){
		ll y=e[i].to;
		if(y==fa) continue;
		dfs(y,x);
	}
}

void Lca_init(){
	dfs(1,0);
	for(ll j=1;(1<<j)<=n;++j){
		for(ll i=1;i+(1<<j)-1<=n;++i){
			st[i][j]=lca_min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}

ll _lca(ll u,ll v){
	if(u==v) return u;
	u=dfn[u],v=dfn[v];
	if(u>v) swap(u,v);
	ll lllg=lg2[v-u];++u;
	return lca_min(st[u][lllg],st[v-(1<<lllg)+1][lllg]);
}
ll _dis(ll u,ll v){
	ll lc=_lca(u,v);
	return dep[u]-dep[lc]+dep[v]-dep[lc];
}

void vvvv(ll x){
	vis[x]=1;
	for(ll i=hd[x];i;i=e[i].nxt){
		ll y=e[i].to;
		if(!vis[y]&&chooo[y]) vvvv(y);
	}
}

void get_ans(ll nw,ll num){
	if(num>k) return;
	if(nw==n+1){
		if(num!=k) return;
		for(ll i=1;i<=n;++i) vis[i]=0;
		ll cnt=0;
		for(ll i=1;i<=n;++i)
			if(!vis[i]&&chooo[i]) vvvv(i),++cnt;
		if(cnt>2) return;
		ll ddd=0;
		for(ll i=1;i<=n;++i){
			if(chooo[i]) continue;
			ll nwd=Imax;
			for(ll j=1;j<=n;++j){
				if(chooo[j]) nwd=min(nwd,_dis(i,j));
			}
			ddd=max(nwd,ddd);
		}
		ans=min(ans,ddd);
		return;
	}
	get_ans(nw+1,num);
	chooo[nw]=1;
	get_ans(nw+1,num+1);
	chooo[nw]=0;
}

namespace Usd{bool Ed;void out(){cerr<<"   time: "<<now_time<<"ms\n memory: "<<all_memory<<"MiB\n";}}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>subtask>>T;
	for(ll i=2;i<=N;++i) lg2[i]=lg2[i>>1]+1;
	while(T--){
		memset(hd,0,sizeof(hd));
		eot=0;
		dfnt=0;
		
		cin>>n>>k;
		for(ll i=1;i<n;++i){
			ll u,v;
			cin>>u>>v;
			e[++eot].add(u,v);
			e[++eot].add(v,u);
		}
		Lca_init();
		ans=Imax;
		get_ans(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
