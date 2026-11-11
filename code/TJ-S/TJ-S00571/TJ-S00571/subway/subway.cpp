#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
template<typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template<typename T> bool relax(T &a,const T &b){return a<b?a=b,true:false;}

namespace Force{
	const int N = 210,M = 410;
	const long long INF = 0x3f3f3f3f3f3f3f3fll;
	int w[M];
	long long transfer[N][M];
	long long mindis[M][M];
	
	void solve(){
		int n,m,d,q;
		scanf("%d%d%d%d",&n,&m,&d,&q);
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) transfer[i][j] = INF;
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			while(k--){
				int id,t;
				scanf("%d%d",&id,&t);
				transfer[i][id] = t;
			}
		}
		for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) mindis[i][j] = INF;
		for(int k=1;k<=n;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) tense(mindis[i][j],transfer[k][i]+transfer[k][j]);
		for(int k=1;k<=m;k++) for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) tense(mindis[i][j],mindis[i][k]+mindis[k][j]);
		//for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) printf("%lld%c",mindis[i][j]," \n"[j==m]);
		while(q--){
			int s,t;
			scanf("%d%d",&s,&t);
			printf("%lld\n",mindis[s][t]+w[s]+w[t]);
		}
	}
}

namespace Better{
	const int N = 510,M = 5e5+10,Q = 1e5+10,D = 25;
	const int V = M+N,E = V*2;
	const long long INF = 0x3f3f3f3f3f3f3f3fll;
	int h[V],e[E],val[E],ne[E],idx;
	void add(int u,int v,int w){
		e[++idx] = v,val[idx] = w,ne[idx] = h[u],h[u] = idx;
	}
	long long adder[M];
	long long dist[M];
	struct Item{
		long long dist;
		int id;
		friend bool operator >(const Item &a,const Item &b){return a.dist<b.dist;}
		friend bool operator <(const Item &a,const Item &b){return b>a;}
	};
	struct Query{int s,t,id;long long ans;} query[Q];
	int n,m,d,q;
	
	void dijkstra(int s){
		for(int i=1;i<=n+m;i++) dist[i] = INF;
		std::priority_queue<Item> heap;
		heap.push({dist[s]=0ll,s});
		while(!heap.empty()){
			Item top = heap.top();
			heap.pop();
			long long d = top.dist;
			int u = top.id;
			if(d!=dist[u]) continue;
			for(int i=h[u];i;i=ne[i]){
				int v = e[i],w = val[i];
				if(tense(dist[v],dist[u]+w)) heap.push({dist[v],v});
			}
		}
	}
	void solve(){
		scanf("%d%d%d%d",&n,&m,&d,&q);
		for(int i=1;i<=m;i++) scanf("%lld",&adder[i]);
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			while(k--){
				int id,t;
				scanf("%d%d",&id,&t);
				add(id,m+i,t),add(m+i,id,t);
			}
		}
		for(int i=1;i<=q;i++) scanf("%d%d",&query[i].s,&query[i].t),query[i].id = i;
		std::sort(query+1,query+q+1,[](const Query &a,const Query &b){return a.s<b.s;});
		for(int s=1,qid=1;s<=m;s++){
			dijkstra(s);
			for(;qid<=q&&query[qid].s==s;qid++) query[qid].ans = dist[query[qid].t];
		}
		std::sort(query+1,query+q+1,[](const Query &a,const Query &b){return a.id<b.id;});
		for(int i=1;i<=q;i++) printf("%lld\n",query[i].ans+adder[query[i].s]+adder[query[i].t]);
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int testcase;
	scanf("%d",&testcase);
	if(testcase<=8) Force::solve();
	else Better::solve();
	return 0;
}


