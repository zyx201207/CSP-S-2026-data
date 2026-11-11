#include<bits/stdc++.h>
#define int long long
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)

constexpr int inf=1e16,N=1e6+10;
int ty,n,k,ex[N],ey[N],ans;
std::vector<int>G[N];
int anc[N],f[N];
int find(int u){
	if(anc[u]==u)return u;
	else return anc[u]=find(anc[u]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	if(u!=v)anc[v]=u;
}

int work(int u,int fa,int dep){
	int cur=inf;
	if(f[u])cur=dep;
	for(auto v:G[u])if(v!=fa){
		cur=min(cur,work(v,u,dep+1));
	}
	return cur;
}

int check(){
	rep(i,1,n)anc[i]=i;
	int cnt=0;
	rep(i,1,n-1){
		int u=ex[i],v=ey[i];
		if(f[u]==f[v])merge(u,v);
	}
	rep(i,1,n)
		if(f[i]&&find(i)==i)++cnt;
	if(cnt>2)return inf;
	int rs=0;
	rep(i,1,n)if(!f[i]){
		rs=max(rs,work(i,0,0));
	}
	return rs;
}

void dfs(int u,int s){
	if(u>n){
		if(s==k)ans=min(ans,check());
		return ;
	}
	if(s+n-u+1<k)return ;
	f[u]=1,dfs(u+1,s+1),f[u]=0,dfs(u+1,s);
}

void solve(){
	std::cin>>n>>k;
	rep(i,1,n)G[i].clear();
	rep(i,1,n-1){
		int u,v;std::cin>>u>>v;
		G[u].emplace_back(v),G[v].emplace_back(u);
		ex[i]=u,ey[i]=v;
	}
	ans=inf;
	dfs(1,0);
	std::cout<<ans<<"\n";
}

signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);

	int _;std::cin>>ty>>_;
	while(_-->0){
		solve();
	}

	return 0;
}
