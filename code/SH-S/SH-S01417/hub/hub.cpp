#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n)  for(int i=0;i<(n);++i)
#define sizc(x) (int((x).size()))
#define allc(x) (x).begin(),(x).end()
#define fir first
#define sec second

constexpr int N=1e6+5;

int tc,n,m,mid,rt;
vector<int> G[N];

int d[N],len[N],tf[N],sz[N],uplen[N];
int to[20][N],val[20][N];
int dfn[N],ed[N],tick;
int st[20][N];
int ask(int l,int r){
	if(l>r)return 0;
	int k=__lg(r-l);
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
void dfs1(int u,int fa){
	d[u]=d[fa]+1,tf[u]=fa,sz[u]=1,len[u]=0;
	to[0][u]=fa,dfn[u]=++tick;
	for(auto v:G[u])if(v!=fa){
		dfs1(v,u),sz[u]+=sz[v];
		len[u]=max(len[u],len[v]+1);
	}
	ed[u]=tick;
}
void dfs1_5(int u,int fa){
	int mx=0,sc=0;
	for(auto v:G[u])if(v!=fa){
		int vv=len[v]+1;
		if(vv>mx)sc=mx,mx=vv;
		else sc=max(sc,vv); 
	}
	for(auto v:G[u])if(v!=fa){
		int oo=len[v]+1==mx?sc:mx;
		val[0][v]=oo+1;
		uplen[v]=max(oo,uplen[u])+1;
		dfs1_5(v,u);
	}
}

int f1[N],f2[N];
int f1r[N];
void dfs2(int u,int fa){
	f1r[u]=1;
	for(auto v:G[u])if(v!=fa){
		dfs2(v,u);
		if(len[v]+1>mid)f1r[u]+=f1r[v];
	}
}
struct DSU{
	int fa[N];
	int find(int x){
		while(x!=fa[x])x=fa[x]=fa[fa[x]];
		return x;
	}
	void init(){
		rep(i,1,n)fa[i]=i;
	}
}dsu;

int stk[N],tp;
bool dfs3(int u,int fa){
	stk[++tp]=u;
	int sum=1;
	if(uplen[u]>mid)sum+=f2[u];
	for(auto v:G[u])if(v!=fa)
		if(len[v]+1>mid)sum+=f1r[v];
	for(auto v:G[u])if(v!=fa){
		int nsum=sum;
		if(len[v]+1>mid)nsum-=f1r[v];
		f2[v]=nsum;
		if(dfs3(v,u))return 1;
	}
	if(u!=rt){
		int l=max(2,tp-mid),r=tp;
		if(f1[u]+f2[stk[l]]<=m){
			while(l<r){
				int mid=l+r+1>>1,x=stk[mid];
				if(f1[u]+f2[x]<=m)l=mid;
				else r=mid-1;
			}
			int x=stk[l];
			if(ask(dfn[x],dfn[u]-1)<d[x]+mid&&ask(ed[u]+1,ed[x])<d[x]+mid){
				return 1;
			}
		}
	}
	--tp;return 0;
}
vector<int> buc[N];

bool chk(){
	rep(i,1,n)f1[i]=f2[i]=n+1;
	dfs2(rt,0);
	rep(i,1,n)if(f1r[i]<=m&&uplen[i]<=mid)return 1;
	rep(i,1,m)buc[i].clear();
	rep(i,1,n)if(f1r[i]<=m)buc[f1r[i]].push_back(i); 
	dsu.init();
	rep(i,1,m)for(auto u:buc[i]){
		int p=u,q=u,ok=1;while(p=q,q=dsu.find(q)){
			int df=d[p]-d[q];
			while(df){
				int b=__lg(df);
				if(val[b][p]+d[u]-d[p]>mid){
					ok=0;
					break;
				}
				df-=1<<b,p=to[b][p];
			}
			if(!ok)break;
			f1[q]=i,dsu.fa[q]=tf[q];
		}
	}
	return f1[rt]<=m||dfs3(rt,0);
}

void solve(){
	cin>>n>>m;
	rep(i,1,n)G[i].clear();
	rep(i,2,n){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(n==m)return cout<<"0\n",void();
	tick=0,dfs1(1,0);
	rt=max_element(d+1,d+n+1)-d;
	tick=0,dfs1(rt,0),f2[rt]=uplen[rt]=0,dfs1_5(rt,0);
	rep(i,1,n)st[0][dfn[i]]=d[i];
	rep(j,1,19)rep(i,1,n-(1<<j)+1)
		st[j][i]=max(st[j-1][i],st[j-1][i+(1<<j-1)]);
	rep(i,1,n)sort(allc(G[i]),[&](int x,int y){
		return len[x]>len[y];
	});
	rep(j,1,19)rep(i,1,n)
		if(to[j][i]=to[j-1][to[j-1][i]])
			val[j][i]=max(val[j-1][i],val[j-1][to[j-1][i]]+(1<<j-1));
	int l=1,r=n;while(l<r){
		mid=l+r>>1;
		if(chk())r=mid;
		else l=mid+1; 
	}
	cout<<l<<'\n';
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;cin>>tc>>T;
	while(T--)solve();
}

/*

。？ 

是凝固的雨 倾倒在屋檐 醒来便被忘却
留白的海岸 漂泊时牵念 故乡此夜无雪
我把纸页赠还泥土 远山如故 层峦荒芜
风声吹远一句恸哭 你的怀抱却无人驻足 

*/
