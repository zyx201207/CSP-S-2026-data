#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
template<typename T>bool tense(T &a,const T &b){return a>b?a=b,true:false;}
int _c,n,m,d,q;
const int maxn=5e5+5,maxm=500+5,maxq=1e5+5,maxd=20+5;
long long a[maxn];
std::vector<std::pair<int,int>>G[maxn];
std::vector<std::pair<int,long long>>v[maxn];
struct Query{int x,y,id;long long ans;}Q[maxq];
namespace Force{
	const int maxn=1000+5,maxm=500+5,maxd=20+5;
	long long val[maxn][maxm];
	struct item{
		int id,w;long long dist;
		item(){}
		item(int id,int w,long long dist):id(id),w(w),dist(dist){}
		friend bool operator >(item x,item y){
			return x.dist<y.dist;
		}
		friend bool operator <(item x,item y){
			return y>x;
		}
	};
	long long dist[maxn][maxm];
	void dijkstra(int s){
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dist[i][j]=0x3f3f3f3f3f3f3f3f;
		std::priority_queue<item>q;
		for(auto id:v[s]) q.push(item(s,id.first,dist[s][id.first]=id.second));
		while(!q.empty()){
			item tmp=q.top();q.pop();
			int x=tmp.id,w=tmp.w;long long d=tmp.dist;
			if(dist[x][w]!=d) continue;
			for(auto i:v[x]){
				if(tense(dist[x][i.first],d+val[x][w]+i.second)) q.push(item(x,i.first,dist[x][i.first]));
			}
			for(auto i:G[x]) if(i.second==w){
				int y=i.first;
				if(tense(dist[y][w],d)) q.push(item(y,w,dist[y][w]));
			}
		}
	}
	void solve(){
		for(int i=1;i<=n;i++) for(auto t:v[i]) val[i][t.first]=t.second;
		std::sort(Q+1,Q+q+1,[](Query x,Query y){return x.x<y.x;});
		for(int i=1;i<=q;i++){
			if(i==1||Q[i].x!=Q[i-1].x) dijkstra(Q[i].x);
			Q[i].ans=0x3f3f3f3f3f3f3f3f;
			for(auto id:v[Q[i].y]) tense(Q[i].ans,dist[Q[i].y][id.first]+id.second+a[Q[i].x]+a[Q[i].y]);
		}
		//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("dist[%d][%d]=%d\n",i,j,dist[i][j]);
		std::sort(Q+1,Q+q+1,[](Query x,Query y){return x.id<y.id;});
		for(int i=1;i<=q;i++) printf("%lld\n",Q[i].ans);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&_c,&m,&n,&d,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1,num;i<=m;i++){
		scanf("%d",&num);
		for(int j=1,id=0;j<=num;j++){
			int last=id;long long x;
			scanf("%d%lld",&id,&x);
			v[id].push_back(std::make_pair(i,x));
			if(id) G[id].push_back(std::make_pair(last,i)),G[last].push_back(std::make_pair(id,i));
		}
	}
	for(int i=1;i<=q;i++) scanf("%d%d",&Q[i].x,&Q[i].y),Q[i].id=i;
	Force::solve();
	return 0;
}
