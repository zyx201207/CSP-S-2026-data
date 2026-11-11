#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
ll c,n,m,d,q,dis[500005],vis[500005],w[500005];
vector<ll>G[500005];
vector<pair<ll,ll> >G1[500005];
struct node{
	ll id,ti;
}a[500005];
bool cmp1(node x,node y){
	return x.id<y.id;
}
struct xlx{
	ll s,t,sum,bh;
}ans[1000005];
bool cmp2(xlx x,xlx y){
	return x.s<y.s;
}
bool cmp3(xlx x,xlx y){
	return x.bh<y.bh;
}
void dj(ll x){
	memset(dis,0x7f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[x]=0;
	priority_queue<pll,vector<pll>,greater<pll> >pq;
	pq.push({0,x});
	while(pq.size()){
		ll u=pq.top().second;
		pq.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(ll i=0;i<G[u].size();i++){
			ll lin=G[u][i],di=0;
			for(ll j=0;j<G1[lin].size();j++){
				if(G1[lin][j].first==u){
					di=j;
					break;
				}
			}
			for(ll j=0;j<G1[lin].size();j++){
				ll v=G1[lin][j].first,cost=G1[lin][j].second+G1[lin][di].second;
				if(dis[v]>dis[u]+cost){
					dis[v]=dis[u]+cost;
					pq.push({dis[v],v});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=k;j++){
			cin>>a[j].id>>a[j].ti;
			G[a[j].id].push_back(i);
		}
		sort(a+1,a+1+k,cmp1);
		for(ll j=1;j<=k;j++)G1[i].push_back({a[j].id,a[j].ti});
	}
	for(ll i=1;i<=q;i++){
		cin>>ans[i].s>>ans[i].t;
		if(ans[i].s>ans[i].t)swap(ans[i].s,ans[i].t);
		ans[i].bh=i;
	}
	sort(ans+1,ans+1+q,cmp2);
	ll i=1;
	while(i<=q){
		ll u=ans[i].s;
		dj(u);
		while(ans[i].s==u){
			ans[i].sum=dis[ans[i].t]+w[ans[i].s]+w[ans[i].t];
			i++;
		}
	}
	sort(ans+1,ans+1+q,cmp3);
	for(ll i=1;i<=q;i++)cout<<ans[i].sum<<'\n';
	return 0;
}
