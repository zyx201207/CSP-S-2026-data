#include<bits/stdc++.h> 
using namespace std;
#define ll long long 
#define N 500000
const ll INF =2147483637/2-1;
const ll MOD=1e9+7;
const ll DEL=30000;
int c,n,m,d,q;
int dis[N],vis[N],ka[N],kaa[N];
struct node{
	int v, w;
};
vector<node> g[DEL*3];

struct cmp{
	bool operator ()(node n1,node n2){
		return n1.w<n2.w;
	}
};
priority_queue<node,vector<node>,cmp> pq;
node crt(int v,int w){
	node n1;
	n1.v=v,n1.w=w;
	return n1;
}
void djs(int u){
	if(!pq.empty())pq.pop();
	for(int i=1;i<=m;i++)dis[i]=INF,vis[i]=0;
	dis[u]=0;
	pq.push(crt(u,0));
	while(!pq.empty()){
		int u=pq.top().v;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].v,w=g[u][i].w;
			if(!vis[v]){
				if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push(crt(v,dis[v]));
			}
			}
			
		}
	}
}
int main(){
	freopen("crystal3.in","r",stdin);
	freopen("crystal3.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		g[i].push_back(crt(DEL+i,x));
		g[DEL+i].push_back(crt(i,x));
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int kacnt=0,kaacnt=0;
		for(int j=1;j<=k;j++){
			int ai,ti;
			cin>>ai>>ti;
			g[0].push_back(crt(ai,0));
			ka[++kacnt]=ti;
			kaa[++kaacnt]=ai;
		}
		for(int j=1;j<=k;j++){
			g[0].push_back(crt(kaa[j],0));
			g[kaa[j]+DEL].push_back(crt(kaa[j]+DEL*2,ka[j]));
			for(int fu=j+1;fu<=k;fu++){
				g[kaa[j]+DEL*2].push_back(crt(DEL+kaa[fu],0));
			}
		}
	}
	for(int i=1;i<=q;i++){
		int cx,cy;
		cin>>cx>>cy;
		djs(cx);
		cout<<dis[cy];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
