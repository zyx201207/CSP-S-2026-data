#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m;
vector<int> g[1000005];
struct node{
	int u,v;
};
vector<node> edge; 
bool vis[1005];
int dep[100];
void dfst(int u,int fa){
	dep[u]=min(dep[u],dep[fa]+1);
	for(auto v:g[u]){
		if(v==fa)continue;
		dfst(v,u);
	}
}
int f[105];
int F(int x){
	if(f[x]==x)return x;
	else return f[x]=F(f[x]);
}
void U(int x,int y){
	x=F(x),y=F(y);
	if(x==y)return;
	f[x]=y;
}
bool viss[105];
int ans=INT_MAX;
void dfs(int p){
	if(p==n+1){
		for(int i=1;i<=n;i++)f[i]=i;
		memset(dep,0x3f,sizeof(dep));
		memset(viss,0,sizeof(viss));
		int c=0;
		for(int i=1;i<=n;i++){
			c+=vis[i];
			//cout<<vis[i];
		}
		if(c>m)return;
		//cout<<endl;
		for(auto e:edge){
			int u=e.u,v=e.v;
			if(!vis[u]||!vis[v])continue;
			//cout<<u<<" "<<v<<endl;
			U(u,v);
		}
		int ccnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i])continue;
			//cout<<F(i)<<endl;
			if(viss[F(i)]==0){
				viss[F(i)]=1;
				ccnt++;
			}
		}
		if(ccnt>2)return;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				dep[i]=0;
				dfst(i,0);
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(dep[i],mx);
			//cout<<dep[i]<<" ";
		}
//		if(mx==2){
//			for(int i=1;i<=n;i++)cout<<vis[i];
//		}
		//cout<<"uioppioiop";
//		if(mx==1){
//			for(int i=1;i<=n;i++){
//				cout<<vis[i];
//				if(vis[i]==1)cout<<F(i)<<"wiueooiu";
//			}
//			cout<<endl;
//			cout<<c<<endl;
//			for(int j=1;j<=n;j++)cout<<dep[j];
//			cout<<endl<<endl;
//		}
		ans=min(ans,mx);
		return;
	}
	vis[p]=1;
	dfs(p+1);
	vis[p]=0;
	dfs(p+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>T>>T;
	while(T--){
		ans=INT_MAX;
		edge.clear();
		memset(vis,0,sizeof(vis));
		cin>>n>>m;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge.push_back({u,v});
			
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<'\n';
	}
	
}
