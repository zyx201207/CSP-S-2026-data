#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q;
ll k[510];
vector<ll> w;
vector<ll> G[510];
struct node{
	ll a,t;
};
vector<node> b[510];
bool cmp(node x,node y){
	return x.a<y.a;
}
ll dis[510],vis[510];
queue<ll> qq;
void Dijkstra(ll s){
	memset(dis,0,sizeof dis);
	memset(vis,0,sizeof vis);
	qq.push(s);
	dis[s]=0;
	while(qq.size()){
		ll u=qq.front();
		qq.pop();
		for(auto it:G[u]){
			if(vis[it]) continue;
			if(dis[u]+1<dis[it]){
				dis[it]=dis[u]+1;
				vis[it]=1;
				qq.push(it);
			}
		}
	}
	return ;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		ll o;
		cin>>o;
		w.push_back(o);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll qq,ww;
			cin>>qq>>ww;
			b[i].push_back({qq,ww});
		}
	}
	for(int i=1;i<=n;i++) sort(b[i].begin(),b[i].end(),cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			ll l=0,r=0;
			while(l<b[i].size()&&r<b[j].size()){
				if(b[i][l].a==b[j][r].a){
					G[i].push_back(j);
					G[j].push_back(i);
					break;
				}
				if(b[i][l].a<b[j][r].a){
					l++;
				}
				if(b[i][l].a>b[j][r].a){
					r++;
				}
			}
		}
	}
	while(q--){
		ll st,ed;
		cin>>st>>ed;
		Dijkstra(st);
		cout<<dis[ed]*2*b[1][1].t+2*b[1][1].t+w[st]+w[ed]<<"\n";
	}
	return 0;
}
