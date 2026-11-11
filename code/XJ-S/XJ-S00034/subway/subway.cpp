#include <bits/stdc++.h>
using namespace std;


const int N=510,M=5e5+10;
using ll=long long;
using pli=pair<ll,int>;


int c,n,m,d,q;
int w[N];
int k[M];
int t[M][N];
ll dist[M];

vector<int>gv[M];
vector<int>ge[N];


ll dijkstra(int s,int target){
	priority_queue<pli,vector<pli>,greater<pli> >q;
	q.push({0,s});
	dist[s]=0;
	while (!q.empty()){
		auto x=q.top();
		q.pop();
		int w0=x.first,u=x.second;
		if (w0>dist[u]){
			continue;
		}
		for (auto l:gv[u]){
			int w1=t[l][u];
			for (auto v:ge[l]){
				if (gv[v].size()==1){
					dist[v]=min(dist[v],dist[u]+w1+t[l][v]);
					continue;
				}
				int w2=t[l][v];
				if (dist[u]+w1+w2<dist[v]){
					dist[v]=dist[u]+w1+w2;
					q.push({dist[v],v});
				}
			}
		}
	}
	return dist[target];
}

int main (){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf ("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf ("%d",&w[i]);
	}
	for (int i=1;i<=n;i++){
		scanf ("%d",&k[i]);
		for (int j=1;j<=k[i];j++){
			int u,w;
			scanf ("%d%d",&u,&w);
			gv[u].push_back(i);
			ge[i].push_back(u);
			t[i][u]=w; 
		}
	}
	while (q--){
		int s,t;
		scanf ("%d%d",&s,&t);
		memset(dist,0x3f,sizeof dist);
		printf ("%lld\n",dijkstra(s,t)+w[s]+w[t]);
	}
	
	return 0;
}
