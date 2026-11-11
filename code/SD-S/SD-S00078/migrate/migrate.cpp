#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <climits>

constexpr int N=5010,M=N*N;

using ll=long long;
using pii=std::pair<ll,int>;

// consider long long
int testcase,T;
int n;
ll d;
ll x[N],df[N];

int head[N],next[M],to[M],cntg;

ll dist[N],cnt[N];
bool st[N];
std::priority_queue<pii,std::vector<pii>,std::greater<pii>> q;

void addEdge(int u,int v){
	next[++cntg]=head[u];
	to[cntg]=v;
	head[u]=cntg;
}

void dijkstra(int s){
	for(int i=0;i<=n;i++) dist[i]=LLONG_MAX;
	memset(cnt,0,sizeof cnt);
	memset(st,false,sizeof st);
	q=std::priority_queue<pii,std::vector<pii>,std::greater<pii>>();
	
	q.push({0,s});
	dist[s]=0;
	cnt[s]=1;
	
	while(!q.empty()){
		ll d=q.top().first;
		int u=q.top().second;
		q.pop();
		
		if(st[u]) continue;
		st[u]=true;
		
//		for(int i=1;i<=n;i++) std::cout<<dist[i]<<" ";
//		std::cout<<std::endl;
//		for(int i=1;i<=n;i++) std::cout<<cnt[i]<<" ";
//		std::cout<<std::endl<<"\n\n";
		
		for(int e=head[u];e!=0;e=next[e]){
			int v=to[e];
			if(d+1<dist[v]){
				dist[v]=d+1;
				cnt[v]=1;
				q.push({dist[v],v});
			}else if(d+1==dist[v]){
				q.push({dist[v],v});
				cnt[v]++;
			}
		}
	}
}
 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	scanf("%d%d",&testcase,&T);
	if(testcase<=10){
		while(T--){
			scanf("%d%lld",&n,&d);
			
			ll res=0;
			memset(head,0,sizeof head);
			
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
			}
			for(int i=2;i<=n;i++) df[i]=x[i]-x[i-1];
//			for(int i=1;i<=n;i++) std::cout<<df[i]<<" ";
	//		std::cout<<std::endl;
			for(int i=1;i<=n;i++){
				ll sum=0;
				for(int j=i-1;j>=1;j--){
					sum+=df[j+1];
	//								std::cout<<i<<" "<<j<<":"<<sum<<std::endl;
					if(sum>d){
						break;
					}
					addEdge(i,j);
					addEdge(j,i);
	//				std::cout<<i<<" "<<j<<std::endl;
				}
			}
//			for(int i=1;i<=n;i++) addEdge(0,i),addEdge(i,0);
			for(int i=1;i<=n;i++){
				dijkstra(i);
	//			for(int j=1;j<=n;j++){
	//				std::cout<<dist[i]<<" "<<cnt[i]<<std::endl;
	//			}
	
	//for(int i=1;i<=n;i++) std::cout<<dist[i]<<" ";
	//		std::cout<<std::endl;
	//		for(int i=1;i<=n;i++) std::cout<<cnt[i]<<" ";
	//		std::cout<<std::endl<<"\n\n";
				for(int j=1;j<=n;j++){
					if(cnt[j]==2){
						res++;
					}
				}
			}
			printf("%lld\n",res/2);
		}
	}else{
		while(T--) printf("0\n");
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
