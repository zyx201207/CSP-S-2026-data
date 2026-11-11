#include<bits/stdc++.h>
using namespace std;
const int N=3e2+10;
int c,t,n,k,u,v,ans,vis[N],a[N],cnt,mx,dis[N];
vector<int> b[N]; 
vector<int> now;
queue<int> q;

void dfs2(int u){
	vis[u]=1;
	for(int i=0;i<b[u].size();i++){
		v=b[u][i];
		if(a[v] && vis[v]==0){
			dfs2(v);
		}
	}
}
void check(){
	//第一关：选取数量是否合法 
	if(now.size()!=k)return;
	
	//第二关：是否构成<=2个连通块
	memset(vis,0,sizeof(vis));
	cnt=0;
	for(int i=0;i<now.size();i++){
		u=now[i];
		if(vis[u])continue;
		dfs2(u),cnt++;
	}
	if(cnt>2)return;
	
	//第三关：算通勤半径
	mx=0;
	memset(dis,-1,sizeof(dis));
	for(int i=0;i<now.size();i++){
		q.push(now[i]);
		dis[now[i]]=0;
	}
	
	while(q.size()){
		u=q.front();
		q.pop();
		mx=max(mx,dis[u]);
		
		for(int i=0;i<b[u].size();i++){
			v=b[u][i];
			if(dis[v]==-1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	
	ans=min(ans,mx);
	return;
}
void dfs(int x){
	if(x==n+1){
		check();
		return;
	}
	
	dfs(x+1);
	
	now.push_back(x),a[x]=1;
	dfs(x+1);
	now.pop_back(),a[x]=0;
}
int main(){
	//目标：暴搜的15分 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			b[u].push_back(v);
			b[v].push_back(u);
		}
		
		ans=2e9;
		dfs(1);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)b[i].clear(); 
	}
	return 0;
} 