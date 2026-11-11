#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,M = 5e5+5;
int c,n,m,d,q;
int w[M];
struct node{
	int v,w;
};
vector<node>v[M+N];
int dis[M+N];
bool vis[M+N];
int dij(int st,int ed){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[st] = 0;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		for(node t:v[u]){
			int to = t.v,w = t.w;
			if(dis[to]>dis[u]+w){
				dis[to] = dis[u] +w;
				q.push(to);
			}
		}
	}
	return dis[ed];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>w[i];
	}
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			v[x].push_back({i+m,t});
			v[i+m].push_back({x,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<'\n';
	}
    return 0;
}
