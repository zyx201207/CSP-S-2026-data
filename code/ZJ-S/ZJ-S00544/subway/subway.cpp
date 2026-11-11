#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxm=20005;
vector<pair<int,int>> g[maxm];
int a[maxn][maxm],t[maxn][maxm],num[maxn][maxm];
int ans,w[maxm]; 
bool vis[maxm];
void dfs(int e,int u,int fa,int id,int dis){
	if(dis>ans) return;
	if(u==e){
		ans=min(ans,dis+t[id][num[id][u]]);
		return;
	}
	for(auto node:g[u]){
		int v=node.first;
		int i=node.second;
		if(v!=fa&&vis[v]==0){
			if(i==id){
				vis[v]=1;
				dfs(e,v,u,i,dis);
				vis[v]=0;
			}
			else{
				vis[v]=1;
				dfs(e,v,u,i,dis+t[id][num[id][u]]+t[i][num[i][u]]);
				vis[v]=0;
			} 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,lst;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			num[i][a[i][j]]=j;
			if(j!=1){
				g[a[i][j]].push_back({lst,i});
				g[lst].push_back({a[i][j],i});
			}
			lst=a[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		ans=0x3f3f3f3f;
		for(int j=1;j<=m;j++) vis[i]=0;
		int x,y;
		cin>>x>>y;
		vis[x]=1;
		for(auto v:g[x]){
			if(vis[v.first]) continue;
			vis[v.first]=1;
			dfs(y,v.first,x,v.second,t[v.second][num[v.second][x]]);
			vis[v.first]=0;
		}
		cout<<ans+w[x]+w[y]<<"\n";
	} 
	return 0;
}