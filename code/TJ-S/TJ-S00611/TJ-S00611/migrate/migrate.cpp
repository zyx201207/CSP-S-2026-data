#include<cstdio>
#include<algorithm>
#include<queue>
int _c,T,n;long long d;
const int maxn=2e6+5;
long long a[maxn];
/*
namespace Force{
	const int maxn=9+5,maxm=maxn*maxn;
	const long long INF=0x3f3f3f3f3f3f3f3f;
	int head[maxn],next[maxm],to[maxm],len=1;long long v[maxm];
	void add(int x,int y,long long z){
		len++;
		to[len]=y,v[len]=z;
		next[len]=head[x],head[x]=len;
	}
	struct item{
		int id;long long dist;
		item(){}
		item(int id,long long dist):id(id),dist(dist){}
		friend bool operator >(item x,item y){
			return x.dist<y.dist;
		}
		friend bool operator <(item x,item y){
			return y>x;
		}
	};
	long long dist[maxn][maxn];//int cnt[maxn][maxn];
	void dijkstra(int s){
		for(int i=1;i<=n;i++) dist[s][i]=INF;//cnt[s][i]=0;
		std::priority_queue<item>q;
		q.push(item(s,dist[s][s]=0));//cnt[s][s]=1;
		while(!q.empty()){
			item tmp=q.top();q.pop();
			int x=tmp.id;long long d=tmp.dist;
			if(dist[s][x]!=d) continue;
			for(int i=head[x];i;i=next[i]){
				int y=to[i];
				//if(dist[s][y]>=dist[s][x]+v[i]){
					//if(dist[s][y]==dist[s][x]+v[i]) cnt[s][y]++;
					//else dist[s][y]=dist[s][x]+v[i],cnt[s][y]=1,q.push(item(y,dist[s][y]));
				//}
			
				if(tense(dist[s][y],dist[s][x]+v[i])) q.push(item(y,dist[s][y]));
			}
		}
	}
	int tgt,cnt;long long d;
	std::vector<int>v;
	std::vector<std::vector<int>>now;
	void dfs(){
		if(v[(int)v.size()-1]==tgt){
			if(d==dist[v[0]][tgt]){
				bool 
			}
			return 0;
		}
	}
	void solve(){
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(std::abs(a[i]-a[j])<=d) add(i,j,std::abs(a[i]-a[j]));
		for(int i=1;i<=n;i++) dijkstra(i);
		int c=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c+=cnt[i][j]==2;
		//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%5lld%c",dist[i][j]==INF?-1:dist[i][j]," \n"[j==n]);
		//puts("");
		//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%5lld%c",cnt[i][j]," \n"[j==n]);
		printf("%d\n",c);
		for(int i=1;i<=n;i++) head[i]=0;
		len=0;
	}
}
*/
namespace NotCorrect{
	const int maxn=300+5,maxm=maxn*maxn;
	const long long INF=0x3f3f3f3f3f3f3f3f;
	int head[maxn],next[maxm],to[maxm],len=1;long long v[maxm];
	void add(int x,int y,long long z){
		len++;
		to[len]=y,v[len]=z;
		next[len]=head[x],head[x]=len;
	}
	void add_double(int x,int y,long long z){
		add(x,y,z),add(y,x,z);
	}
	struct item{
		int id;long long dist;
		item(){}
		item(int id,long long dist):id(id),dist(dist){}
		friend bool operator >(item x,item y){
			return x.dist<y.dist;
		}
		friend bool operator <(item x,item y){
			return y>x;
		}
	};
	long long dist[maxn][maxn];int cnt[maxn][maxn];
	void dijkstra(int s){
		for(int i=1;i<=n;i++) dist[s][i]=INF,cnt[s][i]=0;
		std::priority_queue<item>q;
		q.push(item(s,dist[s][s]=0)),cnt[s][s]=1;
		while(!q.empty()){
			item tmp=q.top();q.pop();
			int x=tmp.id;long long d=tmp.dist;
			if(dist[s][x]!=d) continue;
			for(int i=head[x];i;i=next[i]){
				int y=to[i];
				if(dist[s][y]>=dist[s][x]+v[i]){
					if(dist[s][y]==dist[s][x]+v[i]) cnt[s][y]++;
					else dist[s][y]=dist[s][x]+v[i],cnt[s][y]=1,q.push(item(y,dist[s][y]));
				}
			}
		}
	}
	void solve(){
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(std::abs(a[i]-a[j])<=d) add_double(i,j,std::abs(a[i]-a[j]));
		for(int i=1;i<=n;i++) dijkstra(i);
		int c=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c+=cnt[i][j]==2;
		//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%5lld%c",dist[i][j]==INF?-1:dist[i][j]," \n"[j==n]);
		//puts("");
		//for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%5lld%c",cnt[i][j]," \n"[j==n]);
		printf("%d\n",c>>1);
		for(int i=1;i<=n;i++) head[i]=0;
		len=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&_c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		//Force::solve();
		NotCorrect::solve();
	}
	return 0;
}
