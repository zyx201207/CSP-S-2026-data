#include<bits/stdc++.h>
using namespace std;
const long long N=5e2+10,M=5e5+10;
long long c,n,m,d,q;
long long w[M];
long long dis[M];
long long s[M],t[M];
struct node{
	long long u,v;
};
vector<node>G[M];
struct edge{
	long long u,v;
	bool operator<(const edge &o)const{
		return o.v<v;
	}
};
int vis[M];
struct pp{
	long long s,t;
}ppp[M];
bool A=1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;m++;
		if(k>2)A=0;
		for(long long j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			G[a].push_back({m,t});
			G[m].push_back({a,t});
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>ppp[i].s>>ppp[i].t;
	}
	
//	if(A){
//		
//	}
	
	
	
	for(long long i=1;i<=q;i++){
priority_queue<edge> pq;
		pq.push({ppp[i].s,0});
//		cout<<1;
		memset(dis,0x3f,sizeof(dis));
//		for(long long i=1;i<=n;i++)cout<<dippp[i].s<<'\n';
		dis[ppp[i].s]=0;
		while(pq.size()){
////			cout<<1;
			int cur=pq.top().u;
			pq.pop();
			if(vis[cur])continue;
			vis[cur]=1;
			for(int j=0;j<G[cur].size();j++){
//				cout<<<<'\n';
				if(dis[G[cur][j].u]>dis[cur]+G[cur][j].v){
					dis[G[cur][j].u]=dis[cur]+G[cur][j].v;
					pq.push({G[cur][j].u,dis[G[cur][j].u]});
				}
			}
			vis[cur]=0;
		}
		cout<<dis[ppp[i].t]+w[ppp[i].s]+w[ppp[i].t]<<'\n';
	}
	return 0;
}
