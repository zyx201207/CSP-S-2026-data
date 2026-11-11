#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100,M=510;
int c,n,m,d,q,w[N],hhr[M],to[M][M];
int d1[M],vis[M],dis[M][M];
struct h{ int v,w; };
vector<h> u[M],u1[N];
inline void D(int s){
	for(int i=1;i<=n;i++) d1[i]=LLONG_MAX,vis[i]=0;
	d1[s]=0; priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > q; q.push({0,s});
	while(!q.empty()){
		int p=q.top().second; q.pop();
		if(vis[p]) continue;
		vis[p]=1;
		for(int i=0;i<u[p].size();i++){
			int v=u[p][i].v,w=u[p][i].w;
			if(d1[v]>d1[p]+w) d1[v]=d1[p]+w,q.push({d1[v],v});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(to,-1,sizeof to);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>hhr[i];
		for(int j=1;j<=hhr[i];j++){
			int id,t; cin>>id>>t;
			u1[id].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		int len=(int)u1[i].size();
		for(int j=0;j<len;j++){
			int v=u1[i][j].v,t=u1[i][j].w;
			for(int k=j+1;k<len;k++){
				int v1=u1[i][k].v,t1=u1[i][k].w;
				if(to[v][v1]==-1 || to[v][v1]>t+t1) to[v][v1]=t+t1;
				if(to[v1][v]==-1 || to[v1][v]>t+t1) to[v1][v]=t+t1;
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(to[i][j]!=-1 && i!=j) u[i].push_back({j,to[i][j]});
	for(int i=1;i<=n;i++){
		D(i);
		for(int j=1;j<=n;j++) dis[i][j]=d1[j];
	}
	while(q--){
		int x,y; cin>>x>>y;
		int ans=LLONG_MAX;
		for(int i=0;i<u1[x].size();i++){
			for(int j=0;j<u1[y].size();j++){
				int v=u1[x][i].v,v1=u1[y][j].v;
				int w=u1[x][i].w,w1=u1[y][j].w;
				ans=min(ans,dis[v][v1]+w+w1);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
