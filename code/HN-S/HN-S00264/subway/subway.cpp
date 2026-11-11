#include<bits/stdc++.h>
using namespace std;
#define int long long
int dist[1003][1003],n,m,d,q,a[500005];
vector<pair<int,int> > e[1000005];
struct node{
	int id,w;
	bool operator<(const node &t)const{
		return w<t.w;
	}
};
priority_queue<node> q1;
void djk(int s){
	q1.push({s,0});
	while(!q1.empty()){
		int x=q1.top().id;int w=q1.top().w;
		q1.pop();
		dist[x][s]=min(dist[x][s],w);
		if(w>dist[x][s])continue;
		for(int i=0;i<e[x].size();i++){
			int v=e[x][i].first,w=e[x][i].second;
			if(dist[v][s]>dist[x][s]+w){
				dist[v][s]=dist[x][s]+w;
				q1.push({v,dist[v][s]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			e[a].push_back({m+i+2,t});
			e[m+i+2].push_back({a,t});
		}
	}
	for(int i=1;i<=m;i++){
		djk(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]+a[x]+a[y]<<'\n';
	} 
}
/*
哭了，44分的点打了1个小时 
*/ 
