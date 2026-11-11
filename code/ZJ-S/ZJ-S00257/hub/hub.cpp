#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
const ll inf=1e17+7;
const int N=1e6+5;
const int mod=998244353;
int tid,n,m,lim;
struct node{
	int op,x,c;
	inline node operator +(const int &o) const{
		return {op,x+o,c};
	}
};
inline node operator *(node l,node r){
	if(l.op<r.op) swap(l,r);
	if(!l.op&&!r.op){
		int x=max(l.x,r.x);
		if(x==lim) return {1,0,1};
		else return {0,x,0};
	}
	if(l.op&&!r.op){
		int x=l.x+r.x;
		if(x<=lim) return l;
		return {1,max(0,l.x-(x-lim)),l.c+x-lim};
	}
	if(l.op&&r.op){
		int x=l.x+r.x;
		return {1,0,l.c+r.c+x-1};
	}
	cerr<<"-1\n";
	return l;
}
node f[N],h[N];
vector<int> g[N];
void dfs0(int u,int fa){
	if(fa) g[u].erase(find(g[u].begin(),g[u].end(),fa));
	for(int v:g[u]) dfs0(v,u);
}
void dfs(int u){
	f[u]={0,0,0};
	for(int v:g[u]){
		dfs(v);
		f[u]=f[u]*(f[v]+1);
	}
	//printf("f:%d %d %d %d\n",u,f[u].op,f[u].c,f[u].x);
}
int ans;
void dfs2(int u){
	int sz=(int)g[u].size();
	if(!sz) return;
	vector<node> pre(sz+2),suf(sz+2);
	pre[0]=suf[sz+1]={0,0,0};
	for(int i=1;i<=sz;i++){
		int v=g[u][i-1];
		pre[i]=pre[i-1]*(f[v]+1);
	}
	for(int i=sz;i;i--){
		int v=g[u][i-1];
		suf[i]=suf[i+1]*(f[v]+1);
	}
	for(int i=1;i<=sz;i++){
		int v=g[u][i-1];
		node now=h[u]*pre[i-1]*suf[i+1];
		if(now.op&&f[v].op) ans=min(ans,now.c+f[v].c);
		h[v]=now+1;
		dfs2(v);
	}
}
pii e[N];
inline int chk(int x){
	lim=x;
	dfs(1);
	ans=f[1].c;
	//printf("ans1:%d\n",ans);
	dfs2(1);
	//printf("ans2:%d\n",ans);
	return ans;
}
void sol(){
	for(int i=1;i<=n;i++) g[i].clear();
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].eb(v),g[v].eb(u);
		e[i]={u,v};
	}
	if(m==n){
		puts("0");
		return;
	}
	dfs0(1,0);
//	int pos=chk(1);
	int l=1,r=n,pos=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid)<=m) r=mid-1,pos=mid;
		else l=mid+1;
	}
	printf("%d\n",pos);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1;
	scanf("%d%d",&tid,&T);
	while(T--) sol();
	return 0;
}