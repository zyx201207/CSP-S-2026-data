#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1011;
int c,q,n,k,fa[N];
vector<int> son[N];
bool up[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	fa[xx]=yy;
}
int ans=10000000;
bool vis[N];
int dfs(int x){
	if(up[x]) return 0;
	vis[x]=1;
	int cur=0;
	for(auto v:son[x]){
		cur=min(cur,dfs(v)+1);
	}
	return cur;
}
void solve(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		if(up[i]){
			for(auto v:son[i]){
				if(up[v]) merge(i,v);
			}
		}
	}
	int num=0;
	for(int i=1;i<=n;i++) if(up[i]&&fa[i]==i) num++;
	if(num>2) return ;
	int nowmax=0;
	for(int i=1;i<=n;i++){
		if(!up[i]) {
			for(int j=1;j<=n;j++) vis[j]=0;
			nowmax=max(nowmax,dfs(i));
		}
	}
	ans=min(ans,nowmax);
}
void DFS(int x,int k){
	if(x==n+1&&k==0){
		solve();
	}
	up[x]=0;
	DFS(x+1,k);
	up[x]=1;
	DFS(x+1,k-1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)son[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			son[u].push_back(v);
			son[v].push_back(u);
		}
		if(k==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					up[i]=1,up[j]=1;
					solve();
					up[i]=0,up[j]=0;
				}
			}
		} 
		DFS(1,k);
	}
}
