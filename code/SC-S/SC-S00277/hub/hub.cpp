#include<bits/stdc++.h>
//#define int long long
//#define pi pair<int,int>
using namespace std;
int n,k,f[1<<13][50],dep[105],vis[105],vs[105];
int flag,wq;
vector<int> e[105];
void dfs(int u,int fe){
	dep[u]=dep[fe]+1;
	f[u][0]=fe;
	for(int v:e[u]){
		if(v==fe) continue;
		dfs(v,u);
	}
}
//int lca(int x,int y){
//	if(dep[x]<dep[y]) swap(x,y);
//	for(int i=11;i>=0;i--){
//		if(dep[x]>=dep[y]){
//			x=f[x][i];
//		}
//	}
//	if(x==y) return x;
//	for(int i=11;i>=0;i--){
//		if(f[x][i]!=f[y][i]){
//			x=f[x][i];
//			y=f[y][i];
//		}
//	}
//	return f[x][0];
//}
void dij(int u,int fe){
	vis[u]=1;
	for(int v:e[u]){
		if(v==fe) continue;
		if(!vs[v]) continue;
		dij(v,u);
	}
}
void dfs1(int u,int fe){
	dep[u]=dep[fe]+1;
	for(int v:e[u]){
		if(v==fe) continue;
		dfs1(v,u);
	}
}
void solve(){
	memset(f,0,sizeof f);
	memset(dep,0,sizeof dep);
	
	int ans=100000;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
//	cout<<dep[2]<<" "<<dep[3]<<" "<<dep[4]<<" "<<dep[5]<<'\n';
//	for(int j=1;j<=11;j++){
//		for(int i=1;i<=n;i++)f[i][j]=f[f[i][j-1]][j-1];
//	}
//	cout<<lca(5,8)<<"*   ";
	for(int len=0;len<(1<<n);len++){
		vector<int> s;
		for(int i=0;i<n;i++){
			if((1<<i)&len) s.push_back(i+1);
		}
		if(s.size()!=k) continue;
	//	for(int i:s) cout<<i<<" ";
	//	cout<<'\n';
		int re=0;
		memset(vis,0,sizeof vis);
		memset(vs,0,sizeof vs);
		for(int i:s) vs[i]=1;
		for(int i:s){
			if(!vis[i]){
				dij(i,0);
//				cout<<'\n';
//				for(int j=1;j<=n;j++) cout<<vis[j]<<' ';
//				cout<<'\n';
				re++;
			}
		}
	//	cout<<re<<'\n';
		if(re>2) continue;
//		for(int i:s) cout<<i<<" ";
//		cout<<'\n';
		int cnt=0;
		for(int i=1;i<=n;i++){
			int y=10000;
			for(int j:s){
				if(i==j){y=0;break;}
				memset(dep,0,sizeof dep);
				dfs1(i,0);
			//	cout<<i<<"->"<<j<<" "<<dep[j]<<'\n';
				y=min(y,dep[j]-1);
			//	y=min(y,dep[i]+dep[j]-2*dep[lca(i,j)]);
			//	cout<<i<<" "<<j<<" "<<lca(i,j)<<'\n';
			}
		//	cout<<y<<'\n';
			cnt=max(y,cnt);
		}
		ans=min(cnt,ans);
	}
	for(int i=0;i<=n+1;i++) e[i].clear();
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/