#include<bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define int long long
#define pb emplace_back
const int M=2e6+5,inf=1e18;
int C,n,m,ans,a[M],L[M],R[M];
int tot,dfn[M],out[M];
vector<int>g[M],e[M];
vector<pair<int,int>>q[M];
bitset<M>vis;
struct Tree{
	struct node{
		int l,r,w,mi,tag;
		inline void Tag(int x){mi+=x,tag+=x;}
	}t[M<<2];
	#define ls p<<1
	#define rs p<<1|1
	#define mid ((t[p].l+t[p].r)>>1)
	inline void build(int l,int r,int p=1){
		t[p]={l,r,r-l+1,0,0};
		if(l==r)return;
		build(l,mid,ls),build(mid+1,r,rs);
	}
	inline void pushdown(int p){
		if(!t[p].tag)return;
		t[ls].Tag(t[p].tag),t[rs].Tag(t[p].tag),t[p].tag=0;
	}
	inline void pushup(int p){
		t[p].mi=min(t[ls].mi,t[rs].mi),t[p].w=0;
		if(t[ls].mi==t[p].mi)t[p].w+=t[ls].w;
		if(t[rs].mi==t[p].mi)t[p].w+=t[rs].w;
	}
	inline void update(int l,int r,int k,int p=1){
		if(l<=t[p].l&&t[p].r<=r)
			return t[p].Tag(k);
		pushdown(p);
		if(l<=mid)update(l,r,k,ls);
		if(r>mid) update(l,r,k,rs);
		pushup(p);
	}
	#undef mid
}T;
namespace AC{
	inline void dfs1(int x){
		vis[x]=1,dfn[x]=++tot;
		for(auto y:e[x]) dfs1(y);
		out[x]=tot;
	}
	inline void add(int i,int j){q[i].pb(dfn[j],out[j]);}
	inline void solve(int x){
		vis[x]=1;
		for(auto it:q[x]) T.update(it.X,it.Y,1);
		ans+=(n-(T.t[1].mi==0)*T.t[1].w);
		for(int y:g[x]) solve(y);
		for(auto it:q[x]) T.update(it.X,it.Y,-1);
	}
	inline void main(){
		for(int i=1;i<=n;++i){
			if(R[i]==i)continue;
			g[R[i]].pb(i);
		}
		for(int i=n;i>=1;--i){
			if(L[i]==i)continue;
			e[L[i]].pb(i);
		}
		tot=ans=0;
		for(int i=1;i<=n;++i) vis[i]=0;
		for(int i=1;i<=n;++i) if(!vis[i]) dfs1(i);
		map<int,int>mp;
		for(int i=1;i<n;++i){
			int mid=R[i],nxt=R[mid];
			if(mid==nxt)continue;
			mp.clear();
			for(int j=mid;j>i&&mid-j<=5;--j){
				int ed=R[j];
				for(int k=ed;k>j&&ed-k<=5;--k) ++mp[k];
			}
			for(int i=nxt;i>mid&&nxt-i<=2;--i)
				if(mp[i]==2) add(i,nxt-1);
		}
		T.build(1,n);
		for(int i=1;i<=n;++i) vis[i]=0;
		for(int i=n;i>=1;--i) if(!vis[i]) solve(i);
		printf("%lld\n",ans);
	}
}
namespace pts40{
	const int N=5005;
	int dp[N],mx[N],dep[N];
	bitset<N>vis;
	inline void main(){
		ans=0;
		for(int i=1;i<=n;++i)
			for(int j=R[i];j>i;--j) g[i].pb(j);
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j) dp[j]=vis[j]=0;
			queue<int>q;
			dp[i]=1,q.emplace(i),vis[i]=1;
			while(q.size()){
				int x=q.front(); q.pop();
				if(dp[x]==2)++ans;
				for(auto y:g[x]){
					dp[y]+=dp[x],dep[y]=dep[x]+1;
					if(dp[y]>2)continue;
					if(!vis[y]) q.emplace(y),vis[y]=1;
				}
			}
		} printf("%lld\n",ans);
	}
}
inline void OIer_WiFi(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	for(int i=1;i<=n;++i){
		L[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
		R[i]=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
	}
	if(n<=5000)pts40::main();
	else AC::main();
}
inline void clear(){
	for(int i=1;i<=n;++i){
		L[i]=R[i]=0;
		q[i].clear(),g[i].clear(),e[i].clear();
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T; scanf("%lld%lld",&C,&T);
	while(T--) OIer_WiFi(),clear();
	return 0;
}