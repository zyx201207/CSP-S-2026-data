#include<bits/stdc++.h>
using namespace std;
const int N=500,M=5e5+11,INF=2e9;
int c,n,m,d,q;
int w[M],t[N][M];
vector<int>tmp[M];
struct node{
	int to,we;
};
vector<node>edge[N];
int b[N][N];
struct data{
	int val,id;
	bool operator < (data other)const{
		return val>other.val;
	}
};
priority_queue<data>pq;
int dis[N],used[N];
void dij(int ss,int W){
	for(int i=0;i<=n;i++){
		dis[i]=INF;
		used[i]=0;
	}
	dis[ss]=W;
	pq.push({dis[ss],ss});
	while(!pq.empty()){
		int u=pq.top().id;
		pq.pop();
		used[u]=1;
		for(auto v:edge[u]){
			if(dis[v.to]>dis[u]+v.we){
				dis[v.to]=dis[u]+v.we;
				pq.push({dis[v.to],v.to});
			}
		}
		while((!pq.empty())&&(used[pq.top().id]==1))pq.pop();
	}
	while(!pq.empty())pq.pop();
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a;
			cin>>t[i][a];
			tmp[a].push_back(i);
		}
	}
	for(int o=1;o<=m;o++){
		if(tmp[o].size()>1){
			for(int i:tmp[o]){
				for(int j:tmp[o]){
					if(i==j)continue;
					int tt=t[i][o]+t[j][o];
					if(b[i][j]){
						for(auto v:edge[i]){
							if(v.to==j){
								tt=max(tt,v.we);
								break;
							}
						}
					}
					edge[i].push_back({j,tt});
					edge[j].push_back({i,tt});
					b[i][j]=1;b[j][i]=1;
				}
			}
		}
	}
	for(int o=1;o<=q;o++){
		int x,y,ans=INF;
		cin>>x>>y;
		for(int u:tmp[x]){
			dij(u,w[x]+t[u][x]);
			for(int v:tmp[y]){
				if(dis[v]==INF)continue;
				int res=dis[v]+w[y]+t[v][y];
				ans=min(ans,res);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}