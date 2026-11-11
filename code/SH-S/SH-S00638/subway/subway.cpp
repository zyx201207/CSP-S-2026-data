#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5;
int c,n,m,d,Q,cnt,head[maxm];
long long w[maxm],dis[maxm];
bool vis[maxm];
struct edge{int v,nxt;long long w;}e[2*maxm];
struct node{
	int u;long long w;
	bool operator<(const node&x)const{
		return w>x.w;
	}
};
void add_edge(int u,int v,int w){
	e[++cnt]={v,head[u],w};
	head[u]=cnt;
}
priority_queue<node>q;
int dij(int st,int ta){
	dis[st]=0;
	q.push({st,0});
	while(!q.empty()){
		node f=q.top();q.pop();
		if(!vis[f.u]){
			vis[f.u]=true;
			int u=f.u;
			for(int i=head[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(dis[v]>=e[i].w+dis[u]){
					dis[v]=e[i].w+dis[u];
					q.push({v,dis[v]});
				}
			}
		}
	}
	return dis[ta];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;long long t;cin>>a>>t;
			add_edge(a,m+i,t);
			add_edge(m+i,a,t);
		}
	}
	while(Q--){
		memset(dis,0x3f,sizeof(dis));
		memset(vis,false,sizeof(vis));
		int x,y;cin>>x>>y;
		cout<<dij(x,y)+w[x]+w[y]<<endl;
	}
	return 0; 
}
