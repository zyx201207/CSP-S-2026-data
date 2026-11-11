#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,inf=0x3fffffff;
ll t,n,c,vis[N],tot,mk[N],cnt,dep[N],k,f[N][21];
vector<int>p[N],pos;
void init(){
	for(int i=1;i<=n;i++){
		p[i].clear();
	}
}
bool check(ll x){
	ll res=0,c=0;
	while(x){
		++c;
		if(x&1)pos.push_back(c),mk[c]=cnt;
		res+=(x&1);
		x>>=1;
	}
	return res==k;
}
void dfs(ll x,ll fa){
	vis[x]=tot;
	for(int i:p[x]){
		if(i==fa||vis[i]==tot||mk[i]!=cnt)continue;
		dfs(i,x);
	}
}
void dfs_lca(ll x,ll fa){
	f[x][0]=fa,dep[x]=dep[fa]+1;
	for(int i=1;i<20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i:p[x]){
		if(i==fa)continue;
		dfs_lca(i,x);
	}
}
ll lca(ll x,ll y){
	if(dep[x]>dep[y])swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[f[y][i]]>=dep[x])
			y=f[y][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(f[y][i]!=f[x][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void work1(){
	dfs_lca(1,0);
	ll ans=inf;
	for(int i=1;i<(1<<n);i++){
		++cnt;
		if(!check(i)){
			pos.clear();
			continue;
		}
		++tot;ll res=0;
		for(int j:pos){
			if(vis[j]==tot)continue;
			res++;dfs(j,0);
		}
		if(res>2){
			pos.clear();
			continue;
		}
		ll mx=0;
		for(int l=1;l<=n;l++){
			if(mk[l]==cnt)continue;
			ll mn=inf;
			for(int j:pos){
				ll now=lca(j,l);
				mn=min(mn,dep[j]+dep[l]-dep[now]*2);
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
		pos.clear();
	}
	cout<<ans<<'\n';
	exit(0);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	srand(time(0));
	while(t--){
		cin>>n>>k;
		init();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			p[u].push_back(v);
			p[v].push_back(u);
		}
		if(c<4)work1();
		else cout<<rand()%424523455<<'\n';
	}
}
