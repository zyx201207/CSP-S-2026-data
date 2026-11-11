#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int c,T,n,k,dis[15][15];
vector<int>e[N];
void dfs(int s,int u,int fa,int d){
	dis[s][u]=d;
	for(int v:e[u]){
		if(v==fa)continue;
		dfs(s,v,u,d+1);
	}
}
int f[15];
int find(int x){
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=1;i<n;++i){
			int u,v;cin>>u>>v;
			e[u].push_back(v);e[v].push_back(u);
		}
		if(n<=10){
			int ans=1e9;
			for(int i=1;i<=n;++i)dfs(i,i,0,0);
			for(int i=1;i<(1<<n);++i){
				if(__builtin_popcount(i)!=k)continue;
				for(int j=1;j<=n;++j)f[j]=j;
				for(int j=1;j<=n;++j){
					for(int k:e[j]){
						if((i>>j-1)&1){
							if((i>>k-1)&1){
								if(find(j)!=find(k)){
									f[find(j)]=find(k);
								}
							}
						}
					}
				}
				int cnt=0;
				for(int j=1;j<=n;++j){
					if((i>>j-1)&1){
						if(j==find(j))++cnt;
					}
				}
				if(cnt>2)continue;
				int s=0;
				for(int j=1;j<=n;++j){
					int d=1e9;
					for(int k=1;k<=n;++k){
						if((i>>k-1)&1){
							d=min(d,dis[j][k]);
						}
					}
					s=max(s,d);
				}
				ans=min(ans,s);
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
