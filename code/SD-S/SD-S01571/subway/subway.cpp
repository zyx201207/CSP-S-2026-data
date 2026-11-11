#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+505; 
const int inf=0x3f3f3f3f;
int w[N];
struct node{
	int v,w;
	node(int v1,int w1){
		v=v1;w=w1;
	}
};
struct edge{
	int s,d;
	bool operator <(const edge x)const{
		return d>x.d;
	}
	edge(int s1,int d1){
		s=s1,d=d1;
	}
};
int c,n,m,d,q;
vector<node>e[N];
int k,a,t;
int dis[N][505];
bool in[N];
//priority_queue<int>q;
inline int dij(int st){
	//printf("dij(%d,%d):\n",st,t);
	for(int i=1;i<=m+n;i++)dis[i][st-m]=inf,in[i]=0;
	priority_queue<edge>q;
	dis[st][st-m]=0;
	edge qw(st,0);
	q.push(qw);
	in[st]=1;
	while(!q.empty()){
		int u=q.top().s;q.pop();
		for(node v1:e[u]){
			int v=v1.v,w=v1.w;
			if(in[v])continue;
			//printf("v=%d,u=%d,dis[v][st-m]=%d,dis[u][st-m]+w=%d+%d=%d\n",v,u,dis[v][st-m],dis[u][st-m],w,dis[u][st-m]+w);
			if(dis[v][st-m]>dis[u][st-m]+w){
				dis[v][st-m]=dis[u][st-m]+w;
				if(!in[v]){
					qw.s=v,qw.d=dis[v][st-m];
					q.push(qw);
					in[v]=1;
				}
			}
		}
	}
	//printf("\n");
}
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	//freopen("subway5.in","r",stdin);//freopen("subway.ans","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			node q(m+i,t);
			e[a].push_back(q);
			q.v=a;
			e[m+i].push_back(q);
		}
	}
	for(int i=1;i<=n;i++){
		dij(i+m);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=inf;
		for(int j=1;j<=n;j++){
			ans=min(ans,dis[x][j]+dis[y][j]);
		}
		printf("%d\n",ans+w[x]+w[y]);
	}
	return 0;
} 
