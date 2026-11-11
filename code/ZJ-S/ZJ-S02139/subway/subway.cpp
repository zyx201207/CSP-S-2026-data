#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <iostream>

using namespace std;
typedef long long ll;

inline ll readl(){
	ll x=0,y=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') y=-y;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}
	return x*y;
}

void writel(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x+'0');
	else writel(x/10),putchar(x%10+'0');
}
const ll N=510,M=5e5+10,D=22,Q=1e5+10;
const ll MAXN=1e17+10;
// Lines: n<=N
// Platform: m<=M
// Line i has k[i] platforms: plt[i] (length = k[i])
ll n,m,d,q,cases,ww[M],k[N];
vector<pair<ll,ll> > lines[M];
ll dist[N][N];

inline void mk_edge(ll u,ll v,ll w){
	dist[u][v]=(dist[u][v]>w?w:dist[u][v]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cases=readl();
	n=readl(),m=readl(),d=readl(),q=readl();
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i!=j)
				dist[i][j]=MAXN;
	for(ll i=1;i<=m;i++) ww[i]=readl();
	for(ll i=1;i<=n;i++){
		k[i]=readl();
		for(ll j=1;j<=k[i];j++){
			ll t=readl();ll v=readl();
			lines[t].push_back(make_pair(i,v));
		}
	}
//	for(ll i=1;i<=m;i++){
//		cerr<<"Plt "<<i<<'\n';
//		for(auto j:lines[i])
//			cerr<<"Line "<<j.first<<"  Wei="<<j.second<<';';
//		cerr<<'\n';
//	}

	for(ll i=1;i<=m;i++){
		for(pair<ll,ll> Line1:lines[i])
			for(pair<ll,ll> Line2:lines[i]){
				// Bruteforce to build Graph. O(m * d^2)
				ll u=Line1.first,v=Line2.first,w=Line1.second+Line2.second;
				if(u!=v)
					mk_edge(u,v,w),
					mk_edge(v,u,w);
			}
	}
//	for(ll i=1;i<=n;i++)
//		for(ll j=1;j<=n;j++)
//			cerr<<"Edge "<<i<<','<<j<<':'<<dist[i][j]<<'\n';
//	cerr<<"Then Floyd.\n";
	//Using Floyd to work out the dist. O(n^3)
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			for(ll k=1;k<=n;k++){
				mk_edge(i,j,dist[i][k]+dist[k][j]);
			}
//	for(ll i=1;i<=n;i++)
//		for(ll j=1;j<=n;j++)
//			cerr<<"Edge "<<i<<','<<j<<':'<<dist[i][j]<<'\n';	
	for(ll tp=1;tp<=q;tp++){
		ll x=readl(),y=readl();
		//O(q * d^2)
		//work out the ans. min{dist(i,j)+t[x][i]+t[y][j]+w1+w2} where i in x,j in y
		ll res=MAXN;
		for(pair<ll,ll> Line1:lines[x])
			for(pair<ll,ll> Line2:lines[y]){
				ll i=Line1.first,j=Line2.first,w=Line1.second+Line2.second;
				ll pp=dist[i][j]+w+ww[x]+ww[y];
				res=(pp<res?pp:res);
			}
		writel(res);
		putchar('\n');
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
