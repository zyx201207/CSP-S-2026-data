#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5;
const int M=1e3+5;//?
int c,n,m,d,q,w[M],k[N];
//测试点编号，地铁线路数量，地铁站数，最多被经过数量，出行计划数量
struct Node{
	int x,y,len;//第x条线路，y号站台（不是第y个），距离 
	friend bool operator < (Node a,Node b){
		return a.len>b.len;
	}
}; 
priority_queue<Node>pq;
vector<Node>v[N][M];
int l[N][M],dis[N][M],ans[M][M];
bool vis[N][M];//是否有经过第i条地铁线路的第j个站台 
void solve1(){
	for(int i=1;i<=m;i++)cin>>w[i];//每个地铁站的地铁口走到站厅的时间
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			l[i][j]=-1;
		}
	}
	for(int i=1;i<=n;i++){
		//第i个地铁线路
		cin>>k[i];//第i条线路经过的地铁站数量
		int shang=-1;
		for(int j=1;j<=k[i];j++){
			int x,t;
			cin>>x;//第i条线路经过的第j个地铁站的编号
			if(shang!=-1){
				v[i][shang].push_back({i,x,0});
				v[i][x].push_back({i,shang,0});
			}
			shang=x;
			cin>>t;//从该地铁站的站厅走到第i条线路的站台所需要的时间 
			l[i][x]=t;
		} 
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int z=1;z<=m;z++){
				//从第i条线路的z号地铁站走到第j条线路的z号地铁站
				//所需要的时间
				if(l[i][z]==-1||l[j][z]==-1||i==j)continue;
				v[i][z].push_back({j,z,(l[i][z]+l[j][z])});
			} 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){//m个站台 
		memset(vis,0,sizeof vis);
		for(int j=1;j<=n;j++){
			for(int z=1;z<=m;z++){
				dis[j][z]=1e18;
			}
		}
		for(int j=1;j<=n;j++){//n个地铁线路数 
			if(l[j][i]==-1)continue;
			pq.push({j,i,0});
			dis[j][i]=w[i]+l[j][i];
		}
		while(!pq.empty()){
			Node sum=pq.top();
			pq.pop();
			int nx=sum.x,ny=sum.y,nlen=sum.len;
			if(vis[nx][ny])continue;
			vis[nx][ny]=1;
			for(int j=0;j<v[nx][ny].size();j++){
				int tox=v[nx][ny][j].x;
				int toy=v[nx][ny][j].y;
				int tolen=v[nx][ny][j].len;
				if(dis[tox][toy]>dis[nx][ny]+tolen){
					dis[tox][toy]=dis[nx][ny]+tolen;
					pq.push({tox,toy,dis[tox][toy]}); 
				}
			}
		}
		for(int j=1;j<=n;j++){
			for(int z=1;z<=m;z++){
				int sum=min(ans[i][z],dis[j][z]+w[z]+l[j][z]);
				sum=min(ans[z][i],sum);
				ans[i][z]=sum;
				ans[z][i]=sum;
			}
		}
	}
	while(q--){
		int s,e;
		cin>>s>>e;
		cout<<ans[s][e]<<'\n';
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	solve1();
	return 0;
}
