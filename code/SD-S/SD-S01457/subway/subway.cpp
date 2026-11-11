#include<bits/stdc++.h>
#define ll long long
#define re register
#define pa pair
using namespace std;
const int N=5e5+5;
const ll INF=INT_MAX;
ll a[N],nex[N*2],to[N*2],val[N*2],head[N],tot,n,m,d,q,c,dis[N+5000];
void add(int u,int v,int w){
	to[++tot]=v;
	val[tot]=w;
	nex[tot]=head[u];
	head[u]=tot;
}
ll dijstra(int s,int t){
	priority_queue<pa<ll,ll> >q;
	for(re int i=1;i<=m+n;i++)dis[i]=INF;
	dis[s]=0;
	q.push({0,s});
	while(q.size()){
		auto now=q.top();q.pop();
		ll u=now.second;
		for(re int i=head[u];i;i=nex[i]){
			ll v=to[i],w=val[i];
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
	return dis[t];
}
map<ll,ll>mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(re int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(re int i=1;i<=n;i++){
		ll k;
		cin>>k;
		while(k--){
			ll u,w;
			cin>>u>>w;
			add(u,i+m,w);
			add(i+m,u,w);
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		ll di=dijstra(u,v);
		cout<<a[u]+a[v]+di<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
