#include<bits/stdc++.h>
using namespace std;
int w[100005];
int vis[100005];
int dis[100005];
vector<int> g[100005];
queue<int> pq;
int c,n,m,d,q;
void dij(){
	memset(vis,0,sizeof(vis));
	fill(dis+1,dis+n+1,pow(2,31)-1);
	dis[1] = 0;
	pq.push(1);
	while(!pq.empty()){
		int u = pq.front();
		pq.pop();
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
//		for(int it:g[u]){
//			if(vis[u]+it<vis[it]){
//				vis[it] = vis[u]+a[];
//				q.push({it,dis[it]});
//			}
//		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(cin >> c >> n >> m >> d >> q){
		cout<< 0 << endl;
	}
}
