#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=6e5+5;
int val[MAXN];
struct Edge{
	int to,w; 
};
vector<Edge> edges[MAXN];
int dist[MAXN];
int c,n,m,d,q;
void dis(int s){
	priority_queue<pair<int,int>> pq;
	pq.push({s,0});
	dist[s]=0;
	while(!pq.empty()){
		int u=pq.top().first;
		pq.pop();
		for(auto v:edges[u]){
			int y=v.to;
			if(y==u) continue;
			int vals=v.w;
			if(dist[y]>dist[u]+vals){
				dist[y]=dist[u]+vals;
				pq.push({y,-dist[y]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	for(int i=m+1;i<m+1+n;i++){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			int v,w;
			cin>>v>>w;
			edges[i].push_back({v,w});
			edges[v].push_back({i,w});
		}
	}
	while(q--){
		memset(dist,0x3f3f3f,sizeof dist);
		int x,y;
		cin>>x>>y;
		dis(x);
		cout<<dist[y]+val[x]+val[y]<<"\n";
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
*/
//.....Íü¼ÇdijÕ¦Ð´ÁËQWQ 

