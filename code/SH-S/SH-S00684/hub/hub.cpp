#include<bits/stdc++.h>
using namespace std;
const int N = 100+5;
int c,t,n,k,dis[N][N],vis[N],ch[N],ans=INT_MAX;
vector<int> g[N];
inline void dfst(int x,int fa,int t){
	dis[t][x]=dis[t][fa]+1;
	for(auto u:g[x]){
		if(u==fa) continue;
		dfst(u,x,t);
	}
}
inline void dfsc(int x){
	vis[x]=1;
	for(auto u:g[x]){
		if(vis[u]||!ch[u]) continue;
		dfsc(u);
	}
}
inline void dfs(int p,int cnt){
	if(cnt>k) return;
	if(p>n){
		if(cnt<k) return;
		int cnt=0;
		for(int i=1;i<=n;++i) vis[i]=0;
		for(int i=1;i<=n;++i){
			if(!ch[i]) continue;
			if(!vis[i]){
				cnt++;
				dfsc(i);
			}
		}
		if(cnt>2) return;
		int res=0,tmp;
		for(int i=1;i<=n;++i){
			tmp=INT_MAX;
			for(int j=1;j<=n;++j){
				if(!ch[j]) continue;
				tmp=min(tmp,dis[i][j]);
			}
			res=max(res,tmp);
		}
		ans=min(ans,res);
		return;
	} 
	ch[p]=0; dfs(p+1,cnt);
	ch[p]=1; dfs(p+1,cnt+1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;++i) dis[i][0]=-1,dfst(i,0,i);
		dfs(1,0);
		for(int i=1;i<=n;++i){
			g[i].clear();
			for(int j=1;j<=n;++j) dis[i][j]=0;
		}
		cout<<ans<<"\n"; ans=INT_MAX;
	}
	return 0;
}
