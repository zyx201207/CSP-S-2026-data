#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
struct Edge{
	int to,type;
	long long weight1,weight2;
	Edge(int to1,int tp,long long wei1,long long wei2):to(to1),type(tp),weight1(wei1),weight2(wei2){}
};
vector<Edge> v[500005];
long long w[500005];
long long dist[1005][1005];
int c,n,m,d,q;
void dijkstra(int srt){
	priority_queue<pair<pair<long long,long long>,pair<int,int>>,vector<pair<pair<long long,long long>,pair<int,int>>>,greater<pair<pair<long long,long long>,pair<int,int>>>> q;
	q.push({{0,0},{0,srt}});
	dist[srt][srt]=0;
	long long ot[1005];
	while(!q.empty()){
		long long dis=q.top().first.first;
		int u=q.top().second.second;
		long long weigh=q.top().first.second;
		int typ=q.top().second.first;
		q.pop();
		if(dis>dist[srt][u])continue;
		ot[u]=weigh;
		for(auto const &e:v[u]){
			int t=e.to;
			int p=e.type;
			long long w1=e.weight1;
			long long w2=e.weight2;
			int weigh1=weigh;
			if(typ==p){
				w1=0;
				weigh=0;
			}
			if(dis+w1+weigh<dist[srt][t]){
				dist[srt][t]=dis+w1+weigh;
				q.push({{dist[srt][t],w2},{p,t}});
			}
			weigh=weigh1;
		}
	}
	for(int i=1;i<=m;i++){
		if(i==srt){
			continue;
		}
		dist[srt][i]+=w[srt]+w[i]+ot[i];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		if(k==0)continue;
		int a1,a2;
		long long t1,t2;
		scanf("%d%lld",&a1,&t1);
		for(int j=1;j<=k;j++){
			scanf("%d%lld",&a2,&t2);
			v[a1].push_back(Edge(a2,i,t1,t2));
			a1=a2;
			t1=t2;
		}
	}
	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++){
			dist[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dist[x][y]);
	}
	return 0;
}
