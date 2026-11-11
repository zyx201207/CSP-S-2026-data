#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,bk[405],vis[405],cun[405],ans=INT_MAX;
vector<int> e[405];
 void dfs(int x,int cu[]){
 	vis[x]=1;
 	int len=e[x].size();
 	for(int i=0;i<len;i++){
 		int to=e[x][i];
 		if(!vis[to]&&cu[to]){
 			dfs(to,cu);
		 }
	 }
	 return;
 }
 int bfs(int x,int cu[]){
 	int dis[35];
 	memset(dis,0,sizeof(dis));
 	queue<pair<int,int> > q;
 	q.push({x,0});
 	while(!q.empty()){
 		pair<int,int> pp=q.front();
 		q.pop();
 		int now=pp.first;
 		int dd=pp.second;
 		if(dis[now]) continue;
 		dis[now]=1;
 		if(cu[now]) return dd;
 		int len=e[now].size();
 		for(int i=0;i<len;i++){
 			int to=e[now][i];
 			if(!dis[to]){
 				q.push({to,dd+1});
			 }
		 }
	 }
 }
void ck(int b[],int cu[]){
	memset(vis,0,sizeof(vis));
	int cnt=0,ma=0;
	for(int i=1;i<=k;i++){
		if(vis[b[i]]==0){
			dfs(b[i],cu);
			cnt++;
		}
		if(cnt>2) return;
	}
	for(int i=1;i<=n;i++){
		if(!cu[i]) ma=max(ma,bfs(i,cu));
	}
	ans=min(ans,ma);
	return;
}
void baol(int dep,int b[],int minn,int cu[]){
	if(dep==k+1) {
		ck(b,cu);
		return;
	}
	for(int i=minn+1;i<=n-k+dep;i++){
		b[dep]=i;
		cu[i]=1;
		baol(dep+1,b,i,cu);
		cu[i]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=INT_MAX;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		baol(1,bk,0,cun);
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) e[i].clear();
	}
}