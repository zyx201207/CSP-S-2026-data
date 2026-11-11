#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
vector<int> G[200005];
int f[200005],dep[200005];
bool vis[200005];
int mask;
void dfs(int u){
	vis[u]=1;
	for(int v:G[u]){
		if(vis[v]) continue;
		if((mask>>(v-1))&1){
			dfs(v);
		}
	}
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;f[u]=fa;
	for(int v:G[u]){
		if(v==fa||v==u) continue;
		dfs(v,u);
	}
}
int LCA(int x,int y){
	while(x!=y){
		if(dep[x]<dep[y]) swap(x,y);
		x=f[x];
	}
	return x;
}
int fa[200005],tmp[200005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		if(c>=13&&c<=14){
			int m=n/2;
			cout<<(m-k+3)/4+1<<"\n";
			continue;
		}
		for(int i=1; i<=n; i++) G[i].clear();
		for(int i=1; i<n; i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(k==n){
			cout<<"0\n";
			continue;
		}
		if(k>=n-2){
			cout<<1<<"\n";
			continue;
		}
		int minn=n;
		dfs(1,0);
		for(mask=0;mask<(1<<n);mask++){
			if(__builtin_popcount(mask)!=k) continue;
			for(int i=1; i<=n; i++) fa[i]=i,vis[i]=0;
			int cnt=0;
			for(int i=0;i<n;i++){
				if(!((mask>>i)&1)) continue;
				if(!vis[i+1]){
					cnt++;
					dfs(i+1);
				}
			}
			if(cnt>2) continue;
			for(int i=1; i<=n; i++) tmp[i]=0x3f3f3f3f;
			for(int j=0;j<n;j++){
				if(!((mask>>j)&1)) continue;
				for(int i=1; i<=n; i++){
					tmp[i]=min(tmp[i],dep[i]+dep[j+1]-2*dep[LCA(i,j+1)]);
				}
			}
			int maxx=0;
			for(int i=1; i<=n; i++){
				if((mask>>(i-1))&1) continue; 
				maxx=max(maxx,tmp[i]);
			}
			minn=min(minn,maxx);
		}
		cout<<minn<<"\n";
	}
	return 0;
}
