#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int C,T,n,m,k,ans=1e9;
int a[N],sa[N],q[N];
vector<int> g[N];
bool vis[N];
int dis[N];

void bj(int u,int fu){
	if(!a[u]) return;
	vis[u]=1;
	for(auto v:g[u]){
		if(v!=fu){
			bj(v,u);
		}
	}
}

int bfs(int x){
	queue<int> pq;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	pq.push(x);
	dis[x]=0;
//	cout<<x<<endl;
	while(!pq.empty()){
		int u=pq.front();
		pq.pop();
		vis[u]=1;
		for(auto v:g[u]){
			if(!vis[v]){
				dis[v]=dis[u]+1;
				if(a[v]){
					return dis[v];
				}
				pq.push(v);
			}
		}
	}
	return 1e18;
}

int check(){
	int ans=0,cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(!vis[i]&&a[i]){
			cnt++;
			if(cnt>2) return 1e18;
			bj(i,0);
		}
	}
	for(int i=1;i<=n;i++){
		if(!a[i]){
			ans=max(ans,bfs(i));
		}
	}
	return ans;
}

void dfs(int step,int cnt){
	if(step=n+1){
		if(cnt==k){
			ans=min(ans,check());
		}
		return ;
	}
	a[step]=1;
	if(cnt<=k) dfs(step+1,cnt+1);
	a[step]=0;
	dfs(step+1,cnt);
}

void calc(){
	cin>>n>>k;
	for(int i=1,u,v;i<=n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<endl;
}


signed main(){
//	freopen("hub.in","r",stdin);hao xiang dianfenshu
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>C>>T;
	while(T--){
		calc();
	}
	return 0;
}
