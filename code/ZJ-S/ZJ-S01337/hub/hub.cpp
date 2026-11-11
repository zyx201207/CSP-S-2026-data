#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,k;
vector<int>g[N];
int f[21][N],dep[N];
void init(){
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		g[i].clear();
		dep[i]=0;
	}
}
void dfs(int k,int fa){
	dep[k]=dep[fa]+1;
	f[0][k]=fa;
	for(auto j:g[k]){
		if(j==fa)continue;
		dfs(j,k);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[i][x]]>=dep[y]){
			x=f[i][x];
		}
	}
	if(x==y)return x;
	for(int i=20;i>=0;i--){
		if(f[i][x]!=f[i][y]){
			x=f[i][x];
			y=f[i][y];
		}
	}
	return f[0][x];
}
bool vis[N];
void dfs2(int k,int fa){
	if(vis[k]==0)return ;
	vis[k]=0;
	for(auto j:g[k]){
		if(j==fa)continue;
		if(vis[j]==1)dfs2(j,k);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		init();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<=20;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=f[i-1][f[i-1][j]];
			}
		}
		int ans=1e18;
		for(int i=0;i<(1<<n);i++){
			for(int j=1;j<=n;j++)vis[i]=0;
			int cnt=0;
			for(int j=0;j<n;j++){
				if(i>>j & 1){
					cnt++;
					if(cnt>k)break;
					vis[j+1]=1;
				}
			}
			if(cnt!=k)continue;
			int tot=0;
			for(int j=1;j<=n;j++){
				if(vis[j]){
					dfs2(j,0);
					tot++;
					if(tot>2)break;
				}
			}
			if(tot>2)continue;
			
			int res=0;
			for(int x=0;x<n;x++){
				for(int y=x;y<n;y++){
					if(i>>y & 1==0)continue;
					if(i>>x & 1==1)continue;
					//cout<<x+1<<' '<<y+1<<'\n';
					int d=dep[x+1]+dep[y+1]-2*dep[lca(x+1,y+1)];
					res=max(res,d);
				}
			}
			//cout<<"-----\n";
			//cout<<i<<' '<<res<<'\n';
			ans=min(ans,res);
		}
		cout<<ans/2<<'\n';
	}
	
	return 0;
}