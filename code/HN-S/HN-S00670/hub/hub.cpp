#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
int c,T;
vector<int>G[maxn];
bool vis[maxn];
int n,k;
bool vis2[maxn];
int ltk=0;
void dfs(int x){
	if(vis2[x]) return ;
	vis2[x]=true;
	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if(!vis[v]) continue;
		dfs(v);
	}
	return ;
}
void work(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int maxx=(1<<n)-1;
	int ans=1e9;
	for(int mask=0;mask<=maxx;mask++){
		int cnt=0;
		ltk=0;
		for(int i=0;i<n;i++){
			vis2[i+1]=false;
			vis[i+1]=false;
			if((mask>>i)&1){
				cnt++;
				vis[i+1]=true;
			}
		}
		if(cnt!=k) continue;
		for(int i=1;i<=n;i++){
			if(!vis2[i]&&vis[i]){
				ltk++;
				dfs(i);
			}
		}
		if(ltk>2) continue;
		int d=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int minn=1e9;
			vector<int>dis(n+1,n+1);
			queue<int>q;
			q.push(i);
			dis[i]=0;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=0;i<G[u].size();i++){
					int v=G[u][i];
					if(dis[v]>dis[u]+1){
						dis[v]=dis[u]+1;
						q.push(v);
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(vis[j]) minn=min(minn,dis[j]);
			}
			d=max(d,minn);
		} 
		ans=min(ans,d);
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) work();
	return 0;
}
