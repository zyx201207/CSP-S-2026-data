#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+100,M=1e6+100;
struct edge{int to,val,nxt;}e[M];
int h[N],pe=2,c,n,m,d,que,outt[N],dist[600][600];
void add(int a,int b,int c){
	e[pe].to=b,e[pe].val=c,e[pe].nxt=h[a];
	h[a]=pe++;
}
struct node{int i,val;friend bool operator < (node a,node b){return a.val>b.val;}};
priority_queue<node> q;
bool vis[N];
inline void dijkstra(int u,int dis[600]){
	for(int i=0;i<n+50;i++){
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
	q=priority_queue<node>();
	dis[u]=0;
	node tmp;
	tmp.i=u,tmp.val=0;
	q.push(tmp);
	while(!q.empty()){
		int t=q.top().i;
		q.pop();
		if(vis[t]) continue;
		else vis[t]=1;
		for(int i=h[t];i;i=e[i].nxt){
			int to=e[i].to,val=e[i].val;
			if(dis[to]>dis[t]+val){
				dis[to]=dis[t]+val;
				tmp.i=to,tmp.val=dis[to];
				q.push(tmp);
			}
		}
	}
}
struct nodes{int a,t;};
vector<nodes> outs[N];
inline int mymin(int a,int b){
	if(a>b) return b;
	else return a;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> que;
	for(int i=1;i<=m;i++){
		cin >> outt[i];
	}
	for(int i=1,sumss;i<=n;i++){
		cin >> sumss;
		int resp=i;
		for(int j=0,a,t;j<sumss;j++){
			cin >> a >> t;
			nodes tmp;
			tmp.a=resp,tmp.t=t;
			outs[a].push_back(tmp);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<outs[i].size();j++){
			for(int k=j+1;k<outs[i].size();k++){
				add(outs[i][j].a,outs[i][k].a,outs[i][j].t+outs[i][k].t);
				add(outs[i][k].a,outs[i][j].a,outs[i][j].t+outs[i][k].t);
			}
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i,dist[i]);
	}
	for(int i=0,a,b;i<que;i++){
		cin >> a >> b;
		int res=0x3f3f3f3f;
		for(int j=0;j<outs[a].size();j++){
			for(int k=0;k<outs[b].size();k++){
				int toa=outs[a][j].a,tob=outs[b][k].a,val=outs[a][j].t+outs[b][k].t;
				res=mymin(res,dist[toa][tob]+val);
			}
		}
		cout << res+outt[a]+outt[b] << endl;
	}
	return 0;
}
