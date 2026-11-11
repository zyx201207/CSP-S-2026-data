#include<bits/stdc++.h>
using namespace std;
const int N=500+5,M=5e5+5,K=2e3+5;
#define ll long long
const ll inf=0x3f3f3f3f3f3f3f3f,Inf=2e9+5;
int qrd(){
	char c;int ret=0;
	do{
		c=getchar();
	}while(!isdigit(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(isdigit(c));
	return ret;
}
int c,n,m,d,q,cnt,W[M];
struct Edge{
	int v,w;
};
vector<Edge> to[M*2];
void add(int u,int v,int w){
	to[u].push_back({v,w});
	to[v].push_back({u,w});
}
ll dis[M];
void dijkstra(int s,int lim){
	for(int i=0;i<=lim+5;i++)dis[i]=inf;
	dis[s]=0;
	priority_queue<pair<ll,int> > q;
	q.push(make_pair(-dis[s],s));
	while(!q.empty()){
		pair<ll,int> tt=q.top();q.pop();
		int u=tt.second;ll dist=-tt.first;
		if(dist>dis[u])continue;
		for(auto e:to[u]){
			int v=e.v,w=e.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(make_pair(-dis[v],v));
			}
		}
	}
}
ll ans[K][K];
void solve1(){
	for(int i=1;i<=n;i++){
		int k;k=qrd();
		int lst=0;
		for(int j=1;j<=k;j++){
			int a,t;a=qrd();t=qrd();
			add(++cnt,a,t);
			if(lst)add(cnt,lst,0);
			lst=cnt;
		}
	}
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=m;i++){
		dijkstra(i,cnt);
		for(int j=1;j<=m;j++)ans[i][j]=dis[j];
	}
	while(q--){
		int x,y;x=qrd();y=qrd();
		printf("%lld\n",ans[x][y]+W[x]+W[y]);
	}
}
int G[N][N];
vector<pair<int,int> > state[M];
void solve2(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)G[i][j]=Inf;
	for(int i=1;i<=n;i++){
		int k;k=qrd();
		for(int j=1;j<=k;j++){
			int a,t;a=qrd();t=qrd();
			state[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++){
		for(int j1=0;j1<state[i].size();j1++){
			for(int j2=j1+1;j2<state[i].size();j2++){
				pair<int,int> l1=state[i][j1],l2=state[i][j2];
				G[l1.first][l2.first]=min(G[l1.first][l2.first],l1.second+l2.second);
				G[l2.first][l1.first]=min(G[l2.first][l1.first],l1.second+l2.second);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(G[i][j]<Inf)add(i,j,G[i][j]);
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=n;i++){
		dijkstra(i,n);
		for(int j=1;j<=n;j++)ans[i][j]=dis[j];
	}
	while(q--){
		int x,y;x=qrd();y=qrd();
		ll fnl=inf;
		for(auto l1:state[x]){
			for(auto l2:state[y]){
				ll sum=1ll*l1.second+l2.second+ans[l1.first][l2.first];
				fnl=min(fnl,sum);
			}
		}
		printf("%lld\n",fnl+W[x]+W[y]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=qrd();n=qrd();m=qrd();d=qrd();q=qrd();
	cnt=m;
	for(int i=1;i<=m;i++)W[i]=qrd();
	if(c<=11)solve1();
	else solve2();
	return 0;
}