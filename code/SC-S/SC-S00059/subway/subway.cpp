#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int V[N];
int k[510];
int a[510][5100],t[510][5100],num[N],cnt,head[N];
int T=-1;
struct node{
	int to,next,w;
}e[N*20*4];
void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
//num——站口i所对的站厅
//bool fB=0;
int dis[5001][5001];
int vis[N*20];
void dj(int s){
	for(int i=1;i<=m*21;i++){
		dis[s][i]=1e9+7;
		vis[i]=0;
	}
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,s});
	dis[s][s]=0;
	while(!q.empty()){
		
		int u=q.top().second;
		q.pop();
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next){
			
			int v=e[i].to;
//			cout <<"u:" << u << "v:" << v << endl;
			if(vis[v]) continue;
			if(dis[s][v]>dis[s][u]+e[i].w){
				dis[s][v]=dis[s][u]+e[i].w;
				q.push({dis[s][v],v});
			}
		}
	}
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> V[i];
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
//			if(T==-1) T=t[i][j];
//			else if(T!=t[i][j]){
//				fB=1;
//			}
			int na=m+(a[i][j]-1)*d+(++num[a[i][j]]);
			int nb=m+(a[i][j-1]-1)*d+(num[a[i][j-1]]);
//			cout << na << " " << nb << endl;
			add(a[i][j],na,t[i][j]);
			add(na,a[i][j],t[i][j]);
			if(j>=2){
				add(na,nb,0);
				add(nb,na,0);
			}
		}
	}
	for(int i=1;i<=m;i++){
		dj(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << dis[x][y]+V[x]+V[y] << endl;
	}
//	if(!fB){
//		
//	}
	return 0;
}