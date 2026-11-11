#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l,r,lt[20005][505],f[505][505],c,n,m,d,q,w[1005],a[1005],t[1005],dis[1005][1005],vis[1005],rt;
struct node{
	ll to;
	ll v;
	bool operator<(const node &s)const{
		return s.v<v;
	}
};
queue<node>qq;
priority_queue<node>pq;
vector<node>G[1005];
vector<ll>vec[1005];
ll bfs(ll now,ll zd){
	while(qq.size())qq.pop();
	ll da=0;
	memset(vis,0,sizeof vis);
	for(int i=1; i<=n; i++){
		if(lt[now][i]==1)qq.push({i,1});
	}while(qq.size()){
		ll nw=qq.front().to;
		ll bs=qq.front().v;
		if(lt[zd][nw]){
			da=bs;
			break;
		}qq.pop();
		if(vis[nw])continue;
		vis[nw]=1;
		for(auto u:vec[nw])qq.push({u,bs+1});
	}return da;
}int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1; i<=m; i++)cin>>w[i];
	if(c<=11){
		for(ll i=1,jg; i<=n; i++){
			cin>>jg;
			for(ll j=1; j<=jg; j++)cin>>a[j]>>t[j];
			for(ll j=1; j<=jg; j++){
				for(ll k=j+1; k<=jg; k++){
					G[a[j]].push_back({a[k],t[j]+t[k]});
					G[a[k]].push_back({a[j],t[j]+t[k]});
				}
			}
		}for(ll i=1; i<=m; i++){
			memset(vis,0,sizeof vis);
			pq.push({i,0});
			dis[i][i]=0;
			while(pq.size()){
				ll now=pq.top().to;
				ll bs=pq.top().v;
				pq.pop();
				if(vis[now])continue;
				vis[now]=1;
				for(auto u:G[now]){
					if(bs+u.v<dis[i][u.to]){
						dis[i][u.to]=bs+u.v;
						pq.push({u.to,dis[i][u.to]});
					}
				}
			}
		}for(ll i=1,x,y; i<=q; i++){
			cin>>x>>y;
			cout<<w[x]+w[y]+dis[x][y]<<'\n';
		}return 0;	
	}if(12<=c&&c<=15){
		for(ll i=1,jg; i<=n; i++){
			cin>>jg;
			for(ll j=1,p,t; j<=jg; j++){
				cin>>p>>t;
				rt=t;
				lt[p][i]=1;
				for(ll k=1; k<=n; k++){
					if(lt[p][k]==1)f[i][k]=f[k][i]=1;
				}
			}
		}for(ll i=1; i<=n; i++){
			for(ll j=i+1; j<=n; j++){
				if(f[i][j]){
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}for(int i=1,x,y; i<=q; i++){
			cin>>x>>y;
			cout<<w[x]+w[y]+bfs(x,y)*2*rt<<'\n';
		}return 0;	
	}
}