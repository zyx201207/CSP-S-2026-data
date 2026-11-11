#include<bits/stdc++.h>
using namespace std;
//#define int long long
int c;
int n,m;
int dep[1000005],siz[1000005];
int top[1000005],sn[1000005],fa[1000005];
vector<int>tmp[1000005],e[1000005];
int vis[1000005];
int ppct(int x){
	int cnt=0;
	while(x){
		cnt+=(x&1);
		x>>=1;
	}
	return cnt;
}
void dfs(int x){
	vis[x]=1;
	siz[x]=1;
	for(int k:tmp[x]){
		if(!vis[k]){
			dep[k]=dep[x]+1;
			fa[k]=x;e[x].push_back(k);
			dfs(k);
			siz[x]+=siz[k];
		}
	}
	int mx=0;
	for(int k:e[x]){
		if(siz[k]>mx){
			mx=siz[k];
			sn[x]=k;
		}
	}
}
void dfs1(int x,int tp){
	if(x==0)return;
	top[x]=tp;
	dfs1(sn[x],tp);
	for(int k:e[x]){
		if(k==sn[x])continue;
		dfs1(k,k);
	}
}
void dfs2(int x){
	vis[x]=2;
	for(int k:tmp[x])if(vis[k]==1)dfs2(k);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])return x;
	return y;
}
int diss(int x,int y){
	int tmpp=dep[lca(x,y)];
	int ans=dep[x]+dep[y]-2*tmpp;
	return ans;
}
void solve(){
	for(int i=1;i<=n;i++){
		e[i].clear();tmp[i].clear();
		dep[i]=0;vis[i]=0;siz[i]=0;top[i]=0;sn[i]=0;fa[i]=0;
	}
	cin >> n >> m;
	for(int i=1;i<n;i++){
		int u,v;cin >> u >> v;
		tmp[u].push_back(v);
		tmp[v].push_back(u); 
	}
	dep[1]=1;
	dfs(1);dfs1(1,1);
	int ans=998244353;
	for(int S=1;S<(1<<(n+1));S++){
		if(ppct(S>>1)!=m)continue;
		for(int i=1;i<=n;i++){
			vis[i]=0;
			if((1<<i)&S)vis[i]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				dfs2(i);cnt++;
			}
		}
		if(cnt>2)continue;
		
		int mx=0;
		for(int i=1;i<=n;i++){
			int mn=998244353;
			for(int j=1;j<=n;j++){
				if(vis[j])mn=min(mn,diss(i,j));
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
	}
	cout << ans << "\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> c >> t;
	while(t--){
		if(c<=3)solve();
//		else if(c==7)sol1();
//		else if(c==11||c==12)sol2();
	}
	return 0;
}
