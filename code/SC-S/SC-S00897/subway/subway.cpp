#include<bits/stdc++.h>
using namespace std;
#define fo(i,begin,end) for(int i=begin;i<=end;++i)
#define of(i,begin,end) for(int i=begin;i>=end;--i)
#define ll long long
#define pii pair<int,int>
const int N=505,M=5e5+5,Q=1e5+5,L=25;
int c,n,m,d,q,w[M],l[Q],r[Q];
ll ans;
bool vis[N];
struct node{int tp,v,w,w2;};
vector<node> G[N];
void dfs(int t,int u,int ltp,int lw,ll res){
	if(u==t) ans=min(ans,res+lw+w[t]);
	for(auto i:G[u]){
		if(i.tp!=ltp){
			ll nr=res+lw+i.w;
			if(!vis[i.v]) vis[i.v]=1,dfs(t,i.v,i.tp,i.w2,nr),vis[i.v]=0;
		}else{if(!vis[i.v]) vis[i.v]=1,dfs(t,i.v,ltp,i.w2,res),vis[i.v]=0;}
	}
}
ll sum[N];
int dep[N],p[N][L];
vector<pii> G2[N];
void calc(int u,int fa){
	dep[u]=dep[fa]+1,p[u][0]=fa;
	fo(i,1,L-1) p[u][i]=p[p[u][i-1]][i-1];
	for(auto i:G2[u]) if(i.first!=fa) sum[i.first]=sum[u]+i.second,calc(i.first,u);
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	of(i,L-1,0) if(dep[p[u][i]]>=dep[v]) u=p[u][i];
	if(u==v) return u;
	of(i,L-1,0) if(p[u][i]!=p[v][i]) v=p[u][i],v=p[v][i];
	return p[u][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	fo(i,1,m) cin>>w[i];
	fo(i,1,n){
		int k,a,t,lsta=0,lstt=0;
		cin>>k;
		while(k--){
			cin>>a>>t;
			if(lsta){
				if(c>=7&&c<=11) G2[a].push_back({lsta,t+lstt}),G2[lsta].push_back({a,t+lstt});
				G[a].push_back({i,lsta,t,lstt});
				G[lsta].push_back({i,a,lstt,t});
			}
			lsta=a,lstt=t;
		}
	}
	fo(i,1,q) cin>>l[i]>>r[i];
	if(c>=7&&c<=11){
		calc(1,0);
		fo(_,1,q) cout<<(ll)(sum[l[_]]+sum[r[_]]-2*sum[lca(l[_],r[_])]+w[l[_]]+w[r[_]])<<"\n";
		return 0;
	}
	if(c<=6){
		fo(_,1,q){
			ans=1e18;
			fo(i,1,n) vis[i]=0;
			dfs(r[_],l[_],0,0,w[l[_]]);
			cout<<ans<<"\n";
		}
		return 0;
	}
	if(c>=20&&c<=21){
		ans=w[1]+w[2];
		ll res=1e18;
		for(auto i:G[1]) res=min(res,(ll)i.w+i.w2);
		fo(_,1,q) cout<<ans+res<<"\n";
		return 0;
	}
	return 0;
}