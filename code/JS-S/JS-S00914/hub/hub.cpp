#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int cs,T,n,k,x,y,res,fa[N][25],dep[N];
vector<int> v[N];
bool ok[N],vis[N];
void mark(int x,int f){
	for(auto i:v[x])if(i!=f&&ok[i]&&!vis[i])vis[i]=1,mark(i,x);
}
void dfs(int x,int f){
	dep[x]=dep[f]+1,fa[x][0]=f;
	for(auto i:v[x])if(i!=f)dfs(i,x);
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=22;i>=0;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	for(int i=22;i>=0;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	if(x==y)return x;
	return fa[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}
main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&cs,&T);
	while(T--){
		scanf("%d %d",&n,&k);res=1e9;
		for(int i=1;i<=n;i++)v[i].clear(),dep[i]=0;
		for(int i=1;i<=n;i++)for(int j=0;j<23;j++)fa[i][j]=0;
		for(int i=1;i<n;i++)scanf("%d %d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		dfs(1,0);
		for(int j=1;j<23;j++)for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
		for(int s=0;s<(1<<n);s++)if(__builtin_popcount(s)==k){
			int id=1,x=s;
			vector<int> shu;
			while(x){
				if(x&1)shu.push_back(id),ok[id]=1;
				id++,x>>=1;
			}
			int cnt=0;
			for(auto i:shu)if(!vis[i])cnt++,mark(i,0);
			if(cnt<=2){
				int ans=0;
				for(int i=1;i<=n;i++){
					int mn=1e9;
					for(auto j:shu)mn=min(mn,dis(i,j));
					ans=max(ans,mn);
				}
				res=min(res,ans);
			}
			for(auto i:shu)ok[i]=vis[i]=0;
		}
		cout<<res<<"\n";
	}
}