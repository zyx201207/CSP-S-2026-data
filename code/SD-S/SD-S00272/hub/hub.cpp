#include<bits\stdc++.h>
using namespace std;
const int N=1e6+7;
int c,T,n,k;
int vis[N],vi[N],dis[N];
vector<int>g[N];
void dfs(int u){
	vi[u]=1;
	for(auto v:g[u]){
		if(!vis[v]||vi[v])continue;
		dfs(v);
	}
}
int bfs(){
	int sum=0;
	queue<int>q;
	for(int i=1;i<=n;i++)if(vis[i]){q.push(i);dis[i]=0;}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++)sum=max(sum,dis[i]);
	return sum;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		int ans=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int id=3;id<(1<<n);id++){
			int cnt=0;
			for(int i=1;i<=n;i++){
				vis[i]=vi[i]=0;
				dis[i]=1e9;
			}
			for(int j=0;j<n;j++){
				if(id&(1<<j)){
					vis[j+1]=1;
					cnt++;
				}
			}
			if(cnt!=k)continue;
			cnt=0;
			for(int j=0;j<n;j++){
				if((id&(1<<j))&&(!vi[j+1])){
					dfs(j+1);
					cnt++;
				}
			}
			if(cnt>2)continue;
			//for(int i=1;i<=n;i++)if(vis[i])cout<<i<<" ";
			//cout<<"\n";
			ans=min(ans,bfs());
		}
		cout<<ans<<"\n";
	}
	return 0;
}
