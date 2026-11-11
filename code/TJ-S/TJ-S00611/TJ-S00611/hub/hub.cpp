#include<cstdio>
#include<algorithm>
#include<vector>
template<typename T>bool tense(T &a,const T &b){return a>b?a=b,true:false;}
template<typename T>bool relax(T &a,const T &b){return a<b?a=b,true:false;}
int _c,T,n,k,root=1;
const int maxn=1e6+5,maxm=maxn<<1;
int head[maxn],next[maxm],to[maxm],len=1;
void add(int x,int y){
	len++;
	to[len]=y;
	next[len]=head[x],head[x]=len;
}
void add_double(int x,int y){
	add(x,y),add(y,x);
}
int fa[maxn],depth[maxn],size[maxn];
void dfs(int x){
	size[x]=1;
	for(int i=head[x];i;i=next[i]){
		int y=to[i];
		if(y!=fa[x]){
			fa[y]=x,depth[y]=depth[x]+1;
			dfs(y);
			size[x]+=size[y];
		}
	}
}
struct UFS{
	int n,fa[maxn],size[maxn];
	void init(int _n){n=_n; for(int i=1;i<=n;i++) fa[i]=i,size[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(size[y]<size[x]) size[x]+=size[y],fa[y]=x;
		else size[y]+=size[x],fa[x]=y;
	}
}ufs;
namespace Force{
	const int maxn=4000+5;
	int G[maxn][maxn],dist[maxn][maxn];
	void solve(){
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) G[i][j]=false;
		for(int i=1;i<=n;i++) for(int j=head[i];j;j=next[j]) G[i][to[j]]=true;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dist[i][j]=G[i][j]?1:(i==j?0:0x3f3f3f3f);
		for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) tense(dist[i][j],dist[i][k]+dist[k][j]);
		int ans=0x3f3f3f3f;
		for(int s=0;s<(1<<n);s++){
			std::vector<int>v;
			for(int i=1;i<=n;i++) if(s>>(i-1)&1) v.push_back(i);
			if((int)v.size()!=k) continue;
			ufs.init(n);
			for(int i:v) for(int j:v) if(G[i][j]) ufs.merge(i,j);
			int cnt=0;
			for(int i:v) if(ufs.fa[i]==i) cnt++;
			if(cnt>2) continue;
			int max_=0;
			for(int i=1;i<=n;i++){
				int min_=0x3f3f3f3f;
				for(int j:v) tense(min_,dist[i][j]);
				relax(max_,min_);
			}
			tense(ans,max_);
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&_c,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),add_double(x,y);
		fa[root]=0,depth[root]=1;
		dfs(root);
		Force::solve();
		for(int i=1;i<=n;i++) head[i]=0;
		len=0;
	}
	return 0;
}
