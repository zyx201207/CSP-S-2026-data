#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
struct bb{
	int x,val;
};
vector<bb> bbb[505];
int alen[N];
int len[505];
int minn[505][505];
struct node{
	int x,val;
}a[N][25];
struct edge{
	int v,w;
	friend bool operator <(const edge &p,const edge &q){
		return p.w>q.w;
	}
};
vector<edge> e[N];
int ans[505][505];
bool vis[N];
void djkstra(int x){
	memset(vis,0,sizeof vis);
	priority_queue<edge> pq;
	pq.push((edge){x,0});
	while(!pq.empty()){
		edge xx=pq.top();
		pq.pop();
		if(vis[xx.v])continue;
		vis[xx.v]=1;
		for(edge i:e[xx.v]){
			if(ans[x][xx.v]+i.w<=ans[x][i.v]){
				ans[x][i.v]=ans[x][xx.v]+i.w;
				pq.push((edge){i.v,ans[x][i.v]});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(minn,0x3f,sizeof minn);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		len[i]=k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			bbb[i].push_back((bb){x,y});
			a[x][alen[x]+1]=(node){i,y};
			alen[x]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<len[i];j++){
			bb idxx=bbb[i][j];
			int idx=idxx.x;
			for(int k=1;k<=alen[idx];k++){
				if(i==a[idx][k].x)continue;
				int x=a[idx][k].x;
				minn[i][x]=minn[x][i]=min(min(minn[i][x],minn[x][i]),bbb[i][j].val+a[idx][k].val);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(minn[i][j]!=0x3f3f3f3f3f3f3f3f){
				e[i].push_back((edge){j,minn[i][j]});
				e[j].push_back((edge){i,minn[i][j]});
			}
		}
	}
	memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=n;i++){
		ans[i][i]=0;
	} 
	for(int i=1;i<=n;i++){
		djkstra(i);
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int anss=1e16;
		for(int j=1;j<=alen[u];j++){
			for(int k=1;k<=alen[v];k++){
				anss=min(anss,a[u][j].val+a[v][k].val+ans[a[u][j].x][a[v][k].x]);
			}
		}
		cout<<anss+w[u]+w[v]<<"\n";
	}
	return 0;
}
