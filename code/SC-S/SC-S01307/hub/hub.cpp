#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int n,k,dep[N],fa[N],tf[N],hvy[N],siz[N],bj[N],bj2[N],ans,cnt;
vector<int>G[N],ve;
void dfs01(int u,int f,int d){
	dep[u]=d,fa[u]=f,siz[u]=1,hvy[u]=0;
	for(int v:G[u]){
		if(v==f)continue;
		dfs01(v,u,d+1),siz[u]+=siz[v];
		if(siz[v]>siz[hvy[u]])hvy[u]=v;
	}
}
void dfs02(int u,int f,int t){
	tf[u]=t;
	if(hvy[u])dfs02(hvy[u],u,t);
	for(int v:G[u]){
		if(v==f||v==hvy[u])continue;
		dfs02(v,u,v);
	}
}
int LCA(int u,int v){
	for(;tf[u]!=tf[v];u=fa[tf[u]])
		if(dep[tf[u]]<dep[tf[v]])swap(u,v);
	return dep[u]<dep[v]?u:v;
}
int Dis(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}
void ddfs(int u){
	bj[u]=1;
	for(int v:G[u])
		if(bj2[v]&&!bj[v])ddfs(v);
}
void solve(){
	if(cnt!=k)return;
	for(int i=1;i<=n;i++)bj[i]=0;
	int tot=0;
	for(int i=1;i<=n;i++){
		if(bj2[i]&&!bj[i])ddfs(i),tot++;
		if(tot>2)return;
	}
	int tt=0;
	for(int i=1;i<=n;i++){
		int t=1e8;
		for(int j:ve)
			t=min(t,Dis(i,j));
		tt=max(tt,t);
	}
	ans=min(ans,tt);
}
void dfs(int x){
	if(x>n){
		solve();
		return ;
	}
	dfs(x+1);
	bj2[x]=1,ve.push_back(x),cnt++;
	dfs(x+1);
	bj2[x]=0,ve.pop_back(),cnt--;
}
void MAIN(){
	cin>>n>>k,ans=1e8,cnt=0;
	for(int i=1;i<=n;i++)G[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u);
	}
	dfs01(1,0,1),dfs02(1,0,1);
	dfs(1);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T>>T;while(T--)MAIN();
	return 0;
}