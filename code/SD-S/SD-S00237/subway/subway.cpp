#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll read(){
	ll f=1,x=0,c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const ll M=5e5+7;
ll c,n,m,d,q;
ll w[M];
vector<ll>bl[M];
vector<ll>a[507];
vector<ll>t[507];
vector<pair<ll,ll>>fal[507];
//dij
ll dis[507][507];
ll f[507];
priority_queue<pair<int,int>>qu;
void dij(ll s){
	memset(dis[s],0x3f,sizeof dis[s]);
	memset(f,0,sizeof f);
	while(qu.size())qu.pop();
	dis[s][s]=0;
	qu.push({0,s});
	while(qu.size()){
		ll u=qu.top().second;
//		cout<<s<<endl<<u<<endl;
		qu.pop();
		if(f[u])continue;
		f[u]=1;
		for(pair<ll,ll>p:fal[u]){
			ll v=p.first,w=p.second;
//			cout<<dis[s][u]<<" "<<w<<" "<<dis[s][v]<<endl;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				if(!f[v])qu.push({-dis[s][v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(ll i=1;i<=m;i++)w[i]=read();
	for(ll i=1;i<=n;i++){
		ll k=read();
		t[i].resize(m+7);
		for(ll j=1,x,y;j<=k;j++){
			x=read(),y=read();
			a[i].push_back(x);
			t[i][x]=y;
			bl[x].push_back(i);
		} 
	}
	for(ll i=0;i<m;i++){
//		cout<<i<<endl;
		if(bl[i].size()>=2){
			ll len=bl[i].size();
//			cout<<len<<endl;
			for(ll j=0;j<len;j++){
				for(ll k=j+1;k<len;k++){
					ll u=bl[i][j],v=bl[i][k],w=t[u][i]+t[v][i];
//					cout<<u<<' '<<v<<' '<<w<<endl;
					fal[u].push_back({v,w});
					fal[v].push_back({u,w});
				}
			}
		}
	}
	for(ll i=1;i<=n;i++)dij(i);
	for(ll i=1,u,v;i<=q;i++){
		u=read(),v=read();
		ll mdis=1e18;
		for(ll j:bl[u]){
			for(ll k:bl[v]){
//				cout<<j<<' '<<k<<endl;
				mdis=min(mdis,t[j][u]+dis[j][k]+t[k][v]);
			}
		}
		printf("%lld\n",mdis+w[u]+w[v]);
	}
	return 0;
}
 
