#include<bits/stdc++.h>
#define il inline 
#define ll long long
using namespace std;
#define rep(x,l,r) for(int x=l;x<=r;++x)
#define per(x,l,r) for(int x=l;x>=r;--x)
il ll read(){
	ll f=1,k=0; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}return f*k;
}
const int N=6e5,V=1050,K=1e7+5;
int c,n,m,d,Q;
ll dis[V][V];
bool vis[N];
ll w[N];
struct op{
	int id,val; 
};
vector<op>line[N];
struct node{
	int nxt,v,w;
}E[K*2]; int head[N],tot;
il void add(int u,int v,int w){
	E[++tot]={head[u],v,w};
	head[u]=tot;
}
struct num{
	ll x,val;
};
priority_queue<num>q;
il bool operator<(num a,num b){
	return a.val>b.val;
}
il void bfs(int s){
	rep(i,1,n+m) dis[s][i]=1e18,vis[i]=0;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty()){
		num temp=q.top();
		q.pop();
		int x=temp.x;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].nxt){
			int v=E[i].v,w=E[i].w;
			if(dis[s][v]<=dis[s][x]+w) continue;
			dis[s][v]=dis[s][x]+w;
			q.push({v,dis[s][v]});
		}	
		
	}
}
il void sub1(){
	rep(i,1,m){
		bfs(i);	
	}
	while(Q--){
		int x=read(),y=read();
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
}
ll dis1[N];
il void Bfs(int s){
	rep(i,1,n+m) dis1[i]=1e18,vis[i]=0;
	dis1[s]=0;
	q.push({s,0});
	while(!q.empty()){
		num temp=q.top();
		q.pop();
		int x=temp.x;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].nxt){
			int v=E[i].v,w=E[i].w;
			if(dis1[v]<=dis1[x]+w) continue;
			dis1[v]=dis1[x]+w;
			q.push({v,dis1[v]});
		}	
	}
}
il void sub2(){
	while(Q--){
		int x=read(),y=read();
		Bfs(x);
		printf("%lld\n",dis1[y]+w[x]+w[y]);
	}
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),Q=read();
	rep(i,1,m) w[i]=read();
	rep(i,1,n){
		int k=read();
		rep(j,1,k){
			int x=read(),t=read();
			line[x].push_back({i,t});
		}
	}
	rep(i,1,m){
		for(op p:line[i]){
			int x=p.id;
			int val=p.val;
			add(i,x+m,val);
			add(x+m,i,val);
		}
	}
	if(m<=1e3) sub1();
	else if(Q<=2000){
		sub2();
	}
	
	return 0;
}

