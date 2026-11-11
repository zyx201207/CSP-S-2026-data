#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
//         1234567
#define M 500003
#define N 503
#define D 25000000
#define Q 100003
#define K M
int c,n,m,d,q;
int w[M];
int hd[M+N],nx[D],to[D],ti[D];
int cnt=1;
inline void add(int u,int v,int t){
	to[cnt]=v;
	nx[cnt]=hd[u];
	ti[cnt]=t;
	hd[u]=cnt;
	cnt++;
}
inline void addd(int u,int v,int t){
	add(u,v,t);
	add(v,u,t);
}
inline void cleang(){
	cnt=1;
}
struct tt{
	int node,dis;
	bool operator<(const tt&oth)const{
		return dis>oth.dis;
	}
};
int djs(int u,int v){
	priority_queue<tt> pq;
	pq.push(tt{u,0});
	while(!pq.empty()){
		int node=pq.top().node;
		int dis=pq.top().dis;
		pq.pop();
		for(int ei=hd[node];ei!=0;ei=nx[ei]){
			if(to[ei]!=node){
				if(to[ei]==v){
					return dis+ti[ei];
				}
				pq.push(tt{to[ei],dis+ti[ei]});
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;++i){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;++j){
			int a,t;
			scanf("%d%d",&a,&t);
			addd(m+i,a,t);
		}
	}
	for(int i=0;i<q;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=w[x]+w[y]+djs(x,y);
		printf("%d\n",ans);
		cleang();
	}
}