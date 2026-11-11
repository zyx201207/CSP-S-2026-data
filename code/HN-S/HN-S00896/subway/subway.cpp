#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int c,n,m,d,q;
ll ans;
//五个非负整数c, n, m, d, q，分别表示测试点编号、地铁线路数、
//地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
//，ti,j 表示从该地铁站的站厅走到第i 条线
//路的站台需要的时间。
int w[N],k[505],dis[N],inq[N];
int tim[505][N];
struct edge{
	int to;
	int line;
};
struct priq{
	int num;
	int dis;
	int preline;
	bool operator <(const priq &t)const{
		return dis>t.dis;
	}
};
vector<edge>g[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];//经过地铁站数 
		int last;
		for(int j=1;j<=k[i];j++){
			int u;
			cin>>u;
			cin>>tim[i][u];
			//cout<<tim[i][u]<<"\n";
			if(j==1) last=u;
			else{
				g[last].push_back({u,i});
				last=u;
			}
		}
		
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)
//			cout<<tim[i][j]<<" ";
//			cout<<"\n";
//	}

	while(q--){
		ans=0;
		int st,ed;
		cin>>st>>ed;
		ans=w[st]+w[ed];
		memset(dis,0x3f,sizeof(dis));
		dis[st]=0;
		priority_queue<priq>pq;
		//dis 上一次坐的线路 
		int preline=0;
		int mincost=-1;
		for(edge v:g[st]){
			//pq.push({st,v.line});
			if(dis[st]==0){
				preline=v.line;
				dis[st]=tim[v.line][st];	
			}
			else{
				dis[st]=min(dis[st],tim[v.line][st]);
				if(tim[v.line][st]<tim[preline][st]){
					preline=v.line;
				}	
			}
		}
		//cout<<"st:"<<dis[st]<<" "<<preline<<"\n";
		pq.push({st,dis[st],preline});
		while(!pq.empty()){
			priq last=pq.top();
			//cout<<last.preline<<'\n';
			int u=last.num;
			pq.pop();
			inq[u]=0;
			for(edge v:g[u]){
				if(v.line!=last.preline){
					if(dis[v.to]>dis[u]+tim[last.preline][u]+tim[v.line][u])	{
						dis[v.to]=dis[u]+tim[last.preline][u]+tim[v.line][u];
						if(v.to==ed){
							if(mincost==-1) mincost=tim[v.line][v.to];
							mincost=min(mincost,tim[v.line][v.to]);
						}
						//cout<<v.to<<":"<<dis[v.to]<<" "<<last.preline<<" "<<v.line<<" "<<tim[last.preline][u]+tim[v.line][u]<<"\n";
						if(!inq[v.to]){
							inq[v.to]=1;
							pq.push({v.to,dis[v.to],v.line});
						}
					}
				}
				else{
					if(dis[v.to]>dis[u]){
						dis[v.to]=dis[u];
												if(v.to==ed){
							if(mincost==-1) mincost=tim[v.line][v.to];
							mincost=min(mincost,tim[v.line][v.to]);
						}
						//cout<<v.to<<":"<<dis[v.to]<<" "<<last.preline<<"\n";
						if(!inq[v.to]){
							inq[v.to]=1;
							pq.push({v.to,dis[v.to],v.line});
						}
					}
				}
				
			}
		}
		
		cout<<dis[ed]+ans+mincost<<"\n";
	}
	return 0;
} 
/*


*/
