#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+1010;
const long long INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,qu;
long long w[M];
long long dis[M];
struct way{
	int to;
	long long ti;
};
vector<way>e[M];
struct point{
	int x;
	long long l;
	bool operator<(const point&p)const{
		return l>p.l;
	}
};
priority_queue<point>q;
void bfs(int s){
	for(int i=1;i<=n+m;i++)dis[i]=INF;
	dis[s]=0ll;
	q.push((point){s,0ll});
	while(!q.empty()){
		point t=q.top();
		q.pop();
		if(t.l>dis[t.x])continue;
		for(way tmp:e[t.x]){
			int v=tmp.to;
			long long nowdis=t.l+tmp.ti;
			if(nowdis>=dis[v])continue;
			dis[v]=nowdis;
			q.push((point){v,nowdis});
		}
	}
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int len;
		scanf("%d",&len);
		for(int j=1;j<=len;j++){
			int v;
			long long co;
			scanf("%d%lld",&v,&co);
			e[v].push_back((way){m+i,co});
			e[m+i].push_back((way){v,co});
		}
	}while(qu--){
		int s,t;
		scanf("%d%d",&s,&t);
		bfs(s);
		printf("%lld\n",w[s]+dis[t]+w[t]);
	}return 0;
}