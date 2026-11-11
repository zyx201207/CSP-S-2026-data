#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=15;
int n,k,tot,dis[N][N],d[N],ans;
vector<int>g[N];
int fa[N]={};
int vis[N];
void init(){for(int i=1;i<N;i++)fa[i]=i;tot=k;}
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]);} 
void merge(int x,int y){
	int xf=getfa(x),yf=getfa(y);
	if(fa[xf]!=yf)fa[xf]=yf,tot--;
}
inline void dfs(int i,int cnt){
	if(i==n+1){
		if(cnt!=0)return;
		init();
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int j:g[i]){
					if(vis[j])merge(i,j);
				}
			}
		}
		if(tot>2)return;
		memset(d,0x3f,sizeof(d));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(!vis[j])continue;
				d[i]=min(d[i],dis[i][j]);
			}
		}int res=0;
		for(int i=1;i<=n;i++)res=max(res,d[i]);
		ans=min(ans,res);
		return;
	}
	//1
	if(cnt){
		vis[i]=1;
		dfs(i+1,cnt-1);
		vis[i]=0;
	}
	//0
	dfs(i+1,cnt);
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		memset(dis,0x3f,sizeof(dis));ans=0x3f3f3f3f3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int i=1;i<=n;i++)dis[i][i]=0;
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		init();
		dfs(1,k);
		cout<<ans<<"\n";
	}
	return 0;
}
