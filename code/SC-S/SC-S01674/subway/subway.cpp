#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 5e5+510;
const int M = 5e5+10;
int w[M];
ll dis[P];
bool vis[P];
vector<pair<int,int> > g[P];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i <= m;i++){
		cin>>w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin>>k;
		for(int j = 1,a,t;j <= k;j++){
			cin>>a>>t;
			g[a].push_back({m+i,t});
			g[m+i].push_back({a,t});
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		dis[s]=0;
		priority_queue<pair<int,int> > q;
		q.push({0,s});
		while(!q.empty() && !vis[t]){
			int u=q.top().second,d=-q.top().first;
			q.pop();
			if(vis[u]) continue;
			vis[u]=1;
			for(auto p:g[u]){
				int v=p.first,w=p.second;
				if(d+w<dis[v]){
					dis[v]=d+w;
					q.push({-dis[v],v});
				}
			}
		}
		cout<<dis[t]+w[s]+w[t]<<"\n";
	}
	return 0;
}