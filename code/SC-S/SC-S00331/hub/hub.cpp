#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>e[100010];
//int f[100010],l[100010],T[100010],dep[100010];
//inline void dfs(int x,int fa){
//	l[x]=f[x]=0;
//	for(int i=0;i<e[x].size();i++){
//		if(e[x][i]==fa) continue;
//		dep[e[x][i]]=dep[x]+1; 
//		dfs(e[x][i],x);
//		l[x]=max(l[x],l[e[x][i]]);
//		if(l[e[x][i]]>=d) f[x]=1;
//	}
//	l[x]++;
//	for(int i=0;i<e[x].size();i++){
//		if(e[x][i]==fa) continue;
//		f[x]+=f[e[x][i]];
//	}
//	T[f[x]]=min(T[f[x]],dep[x]);
//}
//inline bool check(int d){
//	::d=d;
//	for(int i=1;i<=n;i++){
//		dfs(i,0);
//		
//	}
//}
int T[100010],vis[100010];
inline void dfs(int x){
	if(!T[x]) return;
	vis[x]=1;
	for(int i=0;i<e[x].size();i++){
		if(vis[e[x][i]]) continue;
		dfs(e[x][i]);
	}
}
int d[100010];
inline void dfs2(int x,int fa){
	if(T[x]){
		d[x]=0;
		return;
	}
	else d[x]=1e9;
	for(int i=0;i<e[x].size();i++){
		if(e[x][i]==fa) continue;
		dfs2(e[x][i],x);
		d[x]=min(d[x],d[e[x][i]]+1);
	}
}
inline void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	int ans=1e9;
	for(int s=0;s<(1<<n);s++){
		if(__builtin_popcount(s)>k) continue;
		for(int i=0;i<n;i++) if(s&(1<<i)) T[i+1]=1,vis[i+1]=0;else T[i+1]=vis[i+1]=0;
		int cnt=0;
		for(int i=1;i<=n;i++) if(!vis[i] && T[i]) dfs(i),cnt++;
		if(cnt>2) continue;
		int mxd=0;
		for(int i=1;i<=n;i++) dfs2(i,0),mxd=max(mxd,d[i]);
		ans=min(ans,mxd);
	}
	cout<<ans<<"\n";
//	int l=0,r=n,ans=n,mid;
//	while(l<=r)
//		if(check(mid=l+r>>1)) r=mid-1,ans=mid;
//		else l=mid+1;
//	cout<<ans<<"\n";
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int FW_number,t;
	cin>>FW_number>>t;
	while(t--) solve();
	return 0;
}