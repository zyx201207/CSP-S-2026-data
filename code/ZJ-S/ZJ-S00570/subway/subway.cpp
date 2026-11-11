#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=1e3+10;
ll c,n,m,d,q;
ll a[N];
vector<ll>g[N],e[N],C[N],col[N];
ll vis[N];
vector< pair<ll,ll> >b[N];
ll lsh[N],tot,cnt;
ll w[N],id[N];
ll x[N],y[N];
ll dis[N][N];
ll ans[N][N],res[N][N];
struct node{
	ll id,d;
	bool operator<(const node &_)const{
		return d>_.d;
	}
};
priority_queue<node>qu;
void dij(ll st){
	qu.push({st,w[st]});
	dis[st][st]=w[st];
	while(!qu.empty()){
		node now=qu.top();
		qu.pop();
		ll u=now.id;
		if(dis[st][u]!=now.d)continue;
		for(auto v:g[u]){
			if(dis[st][v]>dis[st][u]+w[v]){
				dis[st][v]=dis[st][u]+w[v];
				qu.push({v,dis[st][v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof dis);
	memset(ans,0x3f,sizeof ans);
	for(ll i=1;i<=m;i++){
		cin>>a[i];
	}
	for(ll i=1,k;i<=n;i++){
		cin>>k;
		for(ll j=1,x,v;j<=k;j++){
			cin>>x>>v;
			b[i].push_back({x,v}); 
			lsh[++tot]=x;
		}
	}
	sort(lsh+1,lsh+1+tot);
	tot=unique(lsh+1,lsh+1+tot)-(lsh+1);
	for(ll i=1;i<=n;i++){
		for(auto j:b[i]){
			j.first=lower_bound(lsh+1,lsh+1+tot,j.first)-lsh;
			cnt++;
			w[cnt]=j.second;
			id[cnt]=j.first;
			C[i].push_back(cnt);
			col[id[cnt]].push_back(cnt);
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<C[i].size();j++){
			for(ll k=j+1;k<C[i].size();k++){
				g[C[i][j]].push_back(C[i][k]);
				g[C[i][k]].push_back(C[i][j]);
			}
		} 
	}	
	for(ll i=1;i<=tot;i++){
		for(ll j=0;j<col[i].size();j++){
			for(ll k=j+1;k<col[i].size();k++){
				g[col[i][j]].push_back(col[i][k]);
				g[col[i][k]].push_back(col[i][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ll xx,yy;
		xx=lower_bound(lsh+1,lsh+1+tot,x[i])-lsh;
		yy=lower_bound(lsh+1,lsh+1+tot,y[i])-lsh;
		res[xx][yy]=a[x[i]]+a[y[i]];
		x[i]=xx,y[i]=yy;
		vis[x[i]]=1;
	}
	for(ll i=1;i<=cnt;i++){
		if(vis[id[i]]){
//			cout<<"??"<<i<<endl;
			dij(i);
		}
	}
	for(ll i=1;i<=cnt;i++){
		for(ll j=1;j<=cnt;j++){
			ans[id[i]][id[j]]=min(ans[id[i]][id[j]],dis[i][j]);
		}
	}
	for(ll i=1;i<=q;i++){
//		cout<<res[x[i]][y[i]]<<"\n";
		cout<<ans[x[i]][y[i]]+res[x[i]][y[i]]<<"\n";
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
