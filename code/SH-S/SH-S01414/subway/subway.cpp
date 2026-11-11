#include<bits/stdc++.h>
#define PII pair<int,int>
#define int long long
using namespace std;
const int N=510,M=500010;
int c,n,m,d,q,w[M],di[N][N];
map<pair<int,int>,int>ma;
struct Node{
	int a,t;
};
int head[N+M],nxt[2*N+2*M],to[2*N+2*M],cnt,wt[2*N+2*M];
void add(int u,int v,int ww){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
	wt[cnt]=ww;
}
int e[N][N];
int vis[N+M],d1[N+M];
bool cmp(int u,int v){
	return d1[u]<d1[v];
}
priority_queue<PII,vector<PII>,greater<PII> > qu;
void dijkstra(int u){
	memset(vis,0,sizeof(vis));
	memset(d1,0x3f,sizeof(d1));
	d1[u]=0;
	vis[u]=1;
	qu.push({0,u});
	while(!qu.empty()){
		int uu=qu.top().second;
		qu.pop();
		for(int i=1;i<=n;i++){
			if(e[uu][i])
			if(d1[i]>d1[uu]+e[uu][i]){
				d1[i]=d1[uu]+e[uu][i];
				vis[i]=1;
				qu.push({d1[i],i});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			ma[{i,a}]=t;
			add(i+m,a,t);
			add(a,i+m,t);
		}
	}
	PII e2[M][30];
	int cntt[M]={};
	for(int i=1;i<=m;i++){
		for(int j=head[i];j;j=nxt[j]){
			e2[i][cntt[i]++]={to[j],wt[j]};
		}
		for(int j=0;j<cntt[i];j++){
			for(int k=0;k<cntt[i];k++){
				if(j!=k)if(e2[i][j].second+e2[i][k].second<e[e2[i][j].first-m][e2[i][k].first-m]||e[e2[i][j].first-m][e2[i][k].first-m]==0){
					e[e2[i][j].first-m][e2[i][k].first-m]=e2[i][j].second+e2[i][k].second;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++){
			di[i][j]=d1[j];
		}
	}
	
	while(q--){
		int qx,qy;
		cin>>qx>>qy;
		int minn=0x3f3f3f3f;
		for(int j=0;j<cntt[qx];j++){
			for(int k=0;k<cntt[qy];k++){
				minn=min(minn,di[e2[qx][j].first-m][e2[qy][k].first-m]+
						ma[{e2[qx][j].first-m,qx}]
						+ma[{e2[qy][k].first-m,qy}]);
			}
			
		}
		cout<<minn+w[qx]+w[qy]<<endl;
	}
	return 0;
}
