#include<bits/stdc++.h>
using namespace std;
const int N=110;
int C,T,n,k,s,S,dis[N][N];
vector<int> G[N];
bool vis[N];
void dfs(int u,int fa){
	for(int v:G[u]){
		if(v!=fa){
			dis[s][v]=dis[s][u]+1;
			dfs(v,u);
		}
	}
}
void dd(int u){
	vis[u]=1;
	for(int v:G[u]){
		if(!vis[v]&&(S>>v&1)){
			dd(v);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;++i){
			G[i].clear();
		}
		for(int i=1,u,v;i<n;++i){
			scanf("%d%d",&u,&v);
			G[u-1].emplace_back(v-1);
			G[v-1].emplace_back(u-1);
		}
		for(s=0;s<n;++s){
			dis[s][s]=0;
			dfs(s,0);
		}
		int ans=1e9;
		for(S=0;S<(1<<n);++S){
			if(__builtin_popcount(S)==k){
				for(int i=0;i<n;++i){
					vis[i]=0;
				}
				int cnt=0;
				for(int i=0;i<n;++i){
					if((S>>i&1)&&!vis[i]){
						cnt++;
						dd(i);
					}
				}
//				if(S==262) printf("cnt=%d\n",cnt);
				if(cnt>2) continue;
				int mx=0;
				for(int i=0;i<n;++i){
					int mn=1e9;
					for(int j=0;j<n;++j){
						if(S>>j&1){
							mn=min(mn,dis[i][j]);
//							if(S==262&&i==9) printf("defjei:%d %d\n",j,mn);
						}
					}
//					if(S==262&&i==9) printf("defjei:%d\n",mn);
					mx=max(mx,mn);
				}
//				printf("S=%d %d\n",S,mx);
				ans=min(ans,mx);
			}
		}
		printf("%d\n",ans);
	}
}