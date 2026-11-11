#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N=5e5+51,M=551;
const ll inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
ll w[N];
vector <pair <int,ll> > g[N];
ll h[M][M];
ll k[N];
ll a[N];
ll t[N];
ll x,y;
ll ans=0;
ll dist[N];
bool vis[N];
priority_queue <pair <ll,int> > pq;
//
void dijkstra1(){
	while(!pq.empty()){
		int tp=pq.top().second;
		pq.pop();
		if(vis[tp]) continue;
		vis[tp]=1;
		for(int i=1;i<=m;i++){
			if(i==tp) continue;
			if(h[tp][i]==inf) continue;
			if(dist[i]>dist[tp]+h[tp][i]) {
				dist[i]=dist[tp]+h[tp][i];
				pq.push({-dist[i],i});
			}
		} 
	}
}
void daima1(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			h[i][j]=inf;
		} 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j]>>t[j];
			for(int u=1;u<j;u++){
				h[a[j]][a[u]]=min(h[a[j]][a[u]],t[j]+t[u]);
				h[a[u]][a[j]]=min(h[a[j]][a[u]],t[j]+t[u]);
			}
		} 
	}
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=m;j++){
			dist[j]=inf;
			vis[j]=0;
		} 
		cin>>x>>y;
		ans+=w[x]+w[y];
		pq.push({0,x});
		dist[x]=0;
		dijkstra1();
		cout<<ans+dist[y]<<endl;
	} 
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	daima1();
	return 0;
}


