#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
const ll N=5e5+5,INF=0x3f3f3f3f3f3f3f3f;
using namespace std;
ll n,m,d,Q,a[N],t[N],k,c[N],dis[N];
bool f[N];
ll h[N],to[N<<1],nxt[N<<1],w[N<<1],idx;
struct jd{
	ll x,y,sum;
}b[N];
void add(ll u,ll v,ll ww){
	nxt[++idx]=h[u],h[u]=idx,to[idx]=v,w[idx]=ww;
}
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void dj(int s){
	for(int i=1;i<=n;i++) dis[i]=INF,f[i]=0;
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().se;
		q.pop();
		if(f[u]) continue;
		for(int i=h[u];i;i=nxt[i]){
			int v=to[i];
			if(f[v]) continue;
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
int main(){
 	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>m>>m>>n>>d>>Q;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[j]>>t[j];
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				add(a[u],a[v],t[u]+t[v]);
				add(a[v],a[u],t[u]+t[v]);
			}
		}
	}
	while(Q--){
		ll x,y;
		cin>>x>>y;
  		dj(x);
		cout<<dis[y]+c[x]+c[y]<<"\n";
	}


	return 0;
}
//Oct31==Dec25?
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
