#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge{
	int to;
	int nxt; 
}a[4010];

int dep[4010];
int fa[4010][35];
int head[4010];
int c[4010];
int vis[4010];
int flag[4010];
int tt;
int n;
int k;
int ans;

void add_edge(int u, int v){
	
	a[++tt]={v,head[u]};
	head[u]=tt;
	
	return ;
}

void init(){
	
	for(int i=1;i<=30;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
		}
	}
	
	return ;
}

int LCA(int x, int y){
	
	if(dep[x]<dep[y])swap(x,y);
	
	for(int i=30;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	}
	
	if(x==y)return x;
	
	for(int i=30;i>=0;i--){
		if(fa[x][i]!=fa[y][i])x=fa[x][i], y=fa[y][i];
	}
	
	return fa[x][0];
}

void bfs(int s){
	
	queue<int> q;
	q.push(s);
	vis[s]=1;
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=a[i].nxt){
			int v=a[i].to;
			if(vis[v])continue;
			if(!flag[v])continue;
			q.push(v);
			vis[v]=1;
		}
	}
	
	return ;
}

void dfs(int u, int f){
	
	dep[u]=dep[f]+1;
	fa[u][0]=f;
	
	for(int i=head[u];~i;i=a[i].nxt){
		int v=a[i].to;
		if(v==f)continue;
		dfs(v,u);
	}
	
	return ;
}

void dfs(int i){
	
	if(i>k){
		int cnt=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=k;i++){
			if(!vis[c[i]])bfs(c[i]), cnt++;
		}
		if(cnt>2)return ;
		int ma=LLONG_MIN;
		for(int i=1;i<=n;i++){
			int mn=LLONG_MAX;
			for(int j=1;j<=k;j++){
				int f=LCA(i,c[j]);
				mn=min(mn,dep[i]+dep[c[j]]-dep[f]*2);
			}
			ma=max(ma,mn);
		}
		ans=min(ans,ma);
		return ;
	}
	
	for(int j=c[i-1]+1;j<=n;j++){
		c[i]=j;
		flag[j]=1;
		dfs(i+1);
		c[i]=0;
		flag[j]=0;
	}
	
	return ;
}

void solve(){
	
	tt=0;
	ans=LLONG_MAX;
	memset(head,-1,sizeof head);
	
	cin >> n >> k;
	
	for(int i=1;i<n;i++){
		int u, v;
		cin >> u >> v;
		add_edge(u,v);
		add_edge(v,u);
	}
	
	dfs(1,0);
	init();
	
	dfs(1);
	
	cout << ans << endl;
	
	return ;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int c, t;
	cin >> c >> t;
	
	while(t--){
		solve();
	}
	
	return 0;
}

