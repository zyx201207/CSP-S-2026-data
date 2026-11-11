#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,W=1e9+1,WDF=1e5+10;
ll C,n,m,D,q;
ll w[N];
struct Node{
	ll next,to,weight;
}e[N<<1];
ll head[N],cnt;
vector<ll> a[N];
bool ff[N][302];
ll ro[302][N];
void addedge(ll u,ll v,ll ww){
	e[cnt]=(Node){head[u],v,ww};
	head[u]=cnt++;
}
ll dis[302][302];
bool f[N];
ll ans[WDF];
void dijkstRa(ll s){
	dis[s][s]=0;
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	pq.push(make_pair(0,s));
	while(!pq.empty()){
		ll u=pq.top().second;
		pq.pop();
		if(f[u]) continue;
		f[u]=1;
		for(ll i=head[u];i!=-1;i=e[i].next ){
			ll v=e[i].to ,ww=e[i].weight ;
			if(dis[s][v]>dis[s][u]+ww){
				dis[s][v]=dis[s][u]+ww;
				if(!f[v]) pq.push(make_pair(dis[s][v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>C>>n>>m>>D>>q;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			dis[i][j]=5e5+41;
		}
	}
	memset(head,-1,sizeof(head));
	for(ll i=1;i<=m;i++)
		cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;
			cin>>x>>y;
			ro[i][x]=y;//i路线x站台，y 
			a[x].push_back(i);
		}
	}
	for(ll i=1;i<=m;i++){//站台
		for(ll j=0;j<a[i].size()-1;i++){//subway 
			for(ll z=j+1;z<a[i].size();z++){
				ll ww=ro[a[i][j]][i]+ro[a[i][z]][i];
				addedge(a[i][j],a[i][z],ww);
				addedge(a[i][z],a[i][j],ww);
			}
		}
	}
	for(ll i=1;i<=n;i++) dijkstRa(i);
	for(ll i=1;i<=q;i++){
		ll uu,vu;
		cin>>uu>>vu;
		if(uu>vu) swap(uu,vu);
		ll re=5e5+10;
		for(ll j=0;j<a[uu].size();j++){
			for(ll z=0;z<a[vu].size();z++){
				ll o1=a[uu][j],o2=a[vu][z];
				re=min(re,dis[o1][o2]+ro[o1][uu]+ro[o2][vu]);
			}
		}
		re+=w[uu]+w[vu];
		cout<<re<<endl;
	}
	return 0;
}

