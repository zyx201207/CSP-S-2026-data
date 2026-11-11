#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll inf=2e18;
namespace zyx_{

ll read(){
	ll x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar('0'+x%10);
	return ;
}
struct edge{
	int to,len;
};
struct ask{
	int x,y,idx;
}q[N];
bool cmp1(ask a,ask b){
	if(a.x==b.x) return a.y<b.y;
	return a.x<b.x;
}
vector<edge> g[N];
ll c,n,m,d,Q;
ll w[N],t[N],s[N],ans[N];
ll dis[N];
bool vis[N];
struct node{
	int num,val;
	friend bool operator<(node a,node b){
		return a.val>b.val;
	}
};
void dijkstra(int x){
	for(int i=1;i<=m;i++) dis[i]=inf,vis[i]=false;
	priority_queue<node> pq;
	pq.push((node){x,0}); dis[x]=0;
	while(!pq.empty()){
		node tmp=pq.top(); pq.pop();
		int u=tmp.num; ll l=tmp.val;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to; ll w=g[u][i].len;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push((node){v,dis[v]});
			}
		}
	}
	return ;
}
int my_main(){
	c=read(); n=read(); m=read(); d=read(); Q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		ll k; k=read();
		for(int j=1;j<=k;j++){
			s[j]=read(); t[j]=read();
		}
		for(int j=1;j<=k;j++)
			for(int l=1;l<j;l++){
				int v=max(s[j],s[l]),u=min(s[j],s[l]);
				g[u].push_back((edge){v,t[j]+t[l]});
			}
	}
	for(int i=1;i<=Q;i++){
		ll x,y; x=read(); y=read();
		q[i].x=min(x,y); q[i].y=max(x,y); q[i].idx=i;
		ans[i]+=(w[q[i].x]+w[q[i].y]);
	}
	sort(q+1,q+Q+1,cmp1);
	for(int i=1;i<=Q;i++){
		if(q[i].x!=q[i-1].x) dijkstra(q[i].x);
		ans[q[i].idx]+=dis[q[i].y];
	}
	for(int i=1;i<=Q;i++) print(ans[i]),putchar('\n');
	return 0;
}

}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	zyx_::my_main();
	return 0;
}
