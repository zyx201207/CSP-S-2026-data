#include<bits/stdc++.h>
#define ull unsigned long long
#define int long long
using namespace std;
const int inf=1e18;
const int maxn=505;
const int maxm=500005;
const int maxq=100005;
int dis[maxn][maxn];
int vis[maxn];
int w[maxm];
int k[maxn];
int p[maxm];
int t[maxm];
int C;
int n,m,d,q;
int ans;
struct node{
	int x;
	int w;
	bool friend operator<(const node p,const node q){
		return p.w>q.w;
	}
};
vector<node> a[maxm];
struct edge{
	int x;
	int y;
}r[maxq];
void dijkstra(int sx){
	for(int i=1;i<=m;i++){
		dis[sx][i]=inf;;
		vis[i]=0;
	}
	priority_queue<node> que;
	node now={sx,0};
	que.push(now);
	dis[sx][sx]=0;
	while(!que.empty()){
		node p=que.top();
		que.pop();
		if(vis[p.x]) continue;
		vis[p.x]=1;
		int l=a[p.x].size();
		for(int i=0;i<l;i++){
			int nx=a[p.x][i].x;
			if(dis[sx][p.x]+a[p.x][i].w<dis[sx][nx]){
				dis[sx][nx]=dis[sx][p.x]+a[p.x][i].w;
				node pp={nx,dis[sx][nx]};
				que.push(pp);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>p[j]>>t[j];
		for(int j=1;j<k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				a[p[j]].push_back((node){p[l],t[j]+t[l]});
				a[p[l]].push_back((node){p[j],t[j]+t[l]});
			}
		}
	}
	for(int i=1;i<=m;i++) dijkstra(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y]+dis[x][y];
		cout<<ans<<"\n";
	}
	return 0;
}
