#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
const int M=1e6+5,inf=1e18;
int C,T,n,m,mx,cnt,res;
int a[M],f[M],dep[M],bel[M];
int L[M],R[M];
vector<int>g[M];
bitset<M>vis,mark;
inline void dfs1(int x,int fa){
	dep[x]=dep[fa]+1,f[x]=fa;
	if(dep[x]>dep[mx])mx=x;
	for(auto y:g[x]) if(y!=fa) dfs1(y,x);
}
inline void dfs2(int x,int fa,int k){
	dep[x]=bel[x]=dep[fa]+1;
	for(auto y:g[x]) if(y!=fa&&!vis[y])
		dfs2(y,x,k),bel[x]=max(bel[x],bel[y]);
	res+=bel[x]-dep[x]>=k;
}
inline void dfs3(int x,int fa,int dep[]){
	dep[x]=dep[fa]+1;
	for(auto y:g[x]) if(y!=fa) dfs3(y,x,dep);
}
inline bool check(int x){
	if(n<=4000){
		int ans=n;
		for(int i=x+1;i<cnt-x;++i){
			vis[a[i+1]]=1,res=0;
			dfs2(a[x+1],0,x);
			vis[a[i+1]]=0,vis[a[i]]=1;
			dfs2(a[cnt-x],0,x);
			vis[a[i]]=0;
			ans=min(ans,res);
		}
		return ans<=m;
	} else {
		dfs3(a[x+1],0,L);
		dfs3(a[cnt-x],0,R);
		for(int i=1;i<=n;++i){
			if(L[i]>x&&R[i]>x)return 0;
		} return 1;
	}
}
inline void OIer_WiFi(){
	scanf("%lld%lld",&n,&m);
	for(int i=1,u,v;i<n;++i){
		scanf("%lld%lld",&u,&v);
		g[u].pb(v),g[v].pb(u);
	}
	int st;
	dfs1(1,0),st=mx,dfs1(mx,0);
	while(mx!=st)a[++cnt]=mx,mx=f[mx];
	a[++cnt]=st;
	for(int i=1;i<=cnt;++i) mark[a[i]]=1;

	int l=1,r=cnt>>1,res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))res=mid,r=mid-1;
		else l=mid+1;
	} printf("%lld\n",res);
}
inline void clear(){
	cnt=0,vis.reset();
	for(int i=1;i<=n;++i) g[i].clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--) OIer_WiFi(),clear();
	return 0;
}
// 50pts 17:59