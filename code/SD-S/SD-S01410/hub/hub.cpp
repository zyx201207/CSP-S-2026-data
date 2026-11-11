#include<bits/stdc++.h>
using namespace std;
const int N=15;
typedef pair<int,int> PII;
int test,_,n,m,f[N],dist[N],ans;
vector<int>v[N];
bool vis[N];
int find(int x){
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
int dijkstra(int st){
	memset(dist,0x3f,sizeof dist);
	dist[st]=0;
	queue<PII>q;
	q.push({0,st});
	for(;!q.empty();){
		PII tt=q.front();q.pop();
		int t=tt.second;
		if(vis[t])return dist[t];
		for(int i:v[t]){
			if(dist[i]>dist[t]+1){
				dist[i]=dist[t]+1;
				q.push({dist[i],i});
			}
		}
	}
}
void dfs(int cnt,int now){
	if(cnt>m)return;
	if(now==n+1){
		if(cnt<m)return;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int j:v[i]){
					if(!vis[j])continue;
					int px=find(i),py=find(j);
					f[px]=py;
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i])continue;
			if(i==find(i))cnt++;
		}
		if(cnt>2)return;
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,dijkstra(i));
		}
		ans=min(ans,mx);
		return;
	}
	vis[now]=1;
	dfs(cnt+1,now+1);
	vis[now]=0;
	dfs(cnt,now+1);
	return;
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		v[i].clear();
		vis[i]=0;
	}
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=2e9;
	dfs(0,1);
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&test,&_);
	for(;_--;){
		solve();
	}
	return 0;
}
