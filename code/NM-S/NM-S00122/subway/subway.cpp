#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll c,n,m,d,q,T[N],a[N],t[N];
struct Edge{
	ll to,val;
	bool operator>(const Edge e)const{return val>e.val;}
};
vector<Edge> G[N];
void add(int u,int v,int w){
	Edge r;
	r.to=v,r.val=w;
	G[u].push_back(r);
	return ;
}
void dijkstra(int s,int w){
	ll dist[N],pre[N];
	memset(dist,0x3f3f3f3f,sizeof(dist));
	dist[s]=0;
	priority_queue<Edge,vector<Edge>,greater<Edge> > pq;
	Edge r;
	r.to=s,r.val=0;
	pq.push(r);
	while(!pq.empty()){
		Edge r=pq.top();
		pq.pop();
		if(dist[r.to]<r.val) continue;
		for(int j=0;j<G[r.to].size();j++){
			Edge i=G[r.to][j];
			if(dist[i.to]>dist[r.to]+i.val){
				dist[i.to]=dist[r.to]+i.val;
				Edge r;
				r.to=i.to,r.val=dist[i.to];
				pq.push(r);
			}
		}
	}
	cout<<dist[w]+T[s]+T[w]<<endl;
	return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>T[i];
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int j=1;j<=k;j++){
			for(int u=1;u<=k;u++){
				if(j==u) continue;
				add(a[j],a[u],t[j]+t[u]);
			}
		}
	}
	while(q--){
		int fr,too;
		cin>>fr>>too;
		dijkstra(fr,too);
	}
	return 0;
}
