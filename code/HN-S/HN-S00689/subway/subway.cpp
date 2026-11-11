#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9;
const int N=505;
const int M=2*1e4+5;
int c,n,m,d,q,T;//测试点编号 线路数 站数 单个最多经过数 计划数 
int a[N][M],ans,k,dis[M],b[M],a2[N];//站口到站厅时间 总步行时间 
bool vis[M];
struct node{
	int to,t;//to表示通向站台  t1表示通向站台到站厅的时间 
}; //			   t2表示当前站台到目标线路的时间 
vector<node>e[N];//建图 边权为目前站台到目标站台的时间 
int dij(int s,int y){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,s});
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	vis[s]=1;
	while(!q.empty()){
		auto tag=q.top();q.pop();
		int u=tag.second,val=tag.first;
		for(int j=1;j<=n;j++){
			for(auto i:e[u]){
				auto to=i.to,t=i.t;
				if(!vis[to]&&dis[to]>val+t){
					dis[to]=val+t;
					vis[to]=1;
					q.push({dis[to],to});
				}
			}
		}
	}
	return dis[y];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a2[i];
	int x,y,cur=0;
	for(int i=1;i<=n;i++){
		cin>>k;
		int cnt=0;
		++cur;
		for(int j=1;j<=k;j++){
			cin>>b[++cnt];
			cin>>a[cur][b[cnt]];		
		}
		for(int g=1;g<=cnt;g++){
			for(int p=1;p<=cnt;p++){
				if(p==g)continue;
				e[b[p]].push_back({b[g],a[cur][g]+a[cur][p]});
				e[b[g]].push_back({b[p],a[cur][g]+a[cur][p]});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		ans=0;
		ans+=a2[x]+a2[y];
		ans+=dij(x,y);
		cout<<ans<<"\n";
	} 
	return 0; 
} 
