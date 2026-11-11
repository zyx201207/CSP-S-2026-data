#include<bits/stdc++.h>
#define ll long long
#define pii pair<long long,int>
using namespace std;
inline ll read(){
	ll x=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
} 
int c,n,m,d,q;
int k[505],w[500005];
int fs[550005],to[1000005],nx[1000005],tot;
ll dis[550005],Tm[1000005];
bool f[550005];
inline ll dijkstra(int x,int y){
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.push(make_pair(0,x));
	memset(f,0,sizeof(f));
	while(!pq.empty()){
		int u=pq.top().second;ll ow=pq.top().first;pq.pop();
		if(dis[u]<ow&&f[u]) continue;
		if(u==y) return ow;
		dis[u]=ow;
		f[u]=1;
		for(int i=fs[u];i;i=nx[i]){
			int v=to[i];ll w=Tm[i];
			if(dis[v]<=dis[u]+w&&f[v]||u==v) continue;
			dis[v]=dis[u]+w;
			f[v]=1;
			pq.push(make_pair(dis[v],v));
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int a=read(),t=read();
			tot++,to[tot]=a,nx[tot]=fs[i+m],Tm[tot]=t,fs[i+m]=tot;
			tot++,to[tot]=i+m,nx[tot]=fs[a],Tm[tot]=t,fs[a]=tot;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=w[x]+w[y]+dijkstra(x,y);
		cout<<ans<<'\n';
	}
	return 0;
}
