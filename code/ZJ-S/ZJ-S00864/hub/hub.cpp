#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans=1e9,a[2100000],d[2100000],fa[2100000],dis[2100000],dmn[2100000];
vector<int> g[2100000];
bool ish[2100000],vis[2100000];
priority_queue<pair<int,int> > q;
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void dij(int u){
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	dis[u]=0;
	q.push((pair<int,int>){-dis[u],u});
	while(!q.empty()){
		pair<int,int> x=q.top();
		q.pop();
		int u=x.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push((pair<int,int>){-dis[v],v});
			}
		}
	} 
	for(int i=1;i<=n;i++){
		dmn[i]=min(dmn[i],dis[i]);
	}
}
void cheak2(){
	for(int i=1;i<=n;i++){
		dmn[i]=1e9;
//		cout<<d[i]<<" ";
	} 
//	cout<<"\n";
	for(int i=1;i<=n;i++){
		if(d[i]) dij(i);
	}
	int Max=0;
	for(int i=1;i<=n;i++){
//		cout<<dmn[i]<<" ";
		Max=max(Max,dmn[i]);
	}
//	cout<<Max<<" ";
//	cout<<"\n";
	ans=min(ans,Max);
}
void cheak(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		ish[i]=0;
	}
	for(int i=1;i<=n;i++){
		if(d[i]){
			for(int j=0;j<g[i].size();j++){
				int v=g[i][j];
				if(d[v]){
//					cout<<i<<","<<v<<"|";
					int x=find(i);
					int y=find(v);
					if(x!=y){
						fa[y]=x;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(d[i]){
			ish[find(i)]=1;
//			cout<<i<<","<<find(i)<<" ";
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(d[i]&&ish[i]){
			cnt++;
		}
	}
	if(cnt<=2){
		cheak2(); 
	}
//	cout<<"\n";
}
void dfs(int step){
	if(step>k){
		cheak();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			d[i]=1;
			dfs(step+1);
			d[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		} 
		ans=1e9;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<"\n";
//		cout<<"________________________\n";
	}
	return 0;
} 
