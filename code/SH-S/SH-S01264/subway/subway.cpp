#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
const long long INF=1e8;
ll dis[20];
int c,n,m,d,q;

int e[1000][1000],to[1000][1000],num[1000],w[MAXN];

void addEdge(int u,int v,int w){
	e[u][v]=w;
	to[u][num[u]+1]=v;
	num[u]++;
	
	e[v][u]=w;
	to[v][num[v]+1]=u;
	num[v]++;
}

void dijkstra(int s){
	
	for(int i=1;i<=m;i++)dis[i]=INF;
	dis[1]=0;
	
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
	q.push(make_pair(0,s));
	
	while(!q.empty()){
		pair<ll,int> cur=q.top();
		q.pop();
		ll d=cur.first;
		int u=cur.second;
		if(d>dis[u])continue;
		
		for(int i=1;i<=num[u];i++){
			if(d+e[u][to[u][i]]<dis[to[u][i]]){
				dis[to[u][i]]=d+e[u][to[u][i]];
				q.push(make_pair(dis[to[u][i]],to[u][i]));
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int tmp1,tmp2,tmp3,tmp4;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			if(j==1){
				cin>>tmp1>>tmp2;
			}
			else if(j==2){
				cin>>tmp3>>tmp4;
				addEdge(tmp1,tmp3,tmp2+tmp4);
				tmp2=tmp3;
			}
			else{
				cin>>tmp3>>tmp4;
				addEdge(tmp2,tmp3,tmp4);
				tmp2=tmp3;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		dijkstra(a);
		cout<<dis[b]+w[a]+w[b]<<endl;
	}
	
	return 0;
}
