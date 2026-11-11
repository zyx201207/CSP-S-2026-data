#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q;
int w[500505];
vector<pair<int,ll>>g[500505];
map<int,map<int,ll>>gg;
bool vis[500505];
ll dis[500505];
void dij(int s){
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	for(int i=1;i<=n+m;i++){
		dis[i]=1e18;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int now=q.top().second;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=0;i<g[now].size();i++){
			if(dis[g[now][i].first]>dis[now]+g[now][i].second){
				dis[g[now][i].first]=dis[now]+g[now][i].second;
				q.push({dis[g[now][i].first],g[now][i].first});
			}
		}
	}
}
//ll bfs(int s,int e){
//	queue<pair<int,int>>q;
//	q.push({0,s});
//	vis[s]=1;
//	while(!q.empty()){
//		int now=q.front().second;
//		int w=q.front().first;
//		q.pop();
//		//cout<<now<<" "<<w<<'\n';
//		for(int i=0;i<g[now].size();i++){
//			if(vis[g[now][i].first])continue;
//			if(g[now][i].first==e){
//				//cout<<w<<" "<<g[s][i].second<<'\n';
//				return w+g[now][i].second;
//			}
//			vis[g[now][i].first]=1;
//			q.push({w+g[now][i].second,g[now][i].first});
//		}
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>gg[i][a];
			ll t=gg[i][a];
			g[i+m].push_back({a,w[a]+t});
			g[a].push_back({i+m,w[a]+t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			long long qz=1e18;
			for(int k=1;k<=m;k++){
				if(gg[i][k]!=0&&gg[j][k]!=0){
					qz=min(qz,1ll*gg[i][k]+1ll*gg[j][k]);
				}
			}
			g[i+m].push_back({j+m,qz});
			g[j+m].push_back({i+m,qz});
		}
		
	}
	while(q--){
		for(int i=1;i<=n+m;i++)vis[i]=0;
		int s,e;
		cin>>s>>e;
		dij(s);
		//cout<<'\n';
		cout<<dis[e]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
