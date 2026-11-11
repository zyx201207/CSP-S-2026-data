#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010,M=510;
int num,n,m,d,q,w[M],dis[N+M];
vector<pair<int,int>> g[N+M];
void dij(int st){
	memset(dis,0x3f,sizeof dis);
	priority_queue<pair<int,int>> q;
	dis[st]=0;
	q.push({0,st});
	while(!q.empty()){
		pair<int,int> u=q.top();
		q.pop();
		int ds=-u.first,x=u.second;
		if(ds!=dis[x])continue;
		for(pair<int,int> i:g[x]){
			int v=i.first,w=i.second;
			if(ds+w<dis[v]){
				dis[v]=ds+w;
				q.push({-dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>num>>m>>n>>d>>q;
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	for(int i=1;i<=m;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int v,w;
			cin>>v>>w;
			g[n+i].push_back({v,w});
			g[v].push_back({n+i,w});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<w[x]+w[y]+dis[y]<<'\n';
	}
	return 0;
}

