#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 

int c,n,m,d,q;
const int N=510,M=500520;
int w[M],dist[M];
vector<pii>g[M];
int dij(int s,int e){
	priority_queue<pii,vector<pii>,greater<pii>> h;
	h.push({0,s});
	memset(dist,0x3f,sizeof dist);
	dist[s]=0;
	while(!h.empty()){
		int t=h.top().second;
		h.pop();
		for(int i=0;i<(int)g[t].size();i++){
			int j=g[t][i].second,a=g[t][i].first;
			if(dist[t]+a<dist[j]){
				dist[j]=dist[t]+a;
				//cout<<j<<"-"<<t<<" "<<dist[j]<<" "<<dist[t]<<a<<endl;
				h.push({dist[j],j});
			}
		}
	}
	return dist[e];
}
int main(){
	freopen("subway4.in","r",stdin);
	freopen("subway4.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a=0;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			g[(i-1)*d+m+x].push_back({y,x});
			g[x].push_back({y,(i-1)*d+m+x});
			if(a!=0){
				g[(i-1)*d+m+x].push_back({0,a});
				g[a].push_back({0,(i-1)*d+m+x});
			}
			a=(i-1)*d+m+x;
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<w[s]+w[e]+dij(s,e)<<endl;
	}
	return 0;
}