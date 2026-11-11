#include<bits/stdc++.h>
#define pii pair<int,int> 
#define int long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e6+86;
typedef long long ll;
const int INF=1e18;
int w[N];
vector<pii> g[N];
int tot=0;
bool issuan[N];
vector<int> dist(N+86,INF);
vector<bool> vis(N+86,0);
vector<int> node;
int ans[N];
void dij(int s){
	for(auto v:node){
		dist[v]=INF;
		vis[v]=0;
	}
	node.clear();
	priority_queue<pii,vector<pii>,greater<pii> > q;
	dist[s]=0;
	q.push({0,s});
	node.push_back(s);
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto tmp:g[u]){
			int d=tmp.second;
			int v=tmp.first;
			if(dist[u]+d<=dist[v]){
				dist[v]=dist[u]+d;
				node.push_back(v);
				q.push({dist[v],v});
			}
		}
	}
}
map<int,vector<pii> > mp;
signed main(){
	IOS;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	tot=m;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		vector<int> ids;
		for(int j=1;j<=k;j++){
			int id,wi;cin>>id>>wi;
			++tot;
			ids.push_back(tot);
			g[tot].push_back({id,wi});
			g[id].push_back({tot,wi});
		}
		for(int j=1;j<ids.size();j++){
			g[ids[j]].push_back({ids[j-1],0});
			g[ids[j-1]].push_back({ids[j],0});
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;cin>>s>>e;
		mp[s].push_back({e,i});
	}
	for(auto tmp:mp){
		int s=tmp.first;
		dij(s);
		vector<pii> es=tmp.second;
		for(auto e:es){
			ans[e.second]=dist[e.first]+w[s]+w[e.first];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
}

