#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char ch=getchar();
	int op=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return op*x;
}
const int N=509;
const int INF=1e18;
const int M=5e5+9;
int C,n,m,D,Q;
int pw[M];
int addcnt,head[M],nxt[2*M],to[2*M],w[2*M];
void add(int u,int v,int W){
	to[++addcnt]=v;
	w[addcnt]=W;
	nxt[addcnt]=head[u];
	head[u]=addcnt;
}
struct Node{
	int u,d;
	bool operator<(const Node a)const{return a.d<d;
	}
};
bool vst[M];
bool vis[N][N];
vector<int> ln[M];
vector<int> cst[M];
void solve(){
	for(int i=1;i<=m;i++){
		pw[i]=read();
	}
	for(int i=1;i<=n;i++){
		int K=read();
		for(int j=1;j<=K;j++){
			int ai=read(),ti=read();
			ln[ai].push_back(i);
			cst[ai].push_back(ti);
		}
	}
	
	int dis[n+1][n+1];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<ln[i].size();j++){
			for(int k=j+1;k<ln[i].size();k++){
				int u=ln[i][j],v=ln[i][k];
				int W=cst[i][j]+cst[i][k];
				if(!vis[u][v]){
					add(u,v,W);
					add(v,u,W);
					vis[u][v]=vis[v][u]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		priority_queue<Node> q;
		q.push((Node){i,0});
		while(!q.empty()){
			int u=q.top().u;
			q.pop();
			if(vst[u]){
				continue;
			}
			vst[u]=1;
			for(int j=head[u];j;j=nxt[j]){
				int v=to[j];
				if(dis[i][v]>dis[i][u]+w[j]){
					dis[i][v]=dis[i][u]+w[j];
					if(!vst[v]){
						q.push((Node){v,dis[i][v]});
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			vst[j]=0;
		}
	}
	
	int ans=INF;
	for(int i=1;i<=Q;i++){
		int x=read(),y=read();
		ans=INF;
		for(int j=0;j<ln[x].size();j++){
			for(int k=0;k<ln[y].size();k++){
				ans=min(ans,cst[x][j]+cst[y][k]+dis[ln[x][j]][ln[y][k]]);
			}
		}
		cout<<pw[x]+pw[y]+ans<<'\n';
	}
	
	return ;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();
	n=read();
	m=read();
	D=read();
	Q=read();
	solve();
	return 0;
}
