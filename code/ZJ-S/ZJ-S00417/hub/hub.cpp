#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N=1e2+5;
const int LOG=20;

int n,k;

//int p[N];
//int t[N],frank;
//
//int a[N][N];
//
//vector<int> son[N],G[N],g[N];
//
//int tot;
//int fa[N],vis[N];
//
//void dfs(int u){
//	vis[u]=1;
//	fa[u]=tot;
//
//	for(auto v:son[u]) son[n+tot].push_back(fa[v]);
//
//	for(auto v:G[u]){
//		if(vis[v]) continue;
//		dfs(v);
//	}
//}
//
//unordered_map<int,unordered_map<int,bool>> mp;
//
//int dep[N];
//int st[N][LOG];
//
//void dfs2(int u,int fa){
//	
//	dep[u]=dep[fa]+1;
//	st[u][0]=fa;
//	
//	for(int i=1;i<LOG;i++){
//		st[u][i]=st[st[u][i-1]][i-1];
//	}
//	
//	for(auto v:G[u]){
//		if(vis[v]) continue;
//		dfs2(v,u);
//	}
//}
//
//int lca(int u,int v){
//	if(dep[u]<dep[v]) swap(u,v);
//	int dif=dep[u]-dep[v];
//	
//	for(int i=0;i<LOG;i++){
//		if(dif>>i&1){
//			u=st[u][i];
//			v=st[v][i];
//		}
//	}
//	
//	if(u==v) return u;
//	
//	for(int i=LOG-1;i>=0;i--){
//		if(st[u][i]!=st[v][i]){
//			u=st[u][i];
//		}
//	}
//	
//	return st[u][0];
//}
//
//int ans=1e9;
//
//void solve(){
//	frank=0; mp.clear();
//	for(int i=1;i<=n+2;i++){
//		fa[i]=i;
//		G[i].clear();
//		dep[i]=vis[i]=0;
//		
//		for(int j=0;j<LOG;j++) st[i][j]=0;
//	}
//	
//	for(int i=1;i<=k;i++) t[++frank]=p[i];
//	
//	for(int i=1;i<=frank;i++){
//		for(int j=i+1;j<=frank;j++) if(a[i][j]){
//			G[t[i]].push_back(t[j]);
//			G[t[j]].push_back(t[i]);
//			
////			cout<<t[i]<<" "<<t[j]<<endl;
//		}
//	}
//	
//	tot=n;
//	for(int i=1;i<=n;i++) if(!vis[i]){
//		++tot; if(tot>n+2) break;
//		dfs(i);
//	}
//	if(tot>n+2) return;
//	
//	tot-=n;
//	
//	for(int i=1;i<=n+tot;i++) if(fa[i]==i){
//		for(auto v:son[i]) if(!mp[v][i]){
//			mp[v][i]=mp[i][v]=1;
//			g[i].push_back(v);
//			g[v].push_back(i);
//		}
//	}
//	
//	dfs2(n+1,0);
//	
//	int tot=0;
//	for(int i=1;i<=n;i++) if(fa[i]==i){
//		int res=1e9;
//		if(tot==1) res=min(res,dep[i]+dep[n+1]-2*dep[lca(i,n+1)]);
//		if(tot==2) res=min(res,dep[i]+dep[n+2]-2*dep[lca(i,n+2)]);
//		tot=max(tot,res);
//	}
//	ans=min(ans,tot);
//}
//
//void get(int x,int sum){
//	if(sum>k){
//		solve();
//		return;
//	}
//	if(x>n) return;
//	for(int i=x+1;i<=n;i++){
//		p[sum]=i;
//		get(i,sum+1);
//	}
//}

int main(){

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int c,T; cin>>c>>T;
	while(T--){
		cin>>n>>k;
		
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
//			a[u][v]=1;
//			son[u].push_back(v);
//			son[v].push_back(u);
		}
		
		cout<<n/k-1<<endl;
		
//		for(int i=1;i<=n;i++) p[i]=i;
//		
//		ans=1e9;
//		get(1,1);
//		cout<<ans<<endl;
	}

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
