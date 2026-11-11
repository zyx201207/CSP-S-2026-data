#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int maxn=2e6+10;
int c,t;
int n,d;
int x[maxn];
struct node{
	int to,next;
}e[301*301];
int head[maxn],tot;
void add(int u,int v){
	e[++tot].to=v;
	e[tot].next=head[u];
	head[u]=tot;
}
struct qnode{
	int u,w;
	bool operator<(const qnode& other)const{
		return w>other.w;
	}
};
bitset<maxn> vis;
void dij(int s,int dis[],int cnt[]){
	fill(dis+1,dis+n+1,1e18);
	fill(cnt+1,cnt+n+1,0);
	vis.reset();
	priority_queue<qnode> pq;
	pq.push({s,0}); dis[s]=0; cnt[s]=1;
	while(!pq.empty()){
		qnode qn=pq.top(); pq.pop();
		if(vis[qn.u]) continue;
		vis[qn.u]=1;
		for(int i=head[qn.u];i;i=e[i].next){
			int v=e[i].to;
			if(dis[v]>dis[qn.u]+1){
				dis[v]=dis[qn.u]+1;
				pq.push({v,dis[v]});
			}
			if(dis[v]==dis[qn.u]+1) cnt[v]+=cnt[qn.u];
		}
	}
}
int dis[301][301],cnt[301][301];
bool check(){
	int D=x[2]-x[1];
	for(int i=2;i<n;i++){
		if(x[i+1]-x[i]!=D) return 0;
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		if(check()){
			int D=x[2]-x[1];
			if(d/D<=1) cout<<0<<endl;
			else{
				int L=2*(d/D)-1;
				if(n-L<=0) cout<<0<<endl;
				else cout<<n-L<<endl;
			} 
		}
		else if(n<=300){
			for(int i=1;i<=n;i++){
				int id=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				for(int j=i+1;j<=id;j++) add(i,j);
			}
			for(int i=1;i<=n;i++) dij(i,dis[i],cnt[i]);
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(cnt[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
			memset(head,0,sizeof(int)*(n+1)); tot=0;
		}
		else cout<<0<<endl;
	}
	return 0;
}
/*
16：10 不会啊，暴力！ 
16: 22 24pts
17：22 进行了一个特殊性质的打，24->32
*/