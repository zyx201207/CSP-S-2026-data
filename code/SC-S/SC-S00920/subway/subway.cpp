#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

const int N=520,M=6e5+10;
const long long inf=1e18;
int c,n,m,d,q;
long long w[M];//地铁站到站厅
long long dist[M];
int vis[M];
long long dis[N][N];//地铁线路之间的距离
vector<pii> node[M];

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(dis,0x3f,sizeof dis);
	
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int id,t;
			cin>>id>>t;
			node[id+n].push_back({i,t});
			node[i].push_back({id+n,t});
		}
	}
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pii &S1:node[i+n]){
			for(pii &S2:node[i+n]){
				long long s1=S1.first,t1=S1.second;
				long long s2=S2.first,t2=S2.second;
//				cout<<s1<<' '<<s2<<' '<<dis[s1][s2]+t1+t2<<'\n';
				dis[s1][s2]=min(dis[s1][s2],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n+m;j++) dist[j]=inf,vis[j]=0;
//		priority_queue<pii,vector<pii>,greater<pii>> qu;
//		qu.push({0,i}); dist[i]=0;
//		while(qu.size()){
//			int u=qu.top().second;
//			qu.pop();
//			if(vis[u])continue;
//			vis[u]=1;
//			for(pii var:node[u]){
//				int v=var.first,w=var.second;
//				if(dist[v]>dist[u]+w){
//					dist[v]=dist[u]+w;
//					qu.push({dist[v],v});
//				}
//			}
//		}
//		for(int j=1;j<=n;j++)
//			dis[i][j]=dist[j];
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long minn=inf;
		cin>>x>>y;
		for(pii &S1:node[x+n]){
			for(pii &S2:node[y+n]){
				int s1=S1.first,t1=S1.second;
				int s2=S2.first,t2=S2.second;
//				cout<<s1<<' '<<s2<<' '<<dis[s1][s2]+t1+t2<<'\n';
				minn=min(dis[s1][s2]+t1+t2,minn);
			}
		}
		cout<<minn+w[x]+w[y]<<'\n';
//		cout<<"\n---------------\n";
	}
	return 0;
}
//15:42