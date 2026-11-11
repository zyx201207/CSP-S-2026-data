#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,V[500010];
struct F{
	ll v,w;
};
inline ll read(){
	char c;
	ll ret=0;
	while(1){
		c=getchar();
		if(c<'0'||c>'9')	return ret;
		else	ret*=10ll,ret+=(c-'0');
	}
}
vector<F> g[500010];
ll f[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(); n=read(); m=read(); d=read(); q=read();
	for(ll i=1;i<=m;++i)	V[i]=read();
	for(ll i=1,xx;i<=n;++i){
		xx=read();
		for(ll j=1,v,w;j<=xx;++j){
			v=read(); w=read();
			g[v].push_back((F){i,w});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(ll i=1;i<=n;++i)
		f[i][i]=0;
	for(ll i=1,x,xx,y,yy;i<=m;++i)
		for(ll j=0;j<g[i].size();++j)
			for(ll k=0;k<j;++k){
				x=g[i][j].v; xx=g[i][j].w;
				y=g[i][k].v; yy=g[i][k].w;
				if(f[x][y]>xx+yy)
					f[x][y]=f[y][x]=xx+yy;
			}
	for(ll k=1;k<=n;++k)
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(ll i=1,u,v;i<=q;++i){
		u=read(); v=read();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(ll j=0;j<g[u].size();++j)
			for(ll k=0;k<g[v].size();++k)
				ans=min(ans,f[g[u][j].v][g[v][k].v]+g[u][j].w+g[v][k].w);
		printf("%lld\n",V[u]+V[v]+ans);
	}
	return 0;
}
