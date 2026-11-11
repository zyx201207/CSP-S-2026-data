#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;

struct Node{
	int v,pre;
}edge[N];

int head[N],node;
ll dis[N];
int n,k;
vector<int> dottt;
bool f[N];
bool vis[N];
bool visss[N];
ll ans;

void add(int u,int v){
	edge[++node].v=v;
	edge[node].pre=head[u];
	head[u]=node;
}

void dfsss(int u){
	for(int i=head[u];i;i=edge[i].pre){
		int v=edge[i].v;
		if(visss[v]==0&&f[v]){
			visss[v]=1;
			dfsss(v);
		}
	}
}

ll dij_pr(){
	for(int i=1;i<=n;i++) dis[i]=inf,vis[i]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	for(int i=0;i<dottt.size();i++){
		dis[dottt[i]]=0;
		q.push({0,dottt[i]});
	}
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].pre){
			int v=edge[i].v;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				q.push({dis[v],v});
			}
		}
	}
	ll mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,dis[i]);
	}
	return mx;
}

void dfs(int i){
	if(i>k){
		for(int j=1;j<=n;j++) visss[j]=0;
		int cc=0;
		for(int j=1;j<dottt.size();j++){
			if(!visss[dottt[j]]){
				cc++;
				visss[dottt[j]]=1;
				dfsss(dottt[j]);
			}
		}
		if(cc<=2){
			ans=min(ans,dij_pr());
		}
		return;
	}
	for(int j=1;j<=n;j++){
		if(!f[j]){
			f[j]=1;
			dottt.push_back(j);
			dfs(i+1);
			f[j]=0;
			dottt.pop_back();
		}
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		node=0;
		memset(head,0,sizeof head);
		ans=inf;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}