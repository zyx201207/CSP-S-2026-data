#include<bits/stdc++.h>
#define F first
#define S second
#define mkp make_pair
using namespace std;
int C,n,m,D,Q,w[500005];
//int A[405],T[405];long long dis[1005][1005];
//void solve1(){
//	memset(dis,0x3f,sizeof dis);
//	for(int i=1,K;i<=n;i++){
//		cin>>K;
//		for(int j=1;j<=K;j++){
//			cin>>A[j]>>T[j];
//			for(int k=1;k<j;k++){
//				int x=A[k],y=A[j];
//				dis[x][y]=min(dis[x][y],1ll*T[j]+T[k]);
//				dis[y][x]=min(dis[y][x],1ll*T[j]+T[k]);
//			}
//		}
//	}
//	for(int i=1;i<=m;i++) dis[i][i]=0;
//	for(int k=1;k<=m;k++){
//		for(int i=1;i<=m;i++){
//			for(int j=1;j<=m;j++){
//				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
//			}
//		}
//	}
//	for(int i=1,x,y;i<=Q;i++){
//		cin>>x>>y;
//		cout<<1ll*w[x]+w[y]+dis[x][y]<<'\n';
//	}
//}
vector<pair<int,long long> > E[500005];
//bitset<1005> vis;
//void dijk(int st){
//	vis.reset();
//	priority_queue<pair<long long,int> > q;
//	dis[st][st]=0;q.push(mkp(0,st));
//	while(!q.empty()){
//		int x=q.top().S;q.pop();
//		if(vis[x]) continue;
//		vis[x]=1;
//		for(int i=0;i<E[x].size();i++){
//			int y=E[x][i].F;long long w=E[x][i].S;
//			if(dis[st][y]>dis[st][x]+w){
//				dis[st][y]=dis[st][x]+w;
//				q.push(mkp(-dis[st][y],y));
//			}
//		}
//	}
//}

//void solve2(){
//	for(int i=1,K,a,b,c,d;i<=n;i++){
//		cin>>K;
//		cin>>a>>b>>c>>d;
//		E[a].push_back(mkp(c,1ll*b+d));
//		E[c].push_back(mkp(a,1ll*b+d));
//	}
//	for(int i=1;i<=m;i++){
//		dijk(i);
//	}
//	for(int i=1,x,y;i<=Q;i++){
//		cin>>x>>y;
//		cout<<dis[x][y]+w[x]+w[y]<<'\n';
//	}
//}
const long long INF=1e18;
long long e[505][505];
void solve3(){
	for(int i=1,K;i<=n;i++){
		cin>>K;
		for(int j=1,a,t;j<=K;j++){
			cin>>a>>t;
			E[a].push_back(mkp(i,t));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) e[i][j]=INF;
		e[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<E[i].size();j++){
			int x=E[i][j].F,w=E[i][j].S;
			for(int k=0;k<j;k++){
				int y=E[i][k].F,v=E[i][k].S;
				e[x][y]=min(e[x][y],1ll*w+v);
				e[y][x]=min(e[y][x],1ll*w+v);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
			}
		}
	}
	long long ans;
	for(int i=1,x,y;i<=Q;i++){
		ans=INF;
		cin>>x>>y;
		for(int j=0;j<E[x].size();j++){
			int u=E[x][j].F;
			for(int k=0;k<E[y].size();k++){
				int v=E[y][k].F;
				ans=min(ans,E[x][j].S+E[y][k].S+e[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>D>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
//	if(C<=6||m<=300){
//		solve1();
//	}
//	else if(C<=11||m<=1000){
//		solve2();
//	}
//	else{
		solve3();
//	}
	return 0;
}
