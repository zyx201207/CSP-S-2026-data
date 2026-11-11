#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=605;//线路数量
const int M=5e5;//点数量
const int mod=998244353;
const int inf=1e18;
int c;
int n,m,d,qu;//地铁线路数 地铁站数 最多多少条线 询问数量
vector<pair<int,int> > E[M*25];//第i个站口的地铁 p+N*i 将站厅视作第0个站口 同一线路视作第21个点（超级原点
//不考虑不站台 将站厅直接向超级原点连边
int ww[M];
int dis[M*25];//在第i个站口 第j个站台的最小步数
int vis[M*25];
priority_queue<pair<int,int> , vector<pair<int,int> >,greater<pair<int,int> > > q;
struct node{
	int u,v,point;
}query[M];
unordered_map<int,int> mp[M];

//看看数组行不行

void dij(int st){
	//从哪个站口进入
	 for(int i=0;i<=n+m+1;i++){
		dis[i]=inf;
		vis[i]=0;
	}
	
	dis[st]=0;
	q.push({0,st});
	//第一维放的是ds 第二个是点
	
	
	
	//注意！！！dis的计算是没有算上初始的两个下行进站
	
	
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto i:E[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	for(int ed=1;ed<=m;ed++){
		mp[st][ed+n]=dis[ed+n];
		//if(st==1) cout<<dis[ed+n]<<" ";
		//ans[st][ed]=ww[st]+ww[ed]+dis[ed];
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	double sttime=clock(); 
	
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++){
		cin>>ww[i];//站口下到站厅时间
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		//int x=i*M;
		//int spr=i+M*21;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			a+=n;
			E[a].push_back({i,t});
			E[i].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++){
			dij(i);
	}
	//离线问
	
	//枚举中转核心原点
	for(int i=1;i<=qu;i++){
		int fm,to;
		cin>>fm>>to;
		fm+=n,to+=n;
		int ans=1e18;
		for(int j=1;j<=n;j++){
			ans=min(mp[j][fm]+mp[j][to]+ww[fm-n]+ww[to-n],ans);
		}
		cout<<ans<<"\n";
		//cout<<ans[fm][to]<<"\n";
	}
	return 0;
}
