#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=8e5+5;
const int N=505;
ll c,n,m,d,quest,w[M],k[N],a[N][1005],t;
ll dis[M];
bool vis[M];
struct Node{
	ll v,w;
	bool operator<(const Node &x)const{
		return w>x.w;
	}
};
priority_queue<Node> q;
vector<Node> e[M];
vector<Node> s[1005];
inline void dijkstra(int s){
	for(int i=1;i<=(n+1)*(m+1);i++)
		dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	q.push((Node){s,0});
	while(!q.empty()){
		ll now=q.top().v;
		q.pop();
		if(vis[now])continue;
		vis[now]=1;
		for(int i=0;i<e[now].size();i++){
			ll v=e[now][i].v,w=e[now][i].w;
			if(dis[now]+w<dis[v]){
				dis[v]=dis[now]+w;
				q.push((Node){v,dis[v]});
			}
		}
	}
}
void solve1(){
	ll x,y;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t;
			s[a[i][j]].push_back((Node){i,t});
			int u=(i-1)*m+a[i][j];
			int v=n*m+i;
			e[u].push_back((Node){v,0});
			e[v].push_back((Node){u,0});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<s[i].size();j++){
			int u=m*(s[i][j].v-1)+i;
			int v=(n+1)*m+i;
			e[u].push_back((Node){v,s[i][j].w});
			e[v].push_back((Node){u,s[i][j].w});
		}
	}
	while(quest--){
		cin>>x>>y;
		dijkstra(x);
		ll ans=1e18;
		for(int i=y;i<=(n-1)*m+y;i+=m)
			ans=min(ans,dis[i]);
		cout<<w[x]+w[y]+ans<<'\n';
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	cin>>c>>n>>m>>d>>quest;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	if(c<=11)solve1();
	else{
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++)
				cin>>x>>y;
		}	
		while(quest--){
			cin>>x>>y;
			cout<<y-x<<'\n';
		}
	}
	return 0;
}