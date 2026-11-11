#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
const int MAXN=5e5+505;
struct node{
	int to,w;
};
struct node2{
	int dis,id;
	bool friend operator <(node2 x,node2 y){
		return x.dis>y.dis;
	}
};
int c,n,m,d,q;
int w[M];
vector<node> g[MAXN];
int dis[MAXN];
int flag[MAXN];
int f(int s,int t){
	priority_queue<node2> q;
	for(int i=1;i<=m+n;i++){
		dis[i]=1e18;
		flag[i]=0;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		node2 x=q.top();
		q.pop();
		int id=x.id;
		if(flag[id]){
			continue;
		}
		flag[id]=1;
		for(int i=0;i<g[id].size();i++){
			int to=g[id][i].to;
			int w=g[id][i].w;
			if(dis[to]>dis[id]+w){
				dis[to]=dis[id]+w;
				q.push({dis[to],to});
			}
		}
	}
	return dis[t]+w[s]+w[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({m+i,y});
			g[m+i].push_back({x,y});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<f(x,y)<<'\n';
	}
	return 0;
}
