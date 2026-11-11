#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=505,M=1005;

int cas,n,m,D,q,W[M],k[N];
//int cnt[N];
int rk[M],tot;
int ans[N][N];

vector<int> a[N],t[N];
/*
每条路线内部建边，
各路线相同站点之间建权值为0的边(node用新索引
sum_k遍dic 

统计最短距离时用rk 
 
*/
struct edge{
	int v,w;
};
vector<edge> g[N];
int d[M];
void dic(int st){
	memset(d,-1,sizeof d);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push({0,st});
	d[st]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(d[u]!=-1)continue;
		for(edge e:g[u]){
			int v=e.v,w=e.w;
			if(d[v]==-1||d[u]+w<d[v]){
				d[v]=d[u]+w;
				q.push({d[v],v});
			}
		}
	}
} 

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cas>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]+2);
		t[i].resize(k[i]+2);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			rk[++tot]=a[i][j];
			a[i][j]=tot;
		}
		for(int j=1;j<=k[i];j++){
			for(int l=j+1;l<=k[i];l++){
				int u=a[i][j],v=a[i][l],w=t[i][j]+t[i][l];
				g[u].push_back({v,w});
				g[v].push_back({u,w});
			}
		}
	}
	for(int x=1;x<=tot;x++){
		for(int y=x+1;y<=tot;y++){
			if(rk[x]==rk[y]){
				g[x].push_back({y,0});
				g[y].push_back({x,0});
			}
		}
	}
	memset(ans,0x3f,sizeof ans);
	for(int x=1;x<=tot;x++){
		dic(x);
		for(int y=1;y<=tot;y++){
			int u=rk[x],v=rk[y];
			if(d[y]==-1)continue;
			ans[u][v]=min(ans[u][v],d[y]);
			ans[v][u]=min(ans[v][u],d[y]);
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		cout<<W[x]+W[y]+ans[x][y]<<'\n';
	}
	
	
	return 0;
}
//wholly ** 
//catch cache failed
