#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e6+7;
const ll inf=LONG_LONG_MAX>>1;
ll d[MAXN];
int n;
ll k;
struct Edge{
	int to,next;
}edge[MAXN*5];
int head[MAXN],cnt;
inline void add(int u,int v){
	edge[++cnt]={v,head[u]};
	head[u]=cnt;
}
int num[MAXN];
ll dis[MAXN];
queue<int> q;
bool vis[MAXN];
void bfs(int s){
	for(int i=1;i<=n;i++) num[i]=0,dis[i]=inf,vis[i]=false;
	q.push(s); num[s]=1; dis[s]=0; vis[s]=true;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=head[x];i;i=edge[i].next){
			int t=edge[i].to;
			if(dis[t]==dis[x]+1) num[t]+=num[x];
			else if(dis[t]>dis[x]+1) num[t]=num[x],dis[t]=dis[x]+1;
			if(!vis[t]) q.push(t),vis[t]=true;
		}
	}	
}
void solve1(){
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
		if(d[j]-d[i]<=k) add(i,j);
		else break; 
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++){
			if(num[j]==2) ans++;//,cout<<i<<" "<<j<<endl;
		}
	}
	printf("%d",ans);
	puts("");
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T; scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++) head[i]=0;
		cnt=0;
		for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
		solve1();
	}	
	return 0;
}