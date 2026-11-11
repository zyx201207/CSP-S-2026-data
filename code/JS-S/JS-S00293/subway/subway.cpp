#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')w=(w<<1)+(w<<3)+(ch-'0'),ch=getchar();
	return w;
}
typedef long long LL;
typedef pair<LL,int>pii;
const int MAXN=505,MAXM=5e5+10,MAXQ=1e5+10;
const int MAXSK=5e5+10;
int C,M,N,D,Q;
int w[MAXM],K[MAXN];
vector<int>a[MAXM],t[MAXM];
struct Task{
	int x,y,id;
	inline bool operator<(const Task &b)const{
		if(x!=b.x)return x<b.x;
		return y<b.y;
	}
}task[MAXQ];
LL ans[MAXQ];
int head[MAXN+MAXM];
struct Es{int to,w,nxt;}edge[MAXSK<<1];
int __edge_cnt;
#define AddEdge(u,v,w) (edge[++__edge_cnt]={(v),(w),head[u]},head[u]=__edge_cnt)
LL dis[MAXN+MAXM];
const LL LLINF=0x3f3f3f3f3f3f3f3f;
void dijkstra(int S){
	for(int i=1;i<=N+M;++i)dis[i]=LLINF;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({dis[S]=0,S});
	while(!q.empty()){
		LL dis_=q.top().first;
		int u=q.top().second;
		q.pop();
		if(dis_!=dis[u])continue;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to,w=edge[i].w;
			if(dis[v]>dis[u]+w){
				q.push({dis[v]=dis[u]+w,v});
			}
		}
	}
}
namespace solveB{
	void solve(){
		for(int i=1;i<=N;++i){
			K[i]=read();
			a[i].reserve(K[i]),t[i].reserve(K[i]);
			for(int j=1;j<=K[i];++j){
				a[i][j]=read(),t[i][j]=read();
				AddEdge(i+M,a[i][j],t[i][j]),AddEdge(a[i][j],i+M,t[i][j]);
			}
		}
		for(int i=1;i<=Q;++i){
			task[i].x=read(),task[i].y=read(),task[i].id=i;
		}
		sort(task+1,task+1+Q);
		int last=0;
		for(int i=1;i<=Q;++i){
			if(task[i].x!=last){
				last=task[i].x,dijkstra(last);
			}
			ans[task[i].id]=dis[task[i].y]+w[task[i].x]+w[task[i].y];
		}
		for(int i=1;i<=Q;++i)printf("%lld\n",ans[i]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	// freopen("subway3.in","r",stdin);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	C=read(),N=read(),M=read(),D=read(),Q=read();
	for(int i=1;i<=M;++i){
		w[i]=read();
	}
	if(!C>=12&&C<=19){
		solveB::solve();
		return 0;
	}
	for(int i=1;i<=N;++i){
		K[i]=read();
		a[0].reserve(K[i]),t[0].reserve(K[i]);
		for(int j=1;j<=K[i];++j){
			a[0][j]=read(),t[0][j]=read();
			AddEdge(i+M,a[0][j],t[0][j]),AddEdge(a[0][j],i+M,t[0][j]);
		}
	}
	for(int i=1;i<=Q;++i){
		task[i].x=read(),task[i].y=read(),task[i].id=i;
	}
	sort(task+1,task+1+Q);
	int last=0;
	for(int i=1;i<=Q;++i){
		if(task[i].x!=last){
			last=task[i].x,dijkstra(last);
		}
		ans[task[i].id]=dis[task[i].y]+w[task[i].x]+w[task[i].y];
	}
	for(int i=1;i<=Q;++i)printf("%lld\n",ans[i]);
	
	return 0;
}