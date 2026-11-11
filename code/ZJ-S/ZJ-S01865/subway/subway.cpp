//fencentu?
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<int> w;
vector<int> a[510];
vector<int> t[510];
vector<int> k;
vector<vector<pair<int,int>>> adj;
vector<vector<int>> sta;
vector<bool> vis;
vector<int> dis;
void spfa(int st){
	priority_queue<pair<int,int>> qu;
	vis.resize(n*m+5);
	dis.resize(n*m+5);
	for (int i=1; i<=n*m+2; i++){
		dis[i]=INF;
		vis[i]=0;
	}
	qu.push({0,st});
	vis[st]=1;
	dis[st]=0;
	while (qu.size()){
		auto node=qu.top();
		qu.pop();
		int u=node.second;
		vis[u]=0;
		for (const auto &v:adj[u]){
			if (dis[u]+v.second<dis[v.first] && !vis[v.first]){
				dis[v.first]=dis[u]+v.second;
				vis[v.first]=1;
				qu.push({-dis[v.first],v.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	adj.resize(n*m+5);
	vis.resize(n*m+5);
	dis.resize(n*m+5);
	w.resize(m+1);
	k.resize(n+1);
	sta.resize(m+1);
	for (int i=1; i<=m; i++){
		cin>>w[i];
	}
	for (int i=1; i<=n; i++){
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for (int j=1; j<=2*k[i]; j++){
			if (j&1){
				cin>>a[i][j/2+1];
				sta[a[i][j/2+1]].push_back(i);
			}else{
				cin>>t[i][j/2];
			}
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<k[i]; j++){
			adj[(i-1)*m+a[i][j]].push_back({(i-1)*m+a[i][j+1],0});
			adj[(i-1)*m+a[i][j+1]].push_back({(i-1)*m+a[i][j],0});
		}
		for (int j=1; j<=k[i]; j++){
			if (sta[a[i][j]].size()!=1){
				for (auto &K:sta[a[i][j]]){
					if (K==i){
						break;
					}
					for (int ii=1; ii<=k[i]; ii++){
						if (ii==a[i][j]){
							adj[(i-1)*m+a[i][j]].push_back({(K-1)*m+ii,t[i][j]+t[K][ii]});
							adj[(K-1)*m+ii].push_back({(i-1)*m+a[i][j],t[i][j]+t[K][ii]});
						}
					}
				}
			}
		}
	}
//	for (int i=1; i<=n*m; i++){
//		cout<<i<<":";
//		for (auto &x:adj[i]){
//			cout<<x.first<<" "<<x.second<<",";
//		}
//		cout<<"\n";
//	}
	for (int i=1; i<=Q; i++){
		int st,ed;
		cin>>st>>ed;
		int ans=INF;
		for (int j=1; j<=n; j++){
			for (int abcde=1; abcde<=k[i]; abcde++){
				if (st==a[j][abcde]){
					for (int K=1; K<=n; K++){
						for (int ab=1; ab<=k[K]; ab++){
							if (a[K][ab]==ed){
								int ans1=INF;
								adj[n*m+1].push_back({a[j][abcde],t[1][abcde]});
								adj[(K-1)*m+ed].push_back({n*m+2,t[K][ab]});
								spfa(n*m+1);
								ans1=min(ans1,dis[n*m+2]);
								ans=min(ans,ans1+w[st]+w[ed]);
							}
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}