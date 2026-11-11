#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct node1{
	int v,kind;
};
struct node2{
	int s,t;
};
struct node3{
	int v,kind,tim;
};
int c,n,M,d,Q,w[N],k[N],dis[N],vis[N];
vector<node2> a[N];
vector<node1> g[N];
queue<node3> q;
map<int,int> m[505];
void dj(int start){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[start]=0;
	q.push({start,0,0});
	while(!q.empty()){
		int v=q.front().v,kind=q.front().kind;
		q.pop();
		if(vis[v])	continue;
		vis[v]=1;
		for(int i=0;i<g[v].size();i++){
			int tv=g[v][i].v,tk=g[v][i].kind;
			if(!vis[v]){
				if(tk==kind){
					dis[tv]=min(dis[tv],tim);
					if(tim<dis[tv])	dis[tv]=tim;
					int T=tim;
					q.push({tv,tk,T});
				}
				else{
					int T=tim+a[kind][m[kind][v]].t+a[tk][m[tk][v]].t;
					dis[tv]=min(dis[tv],T);
					q.push({tv,tk,T});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>M>>d>>Q;
	for(int i=1;i<=M;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		int x,y;
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			a[j].push_back({x,y});
			m[i][x]=j;
		}
		for(int j=0;j<k[i]-1;j++)	g[a[i][j].s].push_back({a[i][j+1].s,i});
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		dj(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
