#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=1e6+2,mxm=8e6+2;
int a[mxn],ki[505],dis[mxm],c,n,m,d,q;
inline int f(int u,int x){
	return u+x*m;
}
struct edge{
	int u,v,w,nxt;
}e[mxm];
struct node{
	int id,val;
	bool operator <(const node &p) const{
		return val>p.val;
	}
};
int head[mxm],len;
inline void Insert(int u,int v,int w){
	e[++len]={u,v,w,head[u]},head[u]=len;
}
bool vis[mxm];
void dijkstra(int st){
	priority_queue<node> q;
	for(int i=1;i<=n*m;i++) vis[i]=0,dis[i]=114514114514114514ll;
	q.push({st,0});
	dis[st]=0;
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				q.push({v,dis[v]});
			}
		}
	}
}
int w[mxm+mxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int y,z,tmp;
		cin>>ki[i];
		for(int j=1;j<=ki[i];j++){
			tmp=y;
			cin>>y>>z;
			if(j>1){
				Insert(f(tmp,i),f(y,i),0);
				Insert(f(y,i),f(tmp,i),0);
			}
			w[f(y,i)]=z;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				if(j!=k&&((w[f(i,j)]&&w[f(i,k)])||(!j)||(!k))){
					Insert(f(i,j),f(i,k),w[f(i,j)]+w[f(i,k)]);
				}
			}
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		dijkstra(l);
		cout<<dis[r]+a[l]+a[r]<<endl;
	}
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
*/