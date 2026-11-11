#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> G[5005];
int x[5005];
int dis[5005],cnt[5005],ans;
bool vis[5005];
int n,d;
void bfs(int st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	queue<int> q;
	q.push(st);cnt[st]=1;vis[st]=1;dis[st]=0;
	while(q.size()){
		int p=q.front();q.pop();
		for(int v:G[p]){
			if(vis[v]&&dis[v]==dis[p]+1) cnt[v]++;
			else if(!vis[v]) dis[v]=dis[p]+1,q.push(v),cnt[v]=1,vis[v]=1;
		}
	}
	for(int i=1;i<=n;i++) ans+=(cnt[i]==2);
}
void solve(){
	cin>>n>>d; ans=0;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++){cin>>x[i];}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d) G[i].push_back(j),G[j].push_back(i);
		}
	}
	for(int i=1;i<=n;i++) bfs(i);
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
