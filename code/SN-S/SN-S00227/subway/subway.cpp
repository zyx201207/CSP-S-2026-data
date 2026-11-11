#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int c,n,m,d,q,W[MAXN];
int diss[505][505];
struct node{
	int pos,dis;
};
struct ques{
	int st,ed,ans,id;
}qu[100005];
vector<node> st[MAXN];
bool f[MAXN];
//----------------------------
int h[MAXN<<1],cnt;
struct edge{
	int v,nxt,w;
}e[MAXN<<1];
void add(int u,int v,int w){
	e[++cnt].v=v;e[cnt].w=w;
	e[cnt].nxt=h[u];h[u]=cnt;
}
//---------------------------
struct node1{
	int dis,pos;
	bool operator <(const node1 &x)const{
		return dis>x.dis;
	}
};
priority_queue<node1> que;
int dis[MAXN],vis[MAXN];
void dij(int s){
	dis[s]=0;
	que.push({0,s});
	while(!que.empty()){
		int u=que.top().pos;que.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				que.push({dis[v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			diss[i][j]=0x7f7f7f7f7f7f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			st[a].push_back({i,t});
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i].st>>qu[i].ed;
		f[qu[i].st]=f[qu[i].ed]=1;
		qu[i].id=i;qu[i].ans=W[qu[i].st]+W[qu[i].ed];
	}
	for(int i=1;i<=m;i++){
		for(auto u:st[i]){
			for(auto v:st[i]){
				int u1=u.pos,dis1=u.dis;
				int v1=v.pos,dis2=v.dis;
				if(u1==v1) continue;
				diss[u1][v1]=min(diss[u1][v1],dis1+dis2);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			add(i,j,diss[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		if(f[i]){
			for(auto v:st[i]){
				int v1=v.pos,dis1=v.dis;
				add(i+n,v1,dis1);
			}
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++) dis[j]=0x7f7f7f7f7f7f,vis[j]=0;
		dis[qu[i].st+n]=0x7f7f7f7f7f7f;
		vis[qu[i].st+n]=0;
		dij(qu[i].st+n);
		int ans=0x7f7f7f7f7f7f;
		for(auto v:st[qu[i].ed]){
			int v1=v.pos,dis1=v.dis;
			ans=min(dis[v1]+dis1,ans);
		}
		cout<<ans+qu[i].ans<<"\n";
	}
	return 0;
}
