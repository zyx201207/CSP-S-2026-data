#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
typedef long long ll;
const int N = 5e5+9;
ll c,n,m,d,q,cnt;
ll w[N];ll k[N],a[N],t[N],x[N],y[N];
ll b[3*N],h[3*N],nxt[3*N],z[3*N];
ll ans[N];
ll dis[N];
void add(ll u,ll v,ll k){
	b[++cnt]=v;z[cnt]=k;nxt[cnt]=h[u];h[u]=cnt;
}
priority_queue<pair<ll,ll> > Q;
void djs(ll p){
	Q.push({0,p});
	while(!Q.empty()){
		pair<ll,ll> ls = Q.top();Q.pop();
		ls.first = ls.first*(-1);
		if(ls.first>=dis[ls.second])continue;
		dis[ls.second] = ls.first;
		for(int i = h[ls.second];i!=0;i=nxt[i]){
			Q.push({-1*(ls.first+z[i]),b[i]});
		}
	}
}
//最小生成树，写完才想到，我服了 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m){
		cin>>w[i];
	}
	rep(i,1,n){
		cin>>k[i];
		rep(j,1,k[i]){
			cin>>a[j]>>t[j];
			add(m+i,a[j],t[j]);
			add(a[j],m+i,t[j]);
		}
	}
	rep(i,1,q){
		cin>>x[i]>>y[i];
	}
	
	ll len = n+m+1;
	fill(ans+1,ans+1+q,1e17); 
	rep(i,1,n){
		fill(dis+1,dis+1+len,1e17);
		djs(m+i);
		rep(j,1,q){
			ans[j] = min(dis[x[j]]+dis[y[j]],ans[j]);
		}
	}
	rep(i,1,q){
		if(x[i]==y[i])cout<<0<<"\n";
		else cout<<ans[i]+w[x[i]]+w[y[i]]<<"\n";
	}
	return 0;
}

