#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=15;
int n,k;
vector<int> T[maxn];
int vis[maxn],vvis[maxn],dep[maxn];
void clear(){
	for(int i=1;i<=n;i++) T[i].clear();
}
void dfs(int u,int f){
	vvis[u]=1;
	for(int i=0;i<T[u].size();i++){
		int v=T[u][i];
		if(v==f||!vis[v]) continue;
		dfs(v,u);
	}
}
void dfss(int u,int f,int d){
	dep[u]=d;
	for(int i=0;i<T[u].size();i++){
		int v=T[u][i];
		if(v==f) continue;
		dfss(v,u,d+1);
	}
}
void mymain(){
	clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		T[u].push_back(v),T[v].push_back(u);
	}
	int ans=n+1;
	for(int msk=1;msk<(1<<n);msk++){
		for(int i=1;i<=n;i++) vis[i]=(msk>>(i-1))&1;
		int s=0;
		for(int i=1;i<=n;i++) s+=vis[i];
		if(s!=k) continue;
		for(int i=1;i<=n;i++) vvis[i]=0;
		int cnt=0;
		for(int i=1;i<=n;i++) if(vis[i]&&!vvis[i]) dfs(i,0),cnt++;
		if(cnt>2) continue;
		int res=0;
		for(int i=1;i<=n;i++){
			dfss(i,0,0);
			int d=n+1;
			for(int j=1;j<=n;j++) if(vis[j]) d=min(d,dep[j]);
			res=max(res,d);
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0),cout.tie(0);
	int Typ,_;
	cin>>Typ>>_;
	while(_--) mymain();
	return 0;
}