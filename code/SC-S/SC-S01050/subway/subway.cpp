#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M];
long long ans,dis[N][N];
struct node{
	int v;
	long long w;
	bool operator<(const node&x)const{
		return x.w<w;
	}
};
vector<node>g[N],rou[M];
priority_queue<node>pq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			rou[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<(int)rou[i].size();j++) for(int k=j+1;k<(int)rou[i].size();k++){
			node u=rou[i][j],v=rou[i][k];
			g[u.v].push_back({v.v,u.w+v.w}),g[v.v].push_back({u.v,u.w+v.w});
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=9e18;
		pq.push({i,dis[i][i]=0});
		while(!pq.empty()){
			node u=pq.top();
			pq.pop();
			if(u.w!=dis[i][u.v]) continue;
			for(node v:g[u.v]) if(dis[i][v.v]>u.w+v.w) pq.push({v.v,dis[i][v.v]=u.w+v.w});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y,ans=9e18;
		for(node u:rou[x]) for(node v:rou[y]) ans=min(ans,u.w+v.w+dis[u.v][v.v]);
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}