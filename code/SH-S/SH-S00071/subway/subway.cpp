#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5,N=505;
int c,n,m,d,q;
int w[M],k[N];
//int a[N][M],t[N][M];

int dis[N][N],len[N][N];
bool vis[N][N];
vector<pair<int,int> > metro[M];
//int find(int x){
//	return (fa[x]==x) ? x : fa[x]=find(fa[x]); 
//}
//void merge(int x,int y){
//	int X=find(x),Y=find(y);
//	if(X!=Y){
//		fa[X]=Y;
//	}
//}
int s[N];
priority_queue<pair<int,int> > pq;
vector<pair<int,int> >g[N];
bool use[N];

int sg[15][15],sd[15];
void dfs(int u){
	
}
//vector<pair<int,int> > sta[15];
//vector<pair<int,int> > sg[15];
//void solve1(){
//	for(int i=1;i<=n;++i){
//		cin>>k[i];
//		for(int j=1;j<=k[i];++j){
//			int x;
//			cin>>x;
//			sta[i].push_back({x,j});
//			cin>>t[i][j];
//		}
//	}
//	for(int i=1;i<=n;++i)
//	while(q--){
//		int xr,yr;
//		cin>>xr>>yr;
//		for(int i=1;i<=m;++i)	sd[i]=0x3f3f3f3f;
//		dfs(xr);
//		cout<<sd[yr];
//	}
//}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)	cin>>w[i];
//	if(c<=3){
//		solve1();
//		return 0;
//	}
	memset(dis,0x3f,sizeof(dis));
	memset(len,0x3f,sizeof(len));
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int x,y;
			cin>>x>>y;
//			fa[x]=i;
//			if(j==1){
//				s[i]=x;
//			}else{
//				fa[x]=s[i];
//			}
//			cin>>a[i][j]>>t[i][j];
			metro[x].push_back({i,y});
		}
	}

	for(int i=1;i<=m;++i){
		for(auto u : metro[i]){
			for(auto v : metro[i]){
				if(u.first==v.first)	continue;
				int x=u.first,y=v.first;
				len[x][y]=min(len[x][y],u.second+v.second);
				len[y][x]=min(len[y][x],u.second+v.second);
				vis[x][y]=1;
				vis[y][x]=1;
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(vis[i][j]){
				g[i].push_back({j,len[i][j]});
			}
		} 
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<len[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;++i){
		while(!pq.empty()){
			pq.pop();
		}
		for(int i=1;i<=n;++i)	use[i]=0;
		pq.push({0,i});
		use[i]=1;
		dis[i][i]=0;
		while(!pq.empty()){
			auto o=pq.top();	
			pq.pop();
			int u=o.second;
			for(auto oo : g[u]){
				int v=oo.first;
				if(use[v])	continue;
				dis[i][v]=min(dis[i][v],-o.first+oo.second);
			
				pq.push({-dis[i][v],v});
			}
		}
	}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	int xr,yr;
	ll ans,cur;
	while(q--){
		cin>>xr>>yr;
		ans=INT_MAX;

		for(auto u : metro[xr]){
			for(auto v : metro[yr]){
				cur=0;
				cur+=dis[u.first][v.first];
				cur+=u.second+v.second; 
				ans=min(ans,cur);
			} 
		}
		ans+=w[xr]+w[yr];
		cout<<ans<<"\n";
	}

	return 0;
}
