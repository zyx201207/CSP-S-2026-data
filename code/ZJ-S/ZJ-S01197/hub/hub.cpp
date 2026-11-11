#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
int n,k;
vector<int>e[100010];
bool vis[100010];
bool viss[100010];
queue<int>q;
int f[100010],ans=1e9;
int a[100010];
int fa[100010];
int bfs(){
	memset(viss,0,sizeof(viss));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			q.push(i);
			viss[i]=1;
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i];
			if(viss[y]) continue;
			f[y]=f[x]+1;
			viss[y]=1;
			q.push(y);
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++) sum=max(sum,f[i]);
	return sum;
}
void bfs1(int u){
	q.push(u);
	viss[u]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i];
			if(vis[y]==1&&viss[y]==0){
				viss[y]=1;
				q.push(y);
			}
		}
	}
}
bool check(){
	memset(viss,0,sizeof(viss));
	int sum=0;
	for(int i=1;i<=k;i++){
		if(viss[a[i]]==0){
			sum++;
			if(sum>2) return 0;
			bfs1(a[i]);
		}
	}
	return 1;
}
void dfs(int x,int sum){
	if(sum==k){
		if(check()==0) return ;
		ans=min(ans,bfs());
		return ;
	}
	if(x==n+1) return ;
	vis[x]=1;
	a[sum+1]=x;
	dfs(x+1,sum+1);
	a[sum+1]=0;
	vis[x]=0;
	dfs(x+1,sum);
}
void dfs1(int x,int faa){
	a[x]=a[faa]+1;
	fa[x]=faa;
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		if(y==faa) continue;
		dfs1(y,x);
	}
}
int LCA(int u,int v){
	if(a[u]<a[v]) swap(u,v);
	int sum=0;
	while(a[u]>a[v]){
		u=fa[u];
		sum++;
	}
	while(u!=v){
		u=fa[u];
		v=fa[v];
		sum+=2;
	}
	return sum;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	if(c==7||c==11||c==12){
		while(t--){
			cin>>n>>k;
			int len=0;
			for(int i=1;i<n;i++){
				int u,v; cin>>u>>v;
				e[u].push_back(v);
				e[v].push_back(u);
			}
			dfs1(1,0);
			ans=0;
			for(int i=1;i<=n;i++){
				e[i].clear();
				for(int j=1;j<=n;j++){
					ans=max(ans,LCA(i,j));
				}
			}
			cout<<(ans%4==0?ans/4:ans/4+1)<<endl;
		}
		return 0;
	}
	while(t--){
		cin>>n>>k;
		ans=1e9;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
	return 0;
}