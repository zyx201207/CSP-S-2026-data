#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
const int INF=0x3f3f3f3f;
int ans[N],dis[N],vis[N];
vector<int>g[N];
int n,k;
void dijkstra(int u){
	vis[u]=1;
	ll mn=INF;
	int id=-1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(dis[u]+1<dis[v]){
			dis[v]=dis[u]+1;	
		}
	}
	for(int i=1;i<=n;i++){
		if(mn>dis[i]&&vis[i]==0){
			mn=dis[i];
			id=i;
		}
	}
	if(id==-1)return;
	dijkstra(id);
}
int vis2[N],ans2[N];
int mx=0,mn=INF;
void dfs(int now,int day){
	if(now==k+1){
		memset(ans,INF,sizeof(ans));
		mx=0;
		for(int i=1;i<=k;i++){
			for(int i=1;i<=n;i++){
				vis[i]=0,dis[i]=INF;
			}
			dis[ans2[i]]=0;
			dijkstra(ans2[i]);
			for(int j=1;j<=n;j++){
				ans[j]=min(ans[j],dis[j]);
			}
		}
		for(int i=1;i<=n;i++){
			mx=max(mx,ans[i]);
		}
		mn=min(mn,mx);
		return ;
	}
	for(int i=day+1;i<=n;i++){
		if(vis2[i]==0){
			vis2[i]=1;
			ans2[now]=i;
			dfs(now+1,i);
			vis2[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		mx=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
			ans[i]=INF;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0,0);
		
		cout<<mn<<endl;
	}
	return 0;
}