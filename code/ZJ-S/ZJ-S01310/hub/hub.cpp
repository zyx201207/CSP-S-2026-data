#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int csd,T,n,k,dep[N],f[N][23],b[N],ans;
bool vis[N];
vector<int>g[N];
void dfs(int u,int last){
	f[u][0]=last;
	dep[u]=dep[last]+1;
	for(int i=1;i<21;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:g[u]){
		if(v==last) continue;
		dfs(v,u);
	}
}
bool check(){
	int p=0;
	for(int i=1;i<=n;i++){
		if(!vis[f[i][0]]&&vis[i]) p++;
	}
	return p<3;
}
int lca(int x,int y){
	if(x==y) return x;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]<dep[y]) continue;
		x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]==f[y][i]) continue;
		x=f[x][i];
		y=f[y][i];
	}
	return f[x][0];
}
void pai(int ind,int x){
	if(ind>k){
		if(!check()) return;
		int sum=0;
		
		for(int i=1;i<=n;i++){
			int xx=2e9;
			if(vis[i]) continue;
			for(int j=1;j<ind;j++){
				int t=lca(i,b[j]);
				xx=min(dep[i]+dep[b[j]]-dep[t]-dep[t],xx);
//				if(dep[i]+dep[b[j]]-dep[t]-dep[t]==1) cout<<i<<' '<<j;
			}
			sum=max(sum,xx);
		}
		ans=min(ans,sum);
		return;
	}
	for(int i=x;i<=n;i++){
		vis[i]=1;
		b[ind]=i;
		pai(ind+1,i+1);
		vis[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>csd>>T;
	while(T--){
		cin>>n>>k;
		ans=2e9;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		pai(1,1);
		cout<<ans<<'\n';
	} 
	return 0;
}
