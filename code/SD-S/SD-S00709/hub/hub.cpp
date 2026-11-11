#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int INF=1e9;
int c,t;
int n,k;
vector<int> e[N];
bool chs[N],vis[N];
void check(int u,int f){
	vis[u]=1;
	for(int v : e[u]){
		if(!chs[v]||v==f){
			continue;
		}
		check(v,u);
	}
}
int dis[N];
int fa[N],dep[N],siz[N],dfn[N],hson[N],top[N],num;
void dfs1(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	for(int v : e[u]){
		if(v==f){
			continue;
		}
		dfs1(v,u);
		siz[u]+=siz[v];
		if(!hson[u]||siz[hson[u]]<siz[v]){
			hson[u]=v;
		}
	}
}
void dfs2(int u,int topu){
	top[u]=topu;
	dfn[u]=++num;
	if(!hson[u]){
		return;
	}
	dfs2(hson[u],topu);
	for(int v : e[u]){
		if(v!=fa[u]&&v!=hson[u]){
			dfs2(v,v);
		}
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]){
			swap(x,y);
		}
		x=fa[top[x]];
	}
	return dep[x]<dep[y] ? x : y;
}
//int dis[N];
//int d1,d2;
//void dia(int u,int f){
//	if(u==1){
//		dis[u]=0;
//		d1=d2=0;
//	}
//	for(int v : e[u]){
//		if(v==f){
//			continue;
//		}
//		dis[v]=dis[u]+1;
//		if(dis[v]>d1){
//			d2=d1;
//			d1=dis[v];
//		}
//		else if(dis[v]>d2){
//			d2=dis[v];
//		}
//	}
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[i].clear();
			fa[i]=dep[i]=siz[i]=dfn[i]=hson[i]=top[i]=num=0;
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,0);
		dfs2(1,1);
		int ans=INF;
			for(int s=0;s<(1<<n);s++){
				int cnt=0;
				for(int i=1;i<=n;i++){
					chs[i]=vis[i]=0;
					if(s&(1<<(i-1))){
						cnt++;
						chs[i]=1;
					}
				}
				if(cnt!=k){
					continue;
				}
				cnt=0;
				for(int i=1;i<=n;i++){
					if(chs[i]&&!vis[i]){
						check(i,i);
						cnt++;
					}
				}
				if(cnt>2){
					continue;
				}
				int res=0;
				for(int i=1;i<=n;i++){
					int d=INF;
					for(int j=1;j<=n;j++){
						if(i==j||!chs[j]){
							continue;
						}
						if(chs[i]&&chs[j]){
							d=0;
							continue;
						}
						int lca=LCA(i,j);
						d=min(d,dep[i]+dep[j]-2*dep[lca]);
					}
					res=max(res,d);
				}
				ans=min(ans,res);
			}
			cout<<ans<<"\n";
	}
	return 0;
}
