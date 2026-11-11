#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,k;
vector<int> g[N];
int dis[1010][1010],f[1010];
void dfs(int u,int fa,int t){
	for(int v:g[u]){
		if(v==fa) continue;
		dis[t][v]=dis[t][u]+1;
		dfs(v,u,t);
	}
}
int fd(int x){
	return (x==f[x] ? x : f[x]=fd(f[x]));
}
void solve(){
	int ans=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=0;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) dfs(i,0,i);
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k) continue;
		for(int j=1;j<=n;j++) f[j]=j;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				for(int k:g[j]){
					if(i&(1<<(k-1))){
						int fu=fd(j),fv=fd(k);
						if(fu!=fv) f[fu]=fv;
					}
				}
			}
		}
		int res=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				if(f[j]==j) res++;
			} 
		}
		if(res>2) continue;
		res=-1;
		for(int j=1;j<=n;j++){
			int tmp=1e9;
			for(int k=1;k<=n;k++){
				if(i&(1<<(k-1))){
					tmp=min(tmp,dis[j][k]);
				}
			}
			res=max(tmp,res);
		} 
		ans=min(res,ans);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
}

