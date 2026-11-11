#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10,H=2e6+10,M=1e18;
struct Edg{
	int u,v,w,nst;
}e[H];
struct Query{
	int x,y,idd;
}qu[N];
bool cmp(Query a,Query b){
	return a.x<b.x;
}
int dis[N],w1[N],n,m,vis[N],ans[N],len,head[N];//站台到站厅
struct Node{
	int dot,cost;
	Node(int x,int y){
		dot=x,cost=y;
	}
	bool operator<(const Node b)const{
		return cost>b.cost;
	}
};

void djs(int s){
	for(int i=1;i<=m;i++)dis[i]=M,vis[i]=0;
	dis[s]=0;vis[s]=1;
	priority_queue<Node>q;
	q.push(Node(s,0));
	while(!q.empty()){
		int u=q.top().dot;
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].nst){
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w){
				dis[v]=dis[u]+e[i].w;
				if(!vis[v]){
					q.push(Node(v,dis[v]));
					vis[v]=1;
				}
			}
		}
	}
}
int c,d,q,vec[N],co[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w1[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++)cin>>vec[j]>>co[j];//vec是地铁站
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=k;p++){
				int u=vec[j],v=vec[p];
				if(u==v)continue;
				e[++len]={u,v,co[j]+co[p],head[u]};
				head[u]=len;
				swap(u,v);
				e[++len]={u,v,co[j]+co[p],head[u]};
				head[u]=len;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i].x>>qu[i].y;
		qu[i].idd=i;
	}
	sort(qu+1,qu+q+1,cmp);
	int s=0;
	for(int i=1;i<=q;i++){
		if(qu[i].x==s){
			ans[qu[i].idd]=dis[qu[i].y]+w1[qu[i].x]+w1[qu[i].y];
		}
		else{
			s=qu[i].x;
			djs(s);
			ans[qu[i].idd]=dis[qu[i].y]+w1[qu[i].x]+w1[qu[i].y];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
//扶大厦之将倾，挽狂澜于既倒