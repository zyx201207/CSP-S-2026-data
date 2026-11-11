#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e4+10;
ll w[505],k[N];
ll c,n,m,d,q;
ll a[505][N],t[505][N];
struct node{
	ll to,dis,id;
	bool operator<(const node &b)const{
		return b.dis<dis;
	}
};
vector<node> e[505][505];
vector<ll> vec[505];
ll dis[505][505];
bool mark[505];
void dij(ll st,ll id){
	memset(mark,0,sizeof(mark));
	priority_queue<node> q;
	q.push((node){st,0,id});
	dis[id][id]=0;
	while(!q.empty()){
		node now=q.top();q.pop();
		ll x=now.to;
		if(mark[x])continue;
		mark[x]=1;
		for(ll j=0;j<vec[x].size();j++){
			ll k=vec[x][j];
			for(ll i=0;i<e[x][k].size();i++){
				ll v=e[x][k][i].to;
				if(now.id==k){
					q.push((node){v,dis[id][k],k});
				}else{
//					cout<<k<<" "<<now.id<<"\n";
//					cout<<dis[id][k]<<"\n";
					if(dis[id][k]>dis[id][now.id]+t[k][v]+t[now.id][v]){
						dis[id][k]=dis[id][now.id]+t[k][v]+t[now.id][v];
//						cout<<dis[id][k]<<" "<<t[k][v]+t[now.id][v]<<"\n";
						q.push((node){v,dis[id][k],k});
					}
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][a[i][j]];
			vec[a[i][j]].push_back(i);
		}
		for(ll j=2;j<=k[i];j++){
			e[a[i][j]][vec[a[i][j]].size()].push_back((node){a[i-1][j],0,-1});
			e[a[i-1][j]][vec[a[i-1][j]].size()].push_back((node){a[i][j],0,-1});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=n;i++){
		dij(a[i][1],i);
//		for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//		cout<<"\n";
	}
	while(q--){
		ll x,r;cin>>x>>r;
		ll ans=1e18;
		for(int i=0;i<vec[x].size();i++){
			for(int j=0;j<vec[r].size();j++){
				ans=min(ans,dis[vec[x][i]][vec[r][j]]+t[vec[x][i]][x]+t[vec[r][j]][r]);
			}
		}
		cout<<ans+w[r]+w[x]<<"\n";
	}
	return 0;
}