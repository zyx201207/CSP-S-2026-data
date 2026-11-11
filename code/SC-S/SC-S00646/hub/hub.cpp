#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
int C,T;
int n,k,ans;
vector<int>G[N];
bool vis[N];
int f[N];
int fd(int x){
	if(f[x]==x) return x;
	return f[x]=fd(f[x]);
}
void init(){
	for(int i=1;i<=n;i++) f[i]=i;
}
void mg(int u,int v){
	int x=fd(u),y=fd(v);
	if(x==y) return ;
	f[y]=x;
}
void dfs1(int u,int fa){
	for(int v:G[u]){
		if(v==fa) continue;
		if(vis[u]&&vis[v]) mg(u,v);
		dfs1(v,u);
	}
}
int dfs2(int u,int fa,int st){
	int res=n;
	for(int v:G[u]){
		if(v==fa) continue;
		if(vis[v]) return st;
	}
	for(int v:G[u]){
		if(v==fa) continue;
		res=min(res,dfs2(v,u,st+1));
	}
	return res;
}
void check(){
	init();
	dfs1(1,0);
	int gt1=0,gt2=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(gt1==0) gt1=fd(i); 
			else if(gt1==fd(i)) continue;
			else if(gt2==0) gt2=fd(i);
			else if(gt2!=fd(i)) return ;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int y=dfs2(i,0,1);
		res=max(res,y);
	}
	if(res<ans){
		ans=res;
//		cout<<res<<'\n';
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';
//		cout<<'\n';
	}
}
void way(int u,int st){
	if(u>n){
		if(st!=k) return ;
		check();
		return ;
	}
	if(st<k){
		vis[u]=1;way(u+1,st+1);
	}
	vis[u]=0;way(u+1,st);
}
void solve(){
	cin>>n>>k;ans=n;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	way(1,0);cout<<ans<<'\n';
}
/*
int trie[N][30],sum[N];
int tot;
int cal(char x){
	return x-'a';
}
void insert(string s){
	int pos=0;
	for(int i=0;i<s.size();i++){
		if(!trie[pos][cal(s[i])]) trie[pos][cal(s[i])]=tot;
		pos=trie[pos][cal(s[i])];sum[pos]++;
	}
}
int query(string s){
	int pos=0;
	for(int i=0;i<s.size();i++){
		if(!trie[pos][cal(s[i])]) return 0;
		pos=trie[pos][cal(s[i])];
	}
	return sum[pos];
}
I love trie.
*/
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--) solve();
	return 0;
}