#include<bits/stdc++.h>
#define lowbit ((x)&(-x))
#define ls(u) ((u)<<1)
#define rs(u) (((u)<<1)|1)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;

const int N=2e6+5,M=4005,INF=0x3f3f3f3f,mod=998244353;
const double eps=1e-9;

vector<int>g[N];
int n,k,p[N],sz[N],f[N],h[M][M],mn[N],dist[N],ltk,st[N],mx;
int find(int x){
	if(p[x]!=x)p[x]=find(p[x]);
	return p[x];
}
void merge(int a,int b){
	int pa=find(a),pb=find(b);
	if(pa!=pb){
		if(sz[pa]<sz[pb])p[pa]=pb,sz[pb]+=sz[pa];
		else p[pb]=pa,sz[pa]+=sz[pb];
		ltk--;
	}
}
void dfs(int u,int p){
	for(int v:g[u]){
		if(v==p)continue;
		if(mn[v]>mn[u]+1)mn[v]=mn[u]+1,dfs(v,u);
	}
} 
void solve(){
	cin>>n>>k;
	//if(k<=2){solve2();return;}
	int cnt=(1<<n),ans=INF;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)h[i][j]=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v),g[v].push_back(u);
		h[u][v]=1;
	}
	for(int mask=0,sum=0;mask<cnt;mask++,sum=0,mx=0){
		for(int i=1;i<=n;i++)mn[i]=INF,f[i]=0;
		for(int i=0;i<n;i++)if(mask&(1<<i))f[i+1]=1,sum++;
		if(sum!=k)continue;
		for(int i=1;i<=n;i++)mn[i]=INF,p[i]=i,sz[i]=0;
		ltk=k;
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(f[i]&&f[j]&&h[i][j])merge(i,j);
		if(ltk>2)continue;
		for(int i=1;i<=n;i++)if(f[i])mn[i]=0,dfs(i,0);
		for(int i=1;i<=n;i++)mx=max(mx,mn[i]);
		ans=min(ans,mx);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)solve(); 
	return 0;
}
