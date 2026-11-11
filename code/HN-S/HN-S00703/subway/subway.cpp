//i+m 站厅 
//i   站台 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<long long,long long>
#define fir first
#define sec second
const int N=1e5+114;
int c,n,m,d,q,w[N],dis[N*505],ans[N],x[N],y[N];
vector<pii> g[N*505],qu[N];
vector<int>xian[N];
bool vis[N*505];
void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,s});
	for(int i=0;i<=(n+1)*(m+1);i++)dis[i]=0x3f3f3f3f3f3f3f3f,vis[i]=0;
	//这里要记得改成 long long  
	
	//memset(dis,0x3f,sizeof dis),memset(vis,0,sizeof vis);
	
	dis[s]=0;
	while(q.size()){
		int u=q.top().sec;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto genshin:g[u]){
			int v=genshin.fir,w=genshin.sec;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int kk;
		cin>>kk;
		int s,p;//s,a 均为站厅 (1<=s,a<=m) s+i*m is  i 号线的站台 
		cin>>s>>p;
		
		//cout<<"\n\n\n";
		
		g[s+i*m].push_back({s,p}),g[s].push_back({s+i*m,p});
		
		//cout<<"站厅 "<< s <<" 与 "<< s+i*m <<" 站台连接\n"; 
		
		
		xian[s].push_back(i);
		for(int j=2,a,t;j<=kk;j++){
			cin>>a>>t;
			
			g[a+i*m].push_back({s+i*m,0});
			g[s+i*m].push_back({a+i*m,0});
			
			g[a+i*m].push_back({a,t});
			g[a].push_back({a+i*m,t});
			//cout<<"站厅 "<< a <<" 与 "<< a+i*m <<" 站台连接\n"; 
			xian[a].push_back(i);
			
			s=a,p=t;
			/*g[i+m].push_back({i,t});
			g[i].push_back({i+m,t});
			g[i].push_back({a,0});*/
			//g[a].push_back({i,0});
		}
		
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		qu[x[i]].push_back({y[i],i});
	}
	
	/*for(int i=1;i<=m;i++,cout<<"\n"){
		cout<<"站厅 "<<i<<" 连接的站台 : "; 
		for(auto v:g[i])cout<<v.fir<<" ";
	}*/
	/*for(int i=1;i<=m;i++,cout<<"\n"){
		cout<<"站厅 "<<i<<" 的线路选择：";
		for(auto v:xian[i])cout<<v<<" "; 
	}*/
	
	
	
	//memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=m;i++){
		if(qu[i].size()){//有以 i 为起点的 
				dijkstra(i);
				for(auto genshin:qu[i]){
					int j=genshin.fir,id=genshin.sec;
					//ans[id]=dis[j]+w[x[id]]+w[y[id]];
						ans[id]=dis[j]+w[x[id]]+w[y[id]];
						
						//cout<<"问题 "<< id <<" 起点 "<<ii<<" 号线路，终点 "<< jj <<" 号线路，长度"<<dis[j]<<"\n"; 
						
						
					
				}
			//cout<<"\n\n";
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
}
//会赢吗？
//RP++
//希望能有 6 钩 
//luogu 991587 
