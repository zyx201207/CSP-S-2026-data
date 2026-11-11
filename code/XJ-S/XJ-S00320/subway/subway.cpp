#include<bits/stdc++.h>
using namespace std;
int c,n,m,D,q;
namespace sub1{
const int N=5e5+5;
int a[N];
int head[N<<1],ver[N<<1],nxt[N<<1],edge[N<<1],tot;
long long d[N<<1];
bool vis[N<<1];
int nodecnt;
void addedge(int x,int y,int w){
	ver[++tot]=y;
	edge[tot]=w;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct Node{
	int x;
	long long w;
	bool operator < (Node t) const{
		return w>t.w;
	} 
};
void dijkstra(int s){
	for(int i=1;i<=nodecnt;i++) vis[i]=0;
	for(int i=1;i<=nodecnt;i++) d[i]=1e18;
	d[s]=0;
	priority_queue<Node> q;
	q.push({s,d[s]});
	while(!q.empty()){
		int x=q.top().x;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i],w=edge[i];
			if(d[x]+w<d[y]){
				d[y]=d[x]+w;
				q.push({y,d[y]});
			} 
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++) cin >> a[i];
	nodecnt=n;
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		nodecnt++;
		for(int j=1;j<=k;j++){
			int x,y;
			cin >> x >> y;
			addedge(x,nodecnt,y);
			addedge(nodecnt,x,y);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		dijkstra(x);
		cout << d[y]+a[x]+a[y] << '\n';
	}
}
}
namespace sub2{
const int N=1e3+5;
int a[N];
int head[N<<1],ver[N<<1],nxt[N<<1],edge[N<<1],tot;
long long d[N<<1];
bool vis[N<<1];
long long f[N][N];
int nodecnt;
void addedge(int x,int y,int w){
	ver[++tot]=y;
	edge[tot]=w;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct Node{
	int x;
	long long w;
	bool operator < (Node t) const{
		return w>t.w;
	} 
};
void dijkstra(int s){
	for(int i=1;i<=nodecnt;i++) vis[i]=0,d[i]=1e18;
	d[s]=0;
	priority_queue<Node> q;
	q.push({s,d[s]});
	while(!q.empty()){
		int x=q.top().x;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i],w=edge[i];
			if(d[x]+w<d[y]){
				d[y]=d[x]+w;
				q.push({y,d[y]});
			} 
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++) cin >> a[i];
	nodecnt=n;
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		if(k==1){
			int x,y;
			cin >> x >> y;
		}else if(k==2){
			int fx,sx,fy,sy;
			cin >> fx >> sx >> fy >> sy;
			addedge(fx,fy,sx+sy);
			addedge(fy,fx,sx+sy); 
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++){
			f[i][j]=d[j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << f[x][y]+a[x]+a[y] << '\n';
	}
}
}
namespace sub3{
const int N=5e5+5;
int a[N];
int head[N<<1],ver[N<<1],nxt[N<<1],edge[N<<1],tot;
long long d[N<<1];
bool vis[N<<1];
int nodecnt;
void addedge(int x,int y,int w){
	ver[++tot]=y;
	edge[tot]=w;
	nxt[tot]=head[x];
	head[x]=tot;
}
struct Node{
	int x;
	long long w;
	bool operator < (Node t) const{
		return w>t.w;
	} 
};
void BFS(int s){
	for(int i=1;i<=nodecnt;i++) vis[i]=0;
	for(int i=1;i<=nodecnt;i++) d[i]=1e18;
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=ver[i],w=edge[i];
			if(d[x]+w<d[y]){
				d[y]=d[x]+w;
				q.push(y);
			}
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++) cin >> a[i];
	nodecnt=n;
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		nodecnt++;
		for(int j=1;j<=k;j++){
			int x,y;
			cin >> x >> y;
			addedge(x,nodecnt,y);
			addedge(nodecnt,x,y);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		BFS(x);
		cout << d[y]+a[x]+a[y] << '\n';
	}
}
}
namespace sub4{
const int N=5e5+5,M=505;
int a[N];
long long f[M][M];
struct Node{
	int cnt;
	int k[25];
	int t[25];
}b[N];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]); 
			} 
		}
	} 
}
long long query(int x,int y){
	long long ret=1e18;
	for(int i=1;i<=b[x].cnt;i++){
		for(int j=1;j<=b[y].cnt;j++){
			int s=b[x].k[i],t=b[y].k[j];
			ret=min(ret,f[s][t]+b[x].t[i]+b[y].t[j]);
		}
	}
	return ret;
}
void solve(){
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=m;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin >> x >> y;
			b[x].cnt++;
			b[x].k[b[x].cnt]=i,b[x].t[b[x].cnt]=y;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j) f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int tt=1;tt<=n;tt++){
		for(int i=1;i<=b[tt].cnt;i++){
			for(int j=i+1;j<=b[tt].cnt;j++){
				int x=b[tt].k[i],y=b[tt].k[j],w=b[tt].t[i]+b[tt].t[j];
				f[x][y]=min(f[x][y],1ll*w);
				f[y][x]=min(f[y][x],1ll*w);
			}
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin >> x >> y;
		cout << query(x,y)+a[x]+a[y] << '\n';
	}
}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> c >> m >> n >> D >> q;
	if(1<=c&&c<=6){
		sub1::solve();
	}else if(7<=c&&c<=11){
		sub2::solve();
	}else if(12<=c&&c<=15){
		sub3::solve();
	}else{
		sub4::solve();
	} 
	return 0;
}
