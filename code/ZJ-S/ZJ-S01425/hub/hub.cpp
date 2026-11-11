#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=22;
const int inf=1e9;
int c,T,n,k,ans;
int lg[N],dep[N],fa[N][M];
vector<int> now,res,g[N];
void init(){
	lg[1]=0;
	for(int i=2;i<N;i++)lg[i]=lg[i>>1]+1;
}
void clear(){
	ans=inf;
	dep[0]=-1;
	now.clear();
	res.clear();
	for(int i=1;i<=n;i++){
		for(int j=1;j<M;j++)fa[i][j]=0;
		dep[i]=0;
		g[i].clear();
	}
}
void dfs(int u,int f){
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	for(int v:g[u])if(v!=f)dfs(v,u);
}
void dfs1(int u,int f){
	now.push_back(u);
	if(now.size()>res.size())res=now;
	for(int v:g[u])if(v!=f)dfs1(v,u);
	now.pop_back();
}
int findlca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=lg[dep[x]];i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){
	int a=findlca(x,y);
	return dep[x]+dep[y]-dep[a]*2;
}
void solve(){
	cin>>n>>k;
	clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int j=1;j<lg[n];j++)for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
	int maxn=0,id=1;
	for(int i=1;i<=n;i++)if(dep[i]>maxn)maxn=dep[i],id=i;
	dfs1(id,0);
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res.size();j++){
			int maxn=0;
			for(int x=1;x<=n;x++){
				maxn=max(maxn,min(dis(x,res[i]),dis(x,res[j])));
			}
			ans=min(ans,maxn);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>T;
	init();
	while(T--)solve();
	return 0;
}