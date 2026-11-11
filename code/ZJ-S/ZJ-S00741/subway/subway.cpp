#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1000000000000000000;
int c,n,m,d,q;
namespace sub1{
	int w[305],a[55][305],t[55][305],k[55];
	bool vis[355];
	ll dis[355];
	vector<pair<int,int> >ed[355];
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >que;
	void dijkstra(int x){
		que.push({0,x});
		dis[x]=0;
		while(!que.empty()){
			auto t=que.top();que.pop();
			if(vis[t.second]) continue;
			vis[t.second]=true;
			for(auto i:ed[t.second]){
				if(dis[i.first]>t.first+i.second){
					dis[i.first]=t.first+i.second;
					que.push({dis[i.first],i.first});
				}
			}
		}
	}
	int main(){
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%d%d",&a[i][j],&t[i][j]);
				ed[i+m].push_back({a[i][j],t[i][j]});
				ed[a[i][j]].push_back({i+m,t[i][j]});
			}
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			dijkstra(x);
			printf("%lld\n",dis[y]+w[x]+w[y]);
		}
		return 0;
	}
}
namespace sub2{
	int w[1005];
	ll dis[1505][1505];
	bool vis[1505];
	vector<pair<int,int> >ed[1505];
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >que;
	void dijkstra(int dj,int x){
		que.push({0,x});
		dis[dj][x]=0;
		while(!que.empty()){
			auto t=que.top();que.pop();
			if(vis[t.second]) continue;
			vis[t.second]=true;
			for(auto i:ed[t.second]){
				if(dis[dj][i.first]>t.first+i.second){
					dis[dj][i.first]=t.first+i.second;
					que.push({dis[dj][i.first],i.first});
				}
			}
		}
	}
	int main(){
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++){
				int u,v;
				scanf("%d%d",&u,&v);
				ed[u].push_back({i+m,v});
				ed[i+m].push_back({u,v});
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=1500;j++) dis[i][j]=inf;
			memset(vis,0,sizeof(vis));
			dijkstra(i,i);
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",w[x]+w[y]+dis[x][y]);
		}
		return 0;
	}
}
namespace sub3{
	int w[500005],T;
	vector<int>ed[500505];
	queue<int>que;
	bool vis[500505];
	ll bfs(int x,int y){
		vis[x]=true;
		que.push(x);
		ll res=0;
		while(!que.empty()){
			int len=que.size();
			res++;
			for(int i=1;i<=len;i++){
				int t=que.front();que.pop();
				for(int j:ed[t]){
					if(!vis[j]){
						vis[j]=true;
						que.push(j);
						if(j==y) return res;
					}
				}
			}
		}
		return res;
	}
	int main(){
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++){
				int u,v;
				scanf("%d%d",&u,&v);
				ed[u].push_back(i+m);
				ed[i+m].push_back(u);
				T=v;
			}
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			for(int i=1;i<=n+m;i++) vis[i]=false;
			ll l=bfs(x,y);
			printf("%lld\n",l*T+w[x]+w[y]);
			while(!que.empty()) que.pop();
		}
		return 0;
	}
}
namespace sub4{
	int w[500005];
	ll qu[2][500005],ba[500005][2];
	int main(){
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=m;i++) qu[1][i]=qu[2][i]=ba[i][1]=ba[i][2]=inf;
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++){
				int u,v;
				scanf("%d%d",&u,&v);
				qu[i][u]=v;
				ba[u][i]=v;
			}
		}
		int z=0;
		ll Min=inf;
		for(int i=1;i<=n;i++){
			if(Min>qu[1][i]+ba[i][2]){
				Min=qu[1][i]+ba[i][2];
				z=i;
			}
		}
		while(q--){
			int u,v;
			scanf("%d%d",&u,&v);
			ll ans=min(ba[u][1]+qu[1][v],ba[u][2]+qu[2][v]);
			if(z!=u&&z!=v){
				ans=min(ans,Min+ba[u][1]+qu[2][v]);
				ans=min(ans,Min+ba[u][2]+qu[1][v]);
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c>=0&&c<=6) sub1::main();
	else if(c>=7&&c<=11) sub2::main();
	else if(c>=12&&c<=19) sub3::main();
	else if(c==20||c==21) sub4::main();
	return 0;
}