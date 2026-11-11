#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+15;
int _,T,n,k,dep[maxn],anc[20][maxn],fa[maxn];
vector<int> g[maxn];
int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
void dfs(int u,int fth){
	anc[0][u]=fth;
	dep[u]=dep[fth]+1;
	for(int i=1;i<=4;i++){
		anc[i][u]=anc[i-1][anc[i-1][u]];
	}
	for(int v:g[u]) if(v!=fth) dfs(v,u);
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=4;i>=0;i--){
		if(dep[anc[i][u]]>=dep[v]){
			u=anc[i][u];
		}
	}
	if(u==v) return u;
	for(int i=4;i>=0;i--){
		if(anc[i][u]!=anc[i][v]){
			u=anc[i][u];
			v=anc[i][v];
		}
	}
	return anc[0][u];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>_>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		int ans=1e9;
		for(int s=0;s<1<<n;s++){
			if(__builtin_popcount(s)!=k) continue;
			for(int i=1;i<=n;i++) fa[i]=i;
			for(int i=1;i<=n;i++){
				if(s>>(i-1)&1){
					for(int j:g[i]){
						if(s>>(j-1)&1){
							fa[fnd(i)]=fnd(j);
						}
					}
				}
			}
			set<int> st;
			for(int i=1;i<=n;i++){
				if(s>>(i-1)&1){
					st.insert(fnd(i));
				}
			}
			if((int)st.size()>2){
				continue;
			}
			int val=0;
			for(int i=1;i<=n;i++){
				int d=1e9;
				for(int j=1;j<=n;j++){
					if(s>>(j-1)&1){
						d=min(d,dis(i,j));
					}
				}
				val=max(val,d);
			}
			ans=min(ans,val);
		}
		for(int i=1;i<=n;i++){
			dep[i]=fa[i]=0;
			for(int j=0;j<=10;j++) anc[j][i]=0;
			g[i].clear();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
